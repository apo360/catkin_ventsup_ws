#include "ros/ros.h"
#include "std_msgs/String.h"
#include "serial/serial.h"

serial::Serial my_serial("/dev/ttyUSB2", 9600, serial::Timeout::simpleTimeout(1000));

class loraTopics
{

    private:
        std_msgs::String lora_msgs;
        ros::Publisher lora_listen;
        ros::Subscriber sub;
    
    public:
        loraTopics(ros::NodeHandle *n)
        {
            lora_listen = n->advertise<std_msgs::String>("lora_listen", 1000);

            sub = n->subscribe("lora_talker", 1000, &loraTopics::LoraCallback, this);
        }

        void LoraCallback(const std_msgs::String::ConstPtr& msg)
        {

            std::string nome = msg->data.c_str();
            size_t enviar_port = my_serial.write(nome);
            std::string result = my_serial.read(128);

            std::stringstream gps_stream;
            gps_stream << result;
            lora_msgs.data = gps_stream.str();

            lora_listen.publish(lora_msgs);
        }
};

int main(int argc, char **argv)
{

  ros::init(argc, argv, "lora_listen");

  ros::NodeHandle n;

  loraTopics pt = loraTopics(&n);

  ros::spin();

  return 0;
}