#include "ros/ros.h"
#include "std_msgs/String.h"
#include "supervisor/imgData.h"
#include "supervisor/imgDataArray.h"

void GPSCall(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("GPS: [%s]", msg->data.c_str());
}

void PlanoCall(const std_msgs::String::ConstPtr& plan)
{
  ROS_INFO("Plano: [%s]", plan->data.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "supervisor_node");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/topic_position_vehicle", 10, GPSCall);

  ros::Subscriber sub_plano = n.subscribe("/planning_info", 10, PlanoCall);

  ros::Publisher plano_enviar = n.advertise<std_msgs::String>("/super_plano", 10);

  std_msgs::String planos;

  plano_enviar.publish(planos);

/* 
  ros::Publisher pub_comuni = n.advertise<std_msgs::String>("/super_comuni_out", 1000);

  ros::Publisher pub_rumo = n.advertise<std_msgs::String>("/super_rumo", 1000);

  ros::Publisher pub_plano = n.advertise<std_msgs::Vector>("/super_planning", 1000);

  ros::Subscriber sub = n.subscribe("/gest_out", 1000, chatterCallback);
*/
  ros::spin();

  return 0;
}