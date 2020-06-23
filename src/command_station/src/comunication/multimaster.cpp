#include "ros/master.h"
#include "ros/ros.h"
#include "ros/xmlrpc_manager.h"
#include "ros/network.h"
#include <vector>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdlib.h>

void printsms(){
    ROS_ERROR("Use : [-d | {ROS_IP_Master, Port_IP (default 11311)}]");
}

void listHost(){
    system("arp -D");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printsms();
        return 0;
    }

    // Argument 1 is the IP_MASTER
    std::string ip(argv[1]);
    if (ip == "-d")
    {
        listHost();
        return 0;
    }
    // Argument 2 is the port
    std::string porta(argv[2]);
    
    ros::init(argc, argv, "multimaster");

    std::string ip_master = "http://" + ip + ":" + porta;

    setenv("ROS_MASTER_URI", ip_master.c_str(), 1);

    setenv("ROS_IP", "192.168.0.101", 1);

    std::string master_uri_env = getenv("ROS_MASTER_URI");

    ros::master::V_TopicInfo master_topics;

    ros::master::getTopics(master_topics);

    for (ros::master::V_TopicInfo::iterator it = master_topics.begin() ; it != master_topics.end(); it++) {
        const ros::master::TopicInfo& info = *it;
        std::cout << "topic_" << it - master_topics.begin() << ": " << info.name << std::endl;
    }

    return 0;
}