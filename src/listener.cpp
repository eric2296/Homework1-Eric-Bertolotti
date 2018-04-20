#include "ros/ros.h"
#include "homework1/menu.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
int flag=3;

using namespace std;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  vector<string> strings;
  istringstream f(msg->data);
  string s;    
  int count=1;
  
  while(getline(f, s, ';')) {
        
	if(count == flag){
  		ROS_INFO("I heard:[%s]",s.c_str());}
	else if(flag == 4){
		ROS_INFO("I heard:[%s]", msg->data.c_str());
		break;}	
	count++;
	}
}



bool add(homework1::menu::Request  &req,
         homework1::menu::Response &res)
{
  res.response = "Ricevuto";
  ROS_INFO("HO RICEVUTO LA SCELTA: [%s]",  req.choice.c_str());

  if(req.choice == "a"){
	flag=4;
	system("gnome-terminal -x sh -c 'rosrun homework1 talker'");}	
	
  if(req.choice == "n"){ 
	flag=1;
	system("gnome-terminal -x sh -c 'rosrun homework1 talker'");}
  if(req.choice == "e"){ 
	flag=2;
	system("gnome-terminal -x sh -c 'rosrun homework1 talker'");}
  if(req.choice == "c"){
	flag=3;
	system("gnome-terminal -x sh -c 'rosrun homework1 talker'");}
  if(req.choice == "q"){
	return true;

	}


  ROS_INFO("sending back response: [%s]", res.response.c_str());
  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  std_msgs::String msg;
 // ros::Publisher chatter1_pub = n.advertise<std_msgs::String>("chatter1", 1000); //Diciamo al master che andiamo a pubblicare msg su chatter

  //msg.data = "Ciao";
 // chatter1_pub.publish(msg);
  


  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::ServiceServer service = n.advertiseService("menu", add); 
  ros::spin();

  return 0;
}
