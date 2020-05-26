/*
 1 - Definir o numero de Wait Points
 2 - Inserir lat, lng, rumo, Vel
 3 - Comparar com a posição atual e marcar
 4 - Calcular abatimento e tempo a percorrer
    4.1 - tendo em conta a nenhuma variavél
    4.2 - Tendo em conta a variavéis (vento, maré, ondulação)
 5 - 
*/
#include <iostream>
#include <vector>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "GPS.h"
#include <boost/algorithm/string.hpp>
#include <math.h>

int num_wpn;

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

double DegreesConvertDecimal(std::string valores){
   std::vector<std::string> lat_lng = split(valores, ' ');
   for (unsigned int iter_split = 0; iter_split < lat_lng.size(); iter_split++)
      {
         lat_lng[iter_split];
      }
   int Glat_lng = std::stoi(*lat_lng.begin());
   float Mlat_lng = std::stof(*(lat_lng.begin()+1))/60;
   float Slat_lng = std::stof(*(lat_lng.begin()+2))/(60*60);

   double Dlat;
   if(*(lat_lng.begin()+3) == "W" || *(lat_lng.begin()+3) == "O" || *(lat_lng.begin()+3) == "S"){
      Dlat = (Glat_lng + Mlat_lng + Slat_lng)*(-1);
   }else
   {
      Dlat = (Glat_lng + Mlat_lng + Slat_lng);
   }
   return Dlat;
}

double radians(double value){
   double values_Radian = (value) * M_PI / 180.0;
   return values_Radian;
}

double distancBetween(double lat1, double lng1, double lat2, double lng2)
{
  // returns distance in meters between two positions, both specified
  // as signed decimal-degrees latitude and longitude. Uses great-circle
  // distance computation for hypothetical sphere of radius 6372795 meters.
  // Because Earth is no exact sphere, rounding errors may be up to 0.5%.

   // convert to radians 
   double dLat = radians(lat2 - lat1); 
   double dLon = radians(lng2 - lng1); 

   // apply formule Haversine 
   double lat_lng = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(radians(lat1)) * cos(radians(lat2)); 
   double rad = 6372795; 
   double c = 2 * asin(sqrt(lat_lng)); 
   return rad * c; 
}

int main(int argc, char **argv)
{
   ros::init(argc, argv, "planning");
   
   if(argc > 2 ) // Verificar o numero de parametros
   {
      ROS_WARN("Deve inserir apenas um parametro.");
   }
   else
   {
      num_wpn = std::stoi(argv[1]);
      if (num_wpn < 1)
      {
         ROS_WARN("Nao foi possivel definir o numero de Wait Point.");
      }
      else
      {
         std::string plano;
         std::cout << "Please, wrait Wp1 : ";
         std::getline (std::cin, plano);
         
         std::vector<std::string> str_split = split(plano, ',');
            for (unsigned int iter_split = 0; iter_split < str_split.size(); iter_split++)
            {
              str_split[iter_split];
            }

         double Dlat = DegreesConvertDecimal(*str_split.begin());
         
         double Dlng = DegreesConvertDecimal(*(str_split.begin()+1));
         
         std::string rumo = *(str_split.begin()+2);

         std::string vel = *(str_split.begin()+3);

         std::cout << distancBetween(38.1147, -9.13806, Dlat, Dlng) << std::endl;
      }
   }  
   return 0;
}
