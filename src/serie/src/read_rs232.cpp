#include <string>
#include <iostream>
#include <vector>
#include "serial/serial.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

using std::string;
using std::exception;
serial::Serial my_serial("/dev/ttyUSB0", 9600, serial::Timeout::simpleTimeout(2000));

class WritePort{

    private:
        std_msgs::String ssm;
        std::stringstream msg;
        ros::Publisher rs232_out;
        ros::Subscriber rs232_in;
        
    public:

        WritePort(ros::NodeHandle *nh){

            rs232_out = nh->advertise<std_msgs::String>("/rs232_out", 1000);

            rs232_in = nh->subscribe("/rs232_in", 1000, &WritePort::RS232WriteCallback, this);
        }

        void RS232WriteCallback(const std_msgs::String::ConstPtr& texto){

            // Verificar se a porta está aberta
            if(!my_serial.isOpen()){
                ROS_WARN("%s"," Serial port ins't Open.");
                WritePort::enumerate_ports();
            }
    
            std::string dados = texto->data.c_str();

            size_t enviar_port = my_serial.write(dados);

            std::string result = my_serial.read(128);

            std::stringstream S(result);
            std::string name;

            while (getline(S, name, '\n'))
            {
                msg << name.substr(4) << std::endl;
                ssm.data = msg.str();
                rs232_out.publish(ssm);
            }
        }

        void enumerate_ports(){

            std::vector<serial::PortInfo> devices_found = serial::list_ports();

            std::vector<serial::PortInfo>::iterator iter = devices_found.begin();

            while( iter != devices_found.end())
            {
                serial::PortInfo device = *iter++;

                printf("(%s, %s, %s)\n", device.port.c_str(), device.description.c_str(), device.hardware_id.c_str());
            }
        }
};

// port, baudrate, timeout in milliseconds

int main(int argc, char ** argv){

    ros::init(argc, argv, "read_rs232"); // recomendar, que o nome do 'Node' seja o mesmo que do ficheiro

    ros::NodeHandle n; // Criamos um identificador

    WritePort wp = WritePort(&n);

    ros::spin();
}