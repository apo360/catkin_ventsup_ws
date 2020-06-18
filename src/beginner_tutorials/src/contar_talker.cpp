// Criar um acontagem para ROS Master em C++
// Base de C++ 
// Bibliotecas de C++
// #include <iostream> --> Para essa caso não serve, apenas só serveria, se tivessemos que imprimir na tela de C++ 
#include <sstream>
// Como irei de publicar com o ROS, logo tenho que inserir a sua Bibliotecas
#include "ros/ros.h"
// aqui vou apenas incluir a Biblioteca de saida da mensagem
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"

// Agora começo com o corpo do c++

int main(int argc, char **argv){

// e como estou a criar o programa para enviar para ROS, tbem tenho que inicializar o ROS, de forma avisar o ROS-Master,
// que temos um 'node' aqui.

// ros::init(int &argc, char %argv, node_name);

    ros::init(argc, argv, "contar_talker"); // recomendar, que o nome do 'Node' seja o mesmo que do ficheiro
    ros::NodeHandle n; // Criamos um identificador
    ros::Publisher pub_enviar = n.advertise<std_msgs::Int32>("contador_send",1000);
    ROS_INFO("Teste de contar");
    ros::Rate rate(1);
    int count = 0;

    while(ros::ok()){

        std_msgs::Int32 msg;

            pub_enviar.publish(msg);

        //msg.data = count;

        //count++;
        rate.sleep();
    }
return 0;
}