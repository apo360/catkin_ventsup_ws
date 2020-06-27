// --------------- %Begin Include Headers% ----------------------//
#include "ros/ros.h" // 
#include "std_msgs/String.h"
#include "std_msgs/Char.h"
#include "std_msgs/Int32.h"
// %EndTag(MSG_HEADER)%

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
    std::stringstream msg_gps_lat, msg_gps_utc, msg_gps_sog_cog, msg_gps_sat;
    ros::Publisher latitude, sog_cog, satelites, utc;
    ros::Subscriber GetGpsDate;

  public:
    ReadGps(ros::NodeHandle *nh){

      utc = nh->advertise<std_msgs::String>("/gps_utc",1);

      latitude = nh->advertise<std_msgs::String>("/gps_position",1);

      sog_cog = nh->advertise<std_msgs::String>("/gps_cog_sog",1); // leitura do rumo, leitura da velocidade em nós.

      satelites = nh->advertise<std_msgs::String>("/gps_satelites", 1); // leitura de números de satelites. 

      GetGpsDate = nh->subscribe("/rs232_out", 1, &ReadGps::GpsCallback, this);
    }

    void GpsCallback(const std_msgs::String::ConstPtr& Gpsdate){

      std::string gpss;
      std::stringstream gps_stream(Gpsdate->data.c_str());

      while (getline(gps_stream, gpss, '\n'))
      {
        if(gpss.substr(0,5) == "GPGGA")
        {
          std::vector<std::string> str_split = ReadGps::split(gpss.substr(6), ',');
          for (unsigned int iter_split = 0; iter_split < str_split.size(); iter_split++)
          {
            str_split[iter_split];
          }
          
          msg_gps_utc << *str_split.begin() << std::endl;
          msg_gps_lat << *(str_split.begin() + 1) << ',' << *(str_split.begin() + 2) << std::endl;
          msg_gps_sog_cog << *(str_split.begin() + 3) <<',' << *(str_split.begin() + 4) << std::endl;
          msg_gps_sat << (*(str_split.begin() + 6)) << std::endl; 

          G_utc.data = msg_gps_utc.str();
          G_latitude.data = msg_gps_lat.str();
          G_sog_cog.data = msg_gps_sog_cog.str();
          G_satelite.data = msg_gps_sat.str(); 

          utc.publish(G_utc);
          latitude.publish(G_latitude);
          sog_cog.publish(G_sog_cog);
          satelites.publish(G_satelite); 
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
};

int main(int argc, char **argv){
  ros::init(argc, argv, "gps_node"); // name of node;
  ros::NodeHandle nh;
  ReadGps gp = ReadGps(&nh);
  ros::spin();
return 0;
}