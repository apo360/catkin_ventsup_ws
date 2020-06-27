#include <iostream>
#include <vector>
#include "ros/ros.h"
#include "std_msgs/String.h"

using std::string;
class ReadNavigation
{
    private:

    ros::Publisher position_vehicle, new_position;
    ros::Subscriber Gps_lat, Gps_Sat, Gps_vel, Imu_rumo;

    public:
        ReadNavigation(ros::NodeHandle *nh)
        {
            position_vehicle = nh->advertise<std_msgs::String>("/topic_position_vehicle",1);

            new_position = nh->advertise<std_msgs::String>("/position_vehicle",1);

            Gps_lat = nh->subscribe("/gps_position", 1, &ReadNavigation::CallPositionGps, this);

            //Gps_Sat = nh->subscribe("/gps_satelites", 1, &ReadNavigation::CallSateliteGps, this); //Verificar mais tarde essa parte
        }

        void CallPositionGps(const std_msgs::String::ConstPtr &gps_pos){
            //std::cout << gps_pos->data.c_str() << std::endl;
            std::vector<std::string> str_split = ReadNavigation::split(gps_pos->data.c_str(), ',');
            for (unsigned int iter_split = 0; iter_split < str_split.size(); iter_split++)
            {
                str_split[iter_split];
            }
            std::stringstream posit_stream, posit_plan;
            std_msgs::String posicao, planeamento;

            posit_stream << ReadNavigation::convert_decimal_to_degree({*str_split.begin(),*(str_split.begin() + 1)}) << std::endl;
            posit_plan << *str_split.begin()+','+*(str_split.begin() + 1);

            posicao.data = posit_stream.str();
            planeamento.data = posit_plan.str();

            position_vehicle.publish(posicao);
            new_position.publish(planeamento);
        }

        const std::string convert_decimal_to_degree(std::vector<std::string> value)
        {

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
            return *posicao.begin() +' '+ *(posicao.begin() + 1);
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

 int main(int argc, char ** argv){

     ros::init(argc, argv, "navigation_node");

     ros::NodeHandle nh;

     ReadNavigation rn = ReadNavigation(&nh);

     ros::spin();

     return 0;
 }
