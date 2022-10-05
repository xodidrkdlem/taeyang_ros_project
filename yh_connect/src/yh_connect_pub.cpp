#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc,char**argv)
{
    ros::init(argc,argv, "yh_connect_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int64>("yh_topic",20);
    
   
    ros::Rate loop_rate(4); 

    std_msgs::Int64 msg;
    
    
    

    while(ros::ok())
    {
       
          
        ROS_INFO("send msg :%d",msg.data);
        pub.publish(msg);
        msg.data++;
        loop_rate.sleep();
    }


    return 0;
}
