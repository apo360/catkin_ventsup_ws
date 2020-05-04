#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "serial/serial.h"
#include <vector>

using std::vector;
using std::string;
using std::cout;

vector<string> split(string str, char delimiter)
{
    vector<string> ret;
    if(str.empty()) 
    {
        ret.push_back(string(""));
        return ret;
    }

    unsigned i = 0;
    string strstack;
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


void DateCallback(const std_msgs::String::ConstPtr& msg)
{
  /*string name;
  std::stringstream S(msg->data.c_str());
  while(getline(S,name,'\n'))
    cout << name << std::endl;*/
  
  cout << msg->data.c_str() << std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "status_device_node");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/rs232_out", 1000, DateCallback);

    ros::spin();
  
  return 0;
}