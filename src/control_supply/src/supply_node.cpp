#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char ** argv){

    ros::init(argc, argv, "supply_node");

    ros::NodeHandle nh;

    ros::spin();

    return 0;
}