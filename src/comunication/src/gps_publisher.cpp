// --------------- %Begin Include Headers% ----------------------//
#include "ros/ros.h" // 

#include "std_msgs/String.h"
#include "std_msgs/Char.h"
// %EndTag(MSG_HEADER)%

#include <sstream>
#include <iostream>
#include <cstdio>
#include <unistd.h>

using std::string;
using std::exception;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

//------- %Serial Port header%--------//
//#include "serial/serial.h"


// --------------- %END Include Headers% ----------------------//

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  int sum, count = 0;

  ros::init(argc, argv, "gps_publisher"); // name of node;

  ros::NodeHandle n;

// %Tag(PUBLISHER)%
  ros::Publisher gps_lat_pub = n.advertise<std_msgs::String>("gps_lat", 1000);
  ros::Publisher gps_lng_pub = n.advertise<std_msgs::String>("gps_lng", 1000);
  ros::Publisher gps_position_pub = n.advertise<std_msgs::String>("gps_position", 1000);
  ros::Publisher gps_utc_pub = n.advertise<std_msgs::String>("gps_utc", 1000);
  ros::Publisher gps_velocity_pub = n.advertise<std_msgs::String>("gps_velocity", 1000);

  ros::Rate loop_rate(10); // %Tag(LOOP_RATE)%

  /*while (ros::ok()) // %Tag(ROS_OK)%
  {

    std_msgs::String msg;
    std::stringstream ss;

    int port = open("/dev/ttyUSB0", O_RDWR);

char msgss[] = "Hello \r";
int n_written = 0, spot = 0, num_bytes = 0;

char read_buf[64];

memset(read_buf, '\0', sizeof read_buf);
std::fstream in("/dev/ttyUSB0");

    in << 2;
    in >> read_buf;
    std::string dados = read_buf;

	if(in.fail()) break;

if (port < 0)
    {ss << "hello world Porta Fechada " << " " << errno << " " << strerror(errno) << std::endl;}
else
    {
    if(num_bytes < 0)
        {ss << printf("Error reading: %s", strerror(errno));}
    else
    
        {
            while(dados.size()){

            }
            ss << "" << dados << std::endl;
        
            }  
    }
    msg.data = ss.str();
    
// %EndTag(FILL_MESSAGE)%

// %Tag(ROSCONSOLE)%
    ROS_INFO("%s", msg.data.c_str());
// %EndTag(ROSCONSOLE)%

// %Tag(PUBLISH)%
    gps_position_pub.publish(msg);
// %EndTag(PUBLISH)%
close(port);
}*/
// %Tag(SPINONCE)%
    ros::spinOnce();
// %EndTag(SPINONCE)%

// %Tag(RATE_SLEEP)%
    loop_rate.sleep();
// %EndTag(RATE_SLEEP)%
    ++count;

  
  return 0;
}
// %EndTag(FULLTEXT)%
