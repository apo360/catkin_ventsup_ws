#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "serial/Strings.h"

class ReadImu{
  private:
    Strings::StringSplit caractrs;
    std_msgs::String vect_orientation, vect_gravity, vect_gyroscope, vect_linearaccel, vect_magnetometer;
    ros::Publisher imu_orient, imu_grav, imu_gyro, imu_linear, imu_magnet;
    ros::Subscriber GetImu;

  public:
    ReadImu(ros::NodeHandle *nh){
      imu_orient = nh->advertise<std_msgs::String>("/imu_orientation", 10);
      imu_grav = nh->advertise<std_msgs::String>("/imu_gravity", 10);
      imu_gyro = nh->advertise<std_msgs::String>("/imu_gyroscope", 10);
      imu_linear = nh->advertise<std_msgs::String>("/imu_linearaccel", 10);
      imu_magnet = nh->advertise<std_msgs::String>("/imu_magnetometer", 10);

      GetImu = nh->subscribe("/rs232_out", 10, &ReadImu::ImuCallback, this);
    }

    void ImuCallback(const std_msgs::String::ConstPtr& Imudate){

      std::string imus;

      std::stringstream imu_stream(Imudate->data.c_str());

      while (getline(imu_stream, imus, '\n'))
      {
        if(imus.substr(0,5) == "HCHDT"){

          std::vector<std::string> imu_split = caractrs.split(imus.substr(6), ',');
          for (unsigned int i = 0; i < imu_split.size(); i++)
          {
            imu_split[i];
          }
          vect_orientation.data = *imu_split.begin() + '\n'; //VECTOR_EULER -- Vector de Orientação
          //vect_gravity.data = *(imu_split.begin()+1) + '\n'; // VECTOR_GRAVITY
          //vect_gyroscope.data = *(imu_split.begin()+2) + '\n'; // VECTOR_GYROSCOPE
          //vect_linearaccel.data = *(imu_split.begin()+3) + '\n'; // VECTOR_LINEARACCEL
          vect_magnetometer.data = *(imu_split.end()-1) + '\n'; // VECTOR_MAGNETOMETER --------

          // Passa a publicar os respectivos tópicos
          imu_orient.publish(vect_orientation);
          //imu_grav.publish(vect_gravity);
          //imu_gyro.publish(vect_gyroscope);
          //imu_linear.publish(vect_linearaccel);
          imu_magnet.publish(vect_magnetometer);
        }
      }
    }
};

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "imu_node");
  ros::NodeHandle nh;
  //ros::Rate loop_rate(2);
  ReadImu imu = ReadImu(&nh);
  ros::spin();
  //loop_rate.sleep();
  return 0;
}