#include "ros/ros.h"
#include "yh_check/YhCheck.h" 



int main(int argc,char**argv)
{
    ros::init(argc,argv, "yh_check_distance");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_check::YhCheck>("yh_check_distance",20);
   
    
   
    ros::Rate loop_rate(2); 

    yh_check::YhCheck msg;
    
    


    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        ROS_INFO("send msg :%d", msg.stamp.sec);
        ROS_INFO("send msg :%d", msg.stamp.nsec);
        
        pub.publish(msg);
        
        loop_rate.sleep();
    }


    return 0;
}
