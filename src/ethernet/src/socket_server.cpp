/********************
 * Delevoped by Luiz Felipe
 * GitHub: https://github.com/Silva97
 *
 * Date: 02/17/2018
 ********************/
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <ros/ros.h>
#include <std_msgs/String.h>

using namespace std;

int main(int argc, char ** argv)
{
    // create a socket
    int server = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in saddr;
        saddr.sin_family      = AF_INET;
        saddr.sin_addr.s_addr = htonl(INADDR_ANY);
        saddr.sin_port        = htons(5000);

    // Verificar erro com connect

    bind(server, (struct sockaddr*) &saddr, sizeof(saddr));

    listen(server, 5);

    sockaddr_in caddr;

    int csize  = sizeof(struct sockaddr_in);

    while(1){
        int client;
        client = accept(server, (sockaddr*)&caddr, (socklen_t*)&csize);

        int recv_clinent;
        char buff[4096]; 
        recv_clinent = recv(client, buff, sizeof buff, 0);

        if (recv_clinent == -1)
		{
			cerr << "Error in recv(). Quitting" << endl;
			break;
		}

		if (recv_clinent == 0)
		{
			cout << "Client disconnected " << endl;
			break;
		}

        send(client, buff, sizeof(recv_clinent), 0);

        puts(buff);

        fflush(stdout);

        close(client);
    }
    
    return 0;
}