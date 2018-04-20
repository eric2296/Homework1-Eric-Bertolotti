#include "ros/ros.h"	
#include "std_msgs/String.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
int flag=0;
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  
  ROS_INFO("I heard: [%s]", msg->data.c_str());

}

/**
 * This homework1 demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(0.5);


  ifstream OpenFile("/home/eric/catkin_ws/src/homework1/data.txt");
  char ch[1024];  


  int count = 0;
  while (ros::ok())
   {
    
   // 	ros::Subscriber sub = n.subscribe("chatter1", 1000, chatterCallback);
    
    	std_msgs::String msg;
    	
  
    	std::stringstream ss;
    	OpenFile.getline(ch,1024);   

    	ss << ch;
    	msg.data = ss.str();

    	ROS_INFO("%s", msg.data.c_str());
    	chatter_pub.publish(msg);
		 
    	ros::spinOnce();
   	
  	loop_rate.sleep();
  	++count;}
  OpenFile.close();
  return 0;
}
