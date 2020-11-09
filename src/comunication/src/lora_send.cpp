#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "serial/serial.h"

using std::string;
using std::exception;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using ros::Publisher;

class ReadLora{

    private:
    std_msgs::String sslora;
    std::stringstream msg_lora;
    ros::Publisher Lora_Send, lora_out;
    ros::Subscriber GetLora, GetGestCom;

    public:

        ReadLora(ros::NodeHandle *nh){
            Lora_Send = nh->advertise<std_msgs::String>("/lora_send", 10); //Tópico que envia os dados para o nó RS232
            lora_out = nh->advertise<std_msgs::String>("/lora_out", 10);
            GetLora = nh->subscribe("/rs232_out", 1000, &ReadLora::LoraCallback, this);
            GetGestCom = nh->subscribe("/gest_send", 10, &ReadLora::G_ComunicCallback, this);
        }

        void G_ComunicCallback(const std_msgs::String::ConstPtr& comunicdate){
            //Lora_Send.publish("A");
            //ROS_INFO("%s", comunicdate->data.c_str());
            /* int count = 0;
            ros::Rate rate(5);
            while (ros::ok())
            {
                std_msgs::String ola;
                ola.data = std::to_string(count);
                Lora_Send.publish(ola);
                count++;
                rate.sleep();
            } */
            ROS_INFO("%s", comunicdate->data.c_str());
            ros::Rate rate(5);
            std::stringstream teste(comunicdate->data.c_str());
            std_msgs::String ola;
            ola.data = teste.str();
            Lora_Send.publish(ola);
            rate.sleep();
        }
        void LoraCallback(const std_msgs::String::ConstPtr& loradate){

            std::string loras;

            std::stringstream loras_stream(loradate->data.c_str());

            while (getline(loras_stream, loras, '\n'))
            {
                if(loras.substr(0,4) == "Lora"){

                    std::cout << loras << std::endl;
                    /*std::vector<std::string> imu_split = ReadImu::split(imus.substr(6), ' ');
                    for (unsigned int i = 0; i < imu_split.size(); i++)
                    {
                        imu_split[i];
                    }
                    std::cout << *imu_split.begin() << " " << ReadImu::cardinal(std::stod(*imu_split.begin())) << std::endl;*/
                }
            }
        }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "lora_send");
    
    ros::NodeHandle nh;

    ReadLora lorass = ReadLora(&nh);

    ros::spin();
     
}