#include <iostream>
#include <vector>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "supervisor/imgData.h"
#include "supervisor/imgDataArray.h"

void subCB(const supervisor::imgDataArray::ConstPtr& msg)
  {
    for (int i=0; i<msg->images.size(); ++i)
    {
      const supervisor::imgData &data = msg->images[i];
      ROS_INFO_STREAM("UL: " << data.upperleft << "UR: " << data.lowerRight <<
                      "color: " << data.color << "ID: " << data.cameraID);
    }
  }

  int main(int argc, char **argv)
  {
    ros::init(argc, argv, "tes");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("test", 1000, subCB);

    ros::spin();
  }