// --------------- %Begin Include Headers% ----------------------//
#include "ros/ros.h" // 
#include "std_msgs/String.h"
#include "std_msgs/Char.h"
// %EndTag(MSG_HEADER)%

#include <iostream>

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
    std_msgs::String ssm;
    std::stringstream msg_gps;
    ros::Publisher gps_position_gpgga, gps_position_gprmc, status_gps;
    ros::Subscriber GetGpsDate;

  public:
    ReadGps(ros::NodeHandle *nh){
      gps_position_gpgga = nh->advertise<std_msgs::String>("/topic_gps_gpgga",1000);
      gps_position_gprmc = nh->advertise<std_msgs::String>("/topic_gps_gprmc",1000);
      status_gps = nh->advertise<std_msgs::String>("/topic_gps_status",1000);
      GetGpsDate = nh->subscribe("/rs232_out", 1000, &ReadGps::GpsCallback, this);
    }

    void GpsCallback(const std_msgs::String::ConstPtr& Gpsdate){

      std::string gpss;
      std::stringstream gps_stream(Gpsdate->data.c_str());

      while (getline(gps_stream, gpss, '\n'))
      {
        if(gpss.substr(0,5) == "GPGGA"){

            std::vector<std::string> str_split = ReadGps::split(gpss.substr(6), ',');
            for (unsigned int iter_split = 0; iter_split < str_split.size(); iter_split++)
            {
              std::cout << str_split[iter_split] << std::endl;
            }
            
            //std::cout << *str_split.begin() << std::endl;
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

class GPS_Modelo{
  private: 

    string UTC, DATA;
    int satelites;
    double SOG, COG, latitude, longitude;

  public:

    double getSog() {return SOG;}

    void setSog(double $Sog)
    {
      SOG = $Sog;
    }

    double getCog() {return COG;}

    void setCog(double $Cog)
    {
      COG = $Cog;
    }

    int getSatelites() {return satelites;}

    void setSatelites(int $Satelites)
    {
      satelites = $Satelites;
    }

    double getlatitude() {return latitude;}

    void setLatitude(double $Latitude)
    {
      latitude = $Latitude;
    }

    double getLongitude() {return longitude;}

    void setLongitude(double $Longitude)
    {
      longitude = $Longitude;
    }

    string getUtc() {return UTC;}

    void setUtc(string $utc)
    {
      UTC = $utc;
    }

    string getData() {return DATA;}

    void setData(string $data)
    {
      DATA = $data;
    }
};

/*int run(int argc, char **argv){

  char char_array[128], equador, meridiano; // declaring character array
// port, baudrate, timeout in milliseconds
  serial::Serial my_serial("/dev/ttyUSB0", 9600, serial::Timeout::simpleTimeout(1000));

    while(ros::ok()) {
    vector< string > lista (8);
    for (size_t t = 1; t < 8; t++)
    {
      string valor = std::to_string(t);
      size_t bytes_wrote = my_serial.write(valor);
      string result = my_serial.read(128);
      //-----------------------------------------------------//
      strcpy(char_array, result.c_str()); // copying the contents of the string to char array 
      string s;
      for (int i = 0; i < result.length(); i++) // cicle
      {
        switch (char_array[i])
        {
        case ',': //termo de termino
          char_array[i] = '\0';
        break;
        }
        if((char_array[i] == 'N') | (char_array[i] == 'S'))
          {char_array[i] = '\0'; equador = char_array[i];}
        else if((char_array[i] == 'E') | (char_array[i] == 'W'))
          {char_array[i] = '\0'; meridiano = char_array[i];}
           
          s = s + char_array[i]; 
      }
      //----------------------------------------------------//
      lista[t] = s;
    }
    cout << "Lat : " << lista[1] << "Lng : " << lista[2] << "Utc : " 
          << lista[3] << "Data : " << lista[4] << "SOG : " << lista[5]
          << "COG : " << lista[6] << "Sat : " << lista[7]; 

          GPS_DAO val;

          val.listPosition(std::stod(lista[1]), std::stod(lista[2]), 
                          lista[3], lista[4], std::stod(lista[6]), 
                          std::stod(lista[5]), std::stoi(lista[7]));
          
          std_msgs::String msg_gpgga, msg_gprmc, msg_lat, msg_lng, msg_veloci;
          std::stringstream gpgga, gprmc, slat, slng, svelocity;

          gpgga <<"GPGGA, "<< "UTC: "<< lista[3].c_str() 
              << " Latitude: " << std::stod(lista[1]) 
              << " Longitude: " << std::stod(lista[2]) 
              << " Satelites: " << std::atoi(lista[7].c_str()) << endl;

          gprmc <<"GPRMC, "<< "UTC: "<< lista[3].c_str() 
              << " Latitude: " << std::stod(lista[1]) 
              << " Longitude: " << std::stod(lista[2]) 
              << " SOG: " << std::stod(lista[5])
              << " COG: " << std::stod(lista[6]) << endl;
          
          slat << " Latitude: " << std::stod(lista[1]) << endl;
          slng << " Longitude: " << std::stod(lista[2]) << endl;

          svelocity << " SOG: " << std::stod(lista[5]) << " COG: " << std::stod(lista[6]) << endl;
  }
 
  return 0;
}*/

int main(int argc, char **argv){
  ros::init(argc, argv, "gps_node"); // name of node;
  ros::NodeHandle nh;
  ReadGps gp = ReadGps(&nh);
  ros::spin();
return 0;
}