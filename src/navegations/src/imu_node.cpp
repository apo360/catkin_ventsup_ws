#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "serial/serial.h"

class ReadImu{
  private:
    std_msgs::String ssm;
    std::stringstream msg_imu;
    ros::Publisher rumo, proa, status;
    ros::Subscriber GetImu;

  public:
    ReadImu(ros::NodeHandle *nh){
      proa = nh->advertise<std_msgs::String>("/topic_proa", 1000);
      rumo = nh->advertise<std_msgs::String>("/topic_rumo", 1000);
      status = nh->advertise<std_msgs::String>("/topic_imu_status", 1000);
      GetImu = nh->subscribe("/rs232_out", 1000, &ReadImu::ImuCallback, this);
    }

    void ImuCallback(const std_msgs::String::ConstPtr& Imudate){

      std::string imus;

      std::stringstream imu_stream(Imudate->data.c_str());

      while (getline(imu_stream, imus, '\n'))
      {
        if(imus.substr(0,5) == "HCHDT"){

          std::vector<std::string> imu_split = ReadImu::split(imus.substr(6), ' ');
          for (unsigned int i = 0; i < imu_split.size(); i++)
          {
            imu_split[i];
          }
          std::cout << *imu_split.begin() << " " << ReadImu::cardinal(std::stod(*imu_split.begin())) << std::endl;
        }
      }
    }

    std::vector<std::string> split(std::string str, char delimiter)
    {
        std::vector<std::string> ret;
        if(str.empty()) 
        {
            ret.push_back(std::string(""));
            return ret;
        }

        unsigned i = 0;
        std::string strstack;
        while(!(str.empty()) && (str[0] == delimiter)) {str.erase(0,1);}
        reverse(str.begin(), str.end());
        while(!(str.empty()) && (str[0] == delimiter)) {str.erase(0,1);}
        reverse(str.begin(), str.end());
        while(!str.empty())
        {
            ret.push_back(str.substr(i, str.find(delimiter)));
            str.erase(0,str.find(delimiter));
            while(!(str.empty()) && (str[0] == delimiter)) {str.erase(0,1);}
        }
        return ret;
    }

    const char *cardinal(double course)
    {
      static const char* directions[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
      int direction = (int)((course + 11.25f) / 22.5f);
      return directions[direction % 16];
    }
};

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "imu_node");
  ros::NodeHandle nh;
  ReadImu imu = ReadImu(&nh);
  
    ros::spin();

  return 0;
}