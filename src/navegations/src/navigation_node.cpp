#include <iostream>
#include <vector>
#include "ros/ros.h"
#include "std_msgs/String.h"

using std::string;
class navigation
{
private:
   ros::Publisher position_vehicle;
   ros::Subscriber Gps_lat, Gps_lng, Gps_vel, Imu_rumo;
public:
    ReadNavigation(ros::NodeHandle *nh)
    {
        position_vehicle = nh->advertise<std_msgs::String>("/topic_position_vehicle",1000);
        Gps_lat = nh->subscribe("/topic_gps_latitude", 1000)
        Gps_lng = nh->subscribe("/topic_gps_longitude")
    }
    typedef position_navigation(double lat, double lng); // Função de Navegação Gps
    typedef inertial_navigation(double lat, double lng); // Função de navegação Inercial (Imu) -> 
    typedef geonavigation_radar();
    string ReadGps(double lat, double lng);
    string ReadImu(int); 

};
