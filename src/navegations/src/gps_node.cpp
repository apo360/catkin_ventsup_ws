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
    std_msgs::String G_latitude, G_longitude, G_utc, G_sog_cog, G_satelite;
    std::stringstream msg_gps_lat, msg_gps_lng, msg_gps_utc, msg_gps_sog_cog, msg_gps_sat;
    ros::Publisher longitude, latitude, sog_cog, satelites, utc;
    ros::Subscriber GetGpsDate;

  public:
    ReadGps(ros::NodeHandle *nh){

      utc = nh->advertise<std_msgs::String>("/topic_gps_utc",1000);

      latitude = nh->advertise<std_msgs::String>("/topic_gps_latitude",1000);

      longitude = nh->advertise<std_msgs::String>("/topic_gps_longitude",1000);

      sog_cog = nh->advertise<std_msgs::String>("/topic_gps_cog_sog",1000); // leitura do rumo, leitura da velocidade em nós.

      satelites = nh->advertise<std_msgs::String>("/topic_satelites", 1000); // leitura de números de satelites. 

      GetGpsDate = nh->subscribe("/rs232_out", 1000, &ReadGps::GpsCallback, this);
    }

    const std::string convert_decimal_to_degree(std::vector<std::string> value, int num){

      std::vector<std::string> posicao(2);

      for (int i = 0; i < value.size(); i++)
      {
        std::string s;
        int find_space = value[i].find(" ");

        std::string value_string = value[i].substr(find_space++); // pega os valores após do espaço

        std::string value_number = value[i].substr(0,(--find_space)); // pega os valores antes do espaço

        int grau = std::floor(std::stof(value_number));

        double minuto = ((std::stod(value_number) - grau) * 60);
        
        float segundo = ((minuto - std::floor(minuto)) * 60);

        s = std::to_string(grau) + "º " + std::to_string( (int)std::floor(minuto)) + "' " + std::to_string((int)std::floor(segundo)) + '"' + value_string + ' ';

        posicao[i] = s;
      }
      return posicao[num];
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
          msg_gps_lat << ReadGps::convert_decimal_to_degree({*(str_split.begin() + 1),*(str_split.begin() + 2)}, 0) << std::endl;
          msg_gps_lng << ReadGps::convert_decimal_to_degree({*(str_split.begin() + 1),*(str_split.begin() + 2)}, 1) << std::endl;
          msg_gps_sog_cog << *(str_split.begin() + 3) <<',' << *(str_split.begin() + 4) << std::endl;
          msg_gps_sat << (*(str_split.begin() + 6)) << std::endl; 
          std::cout << *(str_split.begin() + 6) << std::endl;

          G_utc.data = msg_gps_utc.str();
          G_latitude.data = msg_gps_lat.str();
          G_longitude.data = msg_gps_lng.str();
          G_sog_cog.data = msg_gps_sog_cog.str();
          G_satelite.data = msg_gps_sat.str(); 

          utc.publish(G_utc);
          latitude.publish(G_latitude);
          longitude.publish(G_longitude);
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