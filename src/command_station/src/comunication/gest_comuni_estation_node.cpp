#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char ** argv)
{
    ros::init(argc,argv, "gest_comuni_estation_node");

    ros::NodeHandle nh;

    ros::Publisher pubIP = nh.advertise<std_msgs::String>("/teste_comuni", 1000);

    ROS_INFO("usar o tópico '/teste_comuni' dando um IP para teste de comunicações \n");

    std_msgs::String IP;

    pubIP.publish(IP);

    ros::spinOnce();

    ros::spin();

    return 0;
}