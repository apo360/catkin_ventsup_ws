/*
Este nó serve para recolher todos os dados de Gps
 e publicar em seus respectivos tópicos
  para serem usados mais a posterior.
*/

#include "ros/ros.h" // 
#include "std_msgs/String.h"
#include "std_msgs/Char.h"
#include "std_msgs/Int32.h"
#include "serial/Strings.h"
#include <iostream>
#include <cmath>

using std::string;
using std::exception;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::stringstream;
using std::to_string;



class ReadGps{
  private:
    std_msgs::String G_latitude, G_utc, G_sog_cog, G_satelite;
    ros::Publisher Position, sog_cog, satelites, utc;
    ros::Subscriber GetGpsDate;
    Strings::StringSplit caractrs;

  public:
    ReadGps(ros::NodeHandle *nh)
    {

      utc = nh->advertise<std_msgs::String>("/gps_utc",10);
      Position = nh->advertise<std_msgs::String>("/gps_position",10);
      sog_cog = nh->advertise<std_msgs::String>("/gps_sog_cog",10); // leitura do rumo, leitura da velocidade em nós.
      satelites = nh->advertise<std_msgs::String>("/gps_satelites", 10); // leitura de números de satelites. 
      GetGpsDate = nh->subscribe("/rs232_out", 10, &ReadGps::GpsCallback, this);
    }

    void GpsCallback(const std_msgs::String::ConstPtr& Gpsdate)
    {
      std::string gpss;
      std::stringstream gps_stream(Gpsdate->data.c_str());

      while (getline(gps_stream, gpss, '\n'))
      {
        if(gpss.substr(0,5) == "GPGGA")
        {
          std::vector<std::string> str_split = caractrs.split(gpss.substr(6), ',');
          for (unsigned int iter_split = 0; iter_split < str_split.size(); iter_split++)
          {
            str_split[iter_split];
          }

          G_utc.data = *str_split.begin() + '\n';
          G_latitude.data = *(str_split.begin() + 1) + ',' + *(str_split.begin() + 2) + '\n';
          G_sog_cog.data = *(str_split.begin() + 3) +',' + *(str_split.begin() + 4) + '\n';
          G_satelite.data = (*(str_split.begin() + 6)) + '\n';

          utc.publish(G_utc);
          sog_cog.publish(G_sog_cog);
          Position.publish(G_latitude);
          satelites.publish(G_satelite); 
        }
      }
    }
};

int main(int argc, char **argv){

  ros::init(argc, argv, "gps_node"); // name of node;

  ros::NodeHandle nh;

  ros::Rate loop_rate(0.1);

  ReadGps gp = ReadGps(&nh);

  ros::spin();

  loop_rate.sleep();

return 0;
}