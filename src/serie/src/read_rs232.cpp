#include <string>
#include <iostream>
#include <vector>
#include "serial/serial.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

using std::string;
using std::stringstream;
using std::exception;
using std::vector;
serial::Serial my_serial("/dev/ttyUSB0", 9600, serial::Timeout::simpleTimeout(2000));

class WritePort{
    struct PortActive_Info
    {
        std::string id_port; /*! ID (e.g. VID:PID serial devices). */

        std::string name_port; /*! Address of the serial port (this can be passed to the constructor of Serial). */

        std::string state_port; /*! State serve for if device has connect or disconnect*/

        int count_port; /*! Count the ports connected*/
    };
    
    private:
        std_msgs::String ssm;
        stringstream msg;
        ros::Publisher rs232_out;
        ros::Subscriber rs232_in;
        vector<string> Active_Ports;
        vector<string> id_port;
        vector<string> nome_port;
        int count_port;
        char *ESP32_LoRa = "067b:2303";
    
    public:
        void enumerate_ports()
        {

            std::vector<serial::PortInfo> devices_found = serial::list_ports();

            std::vector<serial::PortInfo>::iterator iter = devices_found.begin();

            count_port = devices_found.size();

            while( iter != devices_found.end())
            {
                serial::PortInfo device = *iter++;

                if(device.hardware_id != "n/a")
                {
                    id_port.push_back(device.hardware_id+","+device.port);
                }
            }
        }

        WritePort(ros::NodeHandle *nh){

            rs232_out = nh->advertise<std_msgs::String>("/rs232_out", 1000);
            
            ros::Rate loop_rate(25);

            while (ros::ok())
            {
                WritePort::enumerate_ports(); // Identificar todas as portas
                
                for (int i = 0; i < id_port.size(); i++)
                {
                    string n = *(id_port.begin()+i);
                    try
                    {
                        int SNR_find = n.find("SNR");
                        std::cout << n.substr(SNR_find++) << std::endl;
                    }
                    catch(const std::exception& e)
                    {
                        
                        int vir_find = n.find(',');
                        string dev_port = n.substr(++vir_find);

                        int VID_PID_find = n.find("VID:PID");
                        stringstream txte_steam(n);
                        string txte;
                        vector<string> vec_stream;
                        vector<string> idvec_stream;
                        while(getline(txte_steam,txte,','))
                        {
                            vec_stream.push_back(txte);
                            stringstream id_steam(vec_stream[0]);
                            string id_str;
                            while(getline(id_steam,id_str,'='))
                            {
                                idvec_stream.push_back(id_str);
                            }
                        }
                        //std::cout << strcmp((*(--idvec_stream.end())),ESP32_LoRa.c_str());
                         char teste = (*(--idvec_stream.end()));
                        if(strcmp(*teste,*ESP32_LoRa) != 0){
                            //std::cout << *(--vec_stream.end()) << std::endl;
                            std::cout << "aceite" << std::endl;
                        }
                            //std::cout << "067b:2303".compare(teste) <<std::endl;
                            std::cout << *(--idvec_stream.end()) <<std::endl;
                            //std::cout << ESP32_LoRa.compare(*(--idvec_stream.end())) <<std::endl;
                        //}
                        
                        
                        
                    }
                }

                //std::string dados = "RPY/";

                ros::spinOnce();

                loop_rate.sleep();
            }
            
            //rs232_in = nh->subscribe("/rs232_in", 1000, &WritePort::RS232WriteCallback, this);
        }

    void RS232WriteCallback(const std_msgs::String::ConstPtr& texto){

        // Verificar se a porta está aberta
        if(!my_serial.isOpen()){
            ROS_WARN("%s"," Serial port ins't Open.");
            //WritePort::enumerate_ports();
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
};

// port, baudrate, timeout in milliseconds

int main(int argc, char ** argv){

    ros::init(argc, argv, "read_rs232"); // recomendar, que o nome do 'Node' seja o mesmo que do ficheiro

    ros::NodeHandle n; // Criamos um identificador

    WritePort wp = WritePort(&n);
}