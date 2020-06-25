#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO(" I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "gest_com");

  ros::NodeHandle n;

  ros::Publisher pub_comuni = n.advertise<std_msgs::String>("/super_comuni_out", 1000);

  ros::Publisher pub_rumo = n.advertise<std_msgs::String>("/super_rumo", 1000);

  ros::Publisher pub_position = n.advertise<std_msgs::String>("/super_position", 1000);

  ros::Subscriber sub = n.subscribe("/gest_out", 1000, chatterCallback);

  ros::spin();

  return 0;
}