#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include "ros/master.h"
#include "ros/xmlrpc_manager.h"

#define Port 5000
#define MaxClients 10
class socket_server
{
    private:
        char buff[4096];
        char char_topicos[4096];
        int server, ret, client;
        struct sockaddr_in server_addr, client_addr;

    public:
        int socket_server_setup(short porta, int MaxClient){
            // create a socket
            server = socket(AF_INET, SOCK_STREAM, 0);
            // Verify if the socket was created
            if (server < 0)
            {
                printf("[-]Error in connection with server.\n");
                exit(1);
            }
            printf("[+]Server Socket is Created.\n.\n");
            // Specify an address for the socket
            memset(&server_addr, '\0', sizeof(server_addr));
            server_addr.sin_family      = AF_INET;
            server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
            server_addr.sin_port        = htons(porta);

            // Verificar erro com connect
            ret = bind(server, (struct sockaddr*) &server_addr, sizeof(server_addr));
            if (ret < 0)
            {
                ROS_ERROR("[-]Error in binding.\n");
                exit(1);
            }
            printf("[+]Bind to port %d.\n", porta);
            if(listen(server, MaxClient) == 0){ printf("Listening....\n");}
            else {ROS_ERROR("[-]Error in binding.\n");}
            return server;
        }
        int socket_client_setup(int server_client){
            pid_t childpid;
            int csize  = sizeof(client_addr);
            client = accept(server_client, (sockaddr*)&client_addr, (socklen_t*)&csize);
            if (client < 0)
                exit(1);
            printf("connection accepted from %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            // listar os topicos estabelecidos
            ros::master::V_TopicInfo master_topics;
            ros::master::getTopics(master_topics);
            ros::master::V_TopicInfo::iterator it;
            for (it = master_topics.begin(); it != master_topics.end(); it++) {
                const ros::master::TopicInfo& info = *it;
                strcpy(char_topicos, info.name.c_str()+'\n');
                send(client, char_topicos, strlen(char_topicos), 0);
                bzero(char_topicos, sizeof(char_topicos));
            }
            if ((childpid = fork()) == 0){
                close(server_client);
                while (1)
                {
                    int recv_clinent = recv(client, buff, sizeof buff, 0);
                    if (strcmp(buff, ":exit") == 0)
                    {
                        ROS_ERROR("connection accepted form %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                        break;
                    }
                    else if (strcmp(buff, "topics") == 0)
                    {
                        ros::master::V_TopicInfo master_topics;

                        ros::master::getTopics(master_topics);

                        ros::master::V_TopicInfo::iterator it;

                        for (it = master_topics.begin(); it != master_topics.end(); it++) {
                            const ros::master::TopicInfo& info = *it;
                            if(info.name.substr(1,4) == "gest"){
                                std::cout << info.name << " " << info.datatype << std::endl;
                                strcpy(buff, info.name.c_str());
                                send(client, buff, strlen(buff), 0);
                                bzero(buff, sizeof(buff));
                            }    
                        }
                        break;
                    }
                    else
                    {
                        printf("client: %s\n", buff);
                        send(client, buff, strlen(buff), 0);
                        bzero(buff, sizeof(buff));
                    }
                }
            }
            return client;
        }
};

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "wifi_master_server");

    ros::NodeHandle nh;

    ros::Publisher pub_wifi = nh.advertise<std_msgs::String>("wifi_send", 1000);

    int client;
    
    socket_server teste;

    int server = teste.socket_server_setup(Port, MaxClients);
    
    while(1){
        client = teste.socket_client_setup(server);

        fflush(stdout);
    }
    close(client);
    return 0;
}