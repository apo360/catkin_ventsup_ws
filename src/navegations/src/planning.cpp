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
#include <boost/algorithm/string.hpp>
#include <math.h>

int num_wpn;

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

   void setRumo(double rumo){this->rumo = rumo;}
   double getRumo(){return this->rumo;}

   double radians(double value){
      double values_Radian = (value) * M_PI / 180.0;
      return values_Radian;
   }
}points;

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

double CalculoRumo(double x, double y, double x2, double y2)
{
   double vs1 = pow((x),2)+pow((y),2);
   double vs2 = pow((x2),2)+pow((y2),2);
   double v1 = sqrt(vs1);
   double v2 = sqrt(vs2);

   double theta = acos((x)/(v1*v2));

   return theta;
}
int main(int argc, char **argv)
{
   ros::init(argc, argv, "planning");

   ros::NodeHandle nh;

   ros::Publisher info = nh.advertise<std_msgs::String>("/planning_info", 1);

   std_msgs::StringConstPtr plan = ros::topic::waitForMessage<std_msgs::String>("/super_plano", nh);

   std::vector<std::string> array_points = split(plan->data.c_str(),',');

   std::string total = *array_points.begin();

   int num_wp = array_points.size() - 1;

   points t[num_wp];
   points* tp;
   tp = &t[0];

   if (std::atoi(total.c_str()) != num_wp)
   {
      std_msgs::String e;
      e.data = "Numero de pontos diferente com a quantidade de pontos";
      info.publish(e);
   }else
   {
      for (int i = 1; i <= num_wp; i++)
      {
         std::vector<std::string> str_split = split(*(array_points.begin() + i),';');
         for (unsigned int iter_split = 0; iter_split < str_split.size(); iter_split++)
          {
            str_split[iter_split];
          }
         t[i-1].wp = i-1;
         t[i-1].setLatitude(*str_split.begin());
         t[i-1].setLongitude(*(str_split.begin() + 1));
         t[i-1].setVelocidade(*(str_split.end() - 1));
         //t[i-1].setRumo(CalculoRumo(DegreesConvertDecimal(t[i-1].getLatitude()),DegreesConvertDecimal(t[i-1].getLongitude())));

         if((i-1) == 0){
            t[i-1].setdistancBetween(
            DegreesConvertDecimal("38 39 45.32 N"),DegreesConvertDecimal("9 8 51.89 W"),
            DegreesConvertDecimal(t[i-1].getLatitude()),DegreesConvertDecimal(t[i-1].getLongitude())
            ); 

            t[i-1].setRumo(CalculoRumo(
            DegreesConvertDecimal("38 39 45.32 N"),DegreesConvertDecimal("9 8 51.89 W"),
            DegreesConvertDecimal(t[i-1].getLatitude()),DegreesConvertDecimal(t[i-1].getLongitude())
            ));
         }else
         {
            t[i-1].setdistancBetween(
            DegreesConvertDecimal(t[i-2].getLatitude()),DegreesConvertDecimal(t[i-2].getLongitude()),
            DegreesConvertDecimal(t[i-1].getLatitude()),DegreesConvertDecimal(t[i-1].getLongitude())
            );

            t[i-1].setRumo(CalculoRumo(
            DegreesConvertDecimal(t[i-2].getLatitude()),DegreesConvertDecimal(t[i-2].getLongitude()),
            DegreesConvertDecimal(t[i-1].getLatitude()),DegreesConvertDecimal(t[i-1].getLongitude())
            ));
         }
      }
   }
   for (int j = 0; j < num_wp; j++)
   {
      std::cout << (tp+j)->wp <<" -- "<< (tp+j)->getLatitude() <<" -- "<< (tp+j)->getLongitude() <<" -- "<< (tp+j)->getvelocidade() << " -- "<< (tp+j)->getdistancBetween() << " -- "<< (tp+j)->getRumo() << std::endl;
   }
   ros::spin();

   return 0;
}
