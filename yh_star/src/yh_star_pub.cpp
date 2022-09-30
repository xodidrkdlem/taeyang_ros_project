#include "ros/ros.h"
#include "yh_star/YhStarMsg.h"   //패키지 이름,만든 메세지 파일.


int main(int argc,char**argv)
{
    ros::init(argc,argv, "yh_star_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_star::YhStarMsg>("yh_star_topic",20);
    
   
    ros::Rate loop_rate(2); //1초에 2번 0.5초에 1번  Hz주기

    yh_star::YhStarMsg msg;
    int cnt = 1;


    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = cnt;  
        pub.publish(msg);
        cnt++;
        loop_rate.sleep();
    }
     return 0;    

}