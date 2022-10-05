#include "ros/ros.h"
#include "yh_check/YhCheck.h" 



int main(int argc,char**argv)
{
    ros::init(argc,argv, "yh_check_distance");  //노드이름
    ros::NodeHandle nh;  

    ros::Publisher pub = nh.advertise<yh_check::YhCheck>("check_distance",20);  //퍼블리셔 만들기.
   
    
   
    ros::Rate loop_rate(2);  //Hz 주기 만들기.

    yh_check::YhCheck msg;  //메세지 만들기.

    msg.data = true;
    
    


    while(ros::ok())
    {
        msg.stamp = ros::Time::now();  //현재시간
        pub.publish(msg);
        msg.data  = !msg.data; //true면 false, false면 true
        loop_rate.sleep();
    }


    return 0;
}
