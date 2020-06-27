#include <iostream>
#include <vector>
#include "std_msgs/String.h"
#include <boost/algorithm/string.hpp>
#include <math.h>

typedef struct WaitPoint
{
   int wp;
   std::string latitude;
   std::string longitude;
   double      velocidade;
   double      distancBetween;
   double      rumo;

   void setLatitude(std::string latitude)
   {
      this->latitude = latitude.replace(latitude.find("("),1,"\0");
   }
   std::string getLatitude(){return this->latitude;}

   void setLongitude(std::string longitude){this->longitude = longitude;}
   std::string getLongitude(){return this->longitude;}

   void setVelocidade(std::string Velocidade){this->velocidade = std::atof(Velocidade.c_str());}
   double getvelocidade(){return this->velocidade;}

   void setdistancBetween(double lat1, double lng1, double lat2, double lng2)
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
      this->distancBetween = rad * c; 
   }
   double getdistancBetween(){return this->distancBetween;}

   double radians(double value){
      double values_Radian = (value) * M_PI / 180.0;
      return values_Radian;
   }
}points;