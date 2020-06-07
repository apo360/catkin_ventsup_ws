#include <string>
#include <iostream>
#include "serial/serial.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "jni.h"

using std::string;

int main(int argc, char ** argv){
    
    ros::init(argc, argv, "write_rs232"); // recomendar, que o nome do 'Node' seja o mesmo que do ficheiro

    ros::NodeHandle n; // Criamos um identificador

    ros::Publisher rs232_in = n.advertise<std_msgs::String>("/rs232_in", 1000);

    ROS_INFO("A escrever na porta RS232 ... ");

    ros::Rate loop_rate(25);
    
    while(ros::ok()){
        
        std_msgs::String ssm;

        std::stringstream sst;

        sst << "RPY/";

        ssm.data = sst.str();

        rs232_in.publish(ssm);

        ros::spinOnce();

        loop_rate.sleep();
    }
}