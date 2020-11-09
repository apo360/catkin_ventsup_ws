#include "ros/ros.h"
#include "std_msgs/String.h"
#include "serial/serial.h"

serial::Serial my_serial("/dev/ttyACM0", 115200, serial::Timeout::simpleTimeout(1000)); // port, baudrate, timeout in milliseconds

class controller
{
private:
    ros::Publisher motor;
    //ros::Subscriber;
public:
    controller(ros::NodeHandle *nh){
        motor = nh->advertise<std_msgs::String>("/controller_motor", 1); // start, close vel EB, BB
    };
};


int main(int argc, char ** argv){

    ros::init(argc, argv, "control_node");

    ros::NodeHandle nh;

    controller cll = controller(&nh);

    ros::spin();

    return 0;
}