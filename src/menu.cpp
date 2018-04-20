#include "ros/ros.h"
#include "homework1/menu.h"
#include <cstdlib>
#include <iostream>

using namespace std; 

int main(int argc, char **argv)
{
  ros::init(argc, argv, "menu");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<homework1::menu>("menu");
  while(ros::ok){
  homework1::menu srv;
  cout << "Menu:\na-Visualizza linea intera\nn-Visualizza nome\ne-Visualizza eta\nc-Visualizza Corso\nq-Exit\n";
  string scelta;
  cout << "Inserisci scelta: ";
  cin >> scelta;
  
  cout << "Ho preso la scelta numero: " << scelta << "\n";
  srv.request.choice = (string)scelta;

 
  if (client.call(srv))
  {
    ROS_INFO("Rispostra da service: %s", srv.response.response.c_str());
   
 if (scelta == "q")
	return 0; 
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }
}
  return 0;
}
