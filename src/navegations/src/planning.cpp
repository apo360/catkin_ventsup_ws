
#include <iostream>
#include <vector>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/algorithm/string.hpp>
#include <math.h>
#include "navegations/navegation.h"
#include "serial/Strings.h"
#include <map>
#include <fstream>

#define TWO_PI 360

using namespace std;
Strings::StringSplit Caractres;
navegation::Planning *planif;

ofstream output("/home/ventsup/catkin_ventsup/src/navegations/src/missao2.txt");

double radiansToDegrees(double angleRadians){
      double angleRadians_ = (angleRadians) * 180.0 / M_PI;
      return angleRadians_;
   }

   double radians(double value){
      double values_Radian = (value) * M_PI / 180.0;
      return values_Radian;
   }

double setdistancBetween(double lat1, double lng1, double lat2, double lng2)
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

double courseTo(double lat1, double long1, double lat2, double long2)
{
// returns course in degrees (North=0, West=270) from position 1 to position 2,
// both specified as signed decimal-degrees latitude and longitude.
// Because Earth is no exact sphere, calculated course may be off by a tiny fraction.
// Courtesy of Maarten Lamers

double dlon = radians(long2-long1);

lat1 = radians(lat1);
lat2 = radians(lat2);

double a1 = sin(dlon) * cos(lat2);
double a2 = sin(lat1) * cos(lat2) * cos(dlon);

a2 = cos(lat1) * sin(lat2) - a2;
a2 = radiansToDegrees(atan2(a1, a2));

if (a2 < 0.0) {a2 += TWO_PI;}

   return a2;
}

typedef struct planning_
{
   int wp;
   string lat[200];
   string lng[200];
   double velocidade[200];
   double distancBetween;
   double rumo;

   public:

      void setLatitude(std::string lat) {this->lat[200] = lat.replace(lat.find("("),1,"\0");}
      std::string getLatitude(){return this->lat[200];}

      void setLongitude(std::string lng) {this->lng[200] = lng;}
      std::string getLongitude(){return this->lng[200];}

      void setVelocidade(std::string Velocidade) {this->velocidade[200] = std::atof(Velocidade.c_str());}
      double getvelocidade(){return this->velocidade[200];}

         //double getdistancBetween(){return this->distancBetween;}

         void setRumo(double rumo){this->rumo = rumo;}
         double getRumo(){return this->rumo;}

}planningA;

planningA teste[200];
class Point0
{
   private:
      ros::Publisher info, rumo_info, abat_info;
      ros::Subscriber gps, plano, Imu_Orient, gps_sog;
      double latitude_p, longitude_p, imu_X, sog;

   public:

      void setLatitude_p(string lat){ this->latitude_p = std::atof(lat.c_str());}

      double getLatitude_p(){return this->latitude_p;}

      void setLongitude_p(string lng){ this->longitude_p = std::atof(lng.c_str());}

      double getLongitude_p(){return this->longitude_p*(-1);}

      void setImuX_p(string imu_x){ this->imu_X = std::atof(imu_x.c_str());}

      double getImuX_p(){ return this->imu_X;}

      void setSog(string sog){ this->sog = atof(sog.c_str());}

      double getSog(){return this->sog;}

      void CallImuOrient(const std_msgs::String::ConstPtr& msg_imu){
         vector<string> array_imu = Caractres.split(msg_imu->data.c_str(),' ');
         Point0::setImuX_p(*array_imu.begin());
      }

      void CallISog(const std_msgs::String::ConstPtr& msg_sog){
         vector<string> array_imu = Caractres.split(msg_sog->data.c_str(),',');
         Point0::setSog(*array_imu.begin());
      }

      int i = 0;

      void GPSCall(const std_msgs::String::ConstPtr& msg)
      {
         vector<string> array_gps = Caractres.split(msg->data.c_str(),',');

         Point0::setLatitude_p(*array_gps.begin());

         Point0::setLongitude_p(*(array_gps.end()-1));

         // Calculo da distância ate o WaitPoint em curso
         double latD = planif->DegreesConvertDecimal(teste[i].getLatitude());
         double lngD = planif->DegreesConvertDecimal(teste[i].getLongitude());

         double dist_ = setdistancBetween(Point0::getLatitude_p(),Point0::getLongitude_p(),latD, lngD);

         std_msgs::String bd_count;
         //  posição do WaitPoint em curso
         bd_count.data = "Wp"+ to_string(1+i)+' '+to_string(latD)+' ' + to_string(lngD);
         info.publish(bd_count);
         output << to_string(Point0::getLatitude_p())+' '+to_string(Point0::getLongitude_p())+'\n';

         // Calculo do rumo a realizar
         double rumo_ = courseTo(Point0::getLatitude_p(),Point0::getLongitude_p(),latD, lngD);
         
         // Calculo do Abatimento abat = (proa - rumo);
         double abat_ = (Point0::getImuX_p() - rumo_);
         string abatStr;
         
         // Condição para verificar se o Veículo está a EB ou BB do planeamento em curso
         if(abat_ < 0){abatStr = to_string(abat_*(-1))+" BB";} // Calculo do Abatimento
         else{abatStr = to_string(abat_)+" EB";}

         // Calculo do Tempo estimado para concluir até o WaitPoint em curso com velocidade constante (velocidade do planeamento)
         double temp = (((dist_)/(teste[i].getvelocidade()*0.5144))/60); // 1 nó = 0.5144 m/s   ---   // dividir por 60 para ter o tempo em minutos

         // calculo do tempo de acordo com a velocidade que está a realizar (velocidade de gps(sog))
         double Tsog = (((dist_)/(Point0::getSog()))/60);
         string Tpp;

         if(Tsog > temp){Tpp = "Atrasado " + to_string(Tsog - temp);}
         else if(Tsog < temp){Tpp = "Adiantado " + to_string(temp - Tsog);}

         
         bd_count.data = "Dist Wp"+ to_string(1+i) + ':' + to_string(dist_)+", Rumo: " + to_string(rumo_)+", Abat: " + abatStr+", Tempo: " + to_string(temp) + ' ' + Tpp;

         string testes = "Distância ao Wp"+to_string(1+i)+' ' +to_string(dist_)+", Rumo: " + to_string(rumo_)+", Abat: " + abatStr+", Tempo: " + to_string(temp) + ' ' + Tpp;
         cout << testes << endl;

         info.publish(bd_count);

         if(dist_ < 5){
            
            i++;
            printf("Mudar para o Wp%i", i);
         }
            
      }
      const string OpenFile(){
         string texto;
         ifstream in;
         in.open("/home/ventsup/catkin_ventsup/src/navegations/src/plano.txt");
         if(!in.is_open())
            cout << "Aberto" << endl;
         
         while (getline(in, texto));
            return texto.c_str();
      }
      
      void rst()
      {
         vector<string> array_points = Caractres.split(OpenFile(),',');

         string total = *array_points.begin();

         int num_wp = array_points.size() - 1;

         if (atoi(total.c_str()) != num_wp)
         {
            std_msgs::String e;
            e.data = "Numero de pontos diferente com a quantidade de pontos";
            info.publish(e);
         }else
         {
            for (int i = 1; i <= num_wp; i++)
            {
               vector<std::string> str_split = Caractres.split(*(array_points.begin() + i),';');
               
               for (unsigned int iter_split = 0; iter_split < str_split.size(); iter_split++)
               {
                  str_split[iter_split];
               }
               teste[i-1].wp = i;
               teste[i-1].setLatitude(*str_split.begin());
               teste[i-1].setLongitude(*(str_split.begin() + 1));
               teste[i-1].setVelocidade(*(str_split.end() - 1));

               /* if((i-1) == 0){
                  teste[i-1].setdistancBetween(
                  Point0::getLatitude_p(),Point0::getLongitude_p(),
                  planif->DegreesConvertDecimal(teste[i-1].getLatitude()),planif->DegreesConvertDecimal(teste[i-1].getLongitude())
                  ); 

                  teste[i-1].setRumo(planif->courseTo(
                  Point0::getLatitude_p(),Point0::getLongitude_p(),
                  planif->DegreesConvertDecimal(teste[i-1].getLatitude()),planif->DegreesConvertDecimal(teste[i-1].getLongitude())
                  ));
               }else
               {
                  teste[i-1].setdistancBetween(
                  planif->DegreesConvertDecimal(teste[i-2].getLatitude()),planif->DegreesConvertDecimal(teste[i-2].getLongitude()),
                  planif->DegreesConvertDecimal(teste[i-1].getLatitude()),planif->DegreesConvertDecimal(teste[i-1].getLongitude())
                  );

                  teste[i-1].setRumo(planif->courseTo(
                  planif->DegreesConvertDecimal(teste[i-2].getLatitude()),planif->DegreesConvertDecimal(teste[i-2].getLongitude()),
                  planif->DegreesConvertDecimal(teste[i-1].getLatitude()),planif->DegreesConvertDecimal(teste[i-1].getLongitude())
                  ));
               } */
            }
         }
      }

      Point0(ros::NodeHandle *nh){
         info = nh->advertise<std_msgs::String>("/planning_info", 1);
         gps = nh->subscribe("/position_vehicle", 10, &Point0::GPSCall, this);
         Imu_Orient = nh->subscribe("/imu_orientation", 1, &Point0::CallImuOrient, this);
         gps_sog = nh->subscribe("/gps_sog_cog", 1, &Point0::CallISog, this);
         //plano = nh->subscribe("/super_plano", 100, &Point0::rst, this);
      }
};

int main(int argc, char **argv)
{
   string texto;
   ros::init(argc, argv, "planning");
   ros::NodeHandle nh;

   Point0 *t;
   t->rst();
         
   Point0 nt = Point0(&nh);

   ros::spin();

   return 0;
}