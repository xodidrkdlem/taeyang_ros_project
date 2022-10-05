#include "ros/ros.h"

#include "std_msgs/Float64.h"


void msgCallback(const std_msgs::Float64::ConstPtr& msg) 
{
   
    ROS_INFO("%f", msg->data); //msg의 data를 출력한다.
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_connect_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("yh_topic2",30,msgCallback);

    ros::spin(); 
    
    return 0;
}
