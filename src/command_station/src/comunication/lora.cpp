#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include <sstream>

int main(int argc, char ** argv){

    ros::init(argc, argv, "lora");

    ros::NodeHandle nh;

    ros::Publisher lora_talker = nh.advertise<std_msgs::String>("lora_talker", 1000);

    std_msgs::String lora_msgs;

    std::stringstream ss_lora_msgs;

    ss_lora_msgs << lora_msgs;

    lora_msgs.data = ss_lora_msgs.str();

    lora_talker.publish(lora_msgs);

    ros::spinOnce();

    ros::spin();

    return 0;
}