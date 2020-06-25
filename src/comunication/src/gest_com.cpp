#include "ros/ros.h"
#include "std_msgs/String.h"

class GestComu{
  private:
    ros::Publisher receber, enviar;
    ros::Subscriber sub_lora, sub_wifi, super_comuni_out;

  public:

    GestComu(ros::NodeHandle *nh){
      receber = nh->advertise<std_msgs::String>("/gest_send", 1000);
      enviar = nh->advertise<std_msgs::String>("/gest_out", 1000);
      sub_lora = nh->subscribe("/lora_out", 1000, &GestComu::LoraCallback, this);
      sub_wifi = nh->subscribe("/wifi_send", 1000, &GestComu::WifiCallback, this);
      super_comuni_out = nh->subscribe("/super_comuni_out", 1000, &GestComu::SuperCallback, this);
    }

    void LoraCallback(const std_msgs::String::ConstPtr& msg)
    {
      ROS_INFO(" I heard: [%s]", msg->data.c_str());
    }

    void WifiCallback(const std_msgs::String::ConstPtr& msg)
    {
      ROS_INFO(" I heard: [%s]", msg->data.c_str());
    }

    void SuperCallback(const std_msgs::String::ConstPtr& msg)
    {
      ROS_INFO(" I heard: [%s]", msg->data.c_str());
    }

};

int main(int argc, char **argv)
{

  ros::init(argc, argv, "gest_com");

  ros::NodeHandle nh;

  GestComu gc = GestComu(&nh);

  ros::spin();

  return 0;
}