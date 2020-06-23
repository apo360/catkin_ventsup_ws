#include "ros/master.h"
#include "ros/ros.h"
#include "ros/xmlrpc_manager.h"
#include "ros/network.h"
#include <vector>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    
    ros::init(argc, argv, "master");

    ros::master::V_TopicInfo master_topics;

    ros::master::getTopics(master_topics);

    for (ros::master::V_TopicInfo::iterator it = master_topics.begin(); it != master_topics.end(); it++) {
        const ros::master::TopicInfo& info = *it;
        std::cout << info.name << " " << info.datatype << std::endl;
    }
    
    return 0;
}