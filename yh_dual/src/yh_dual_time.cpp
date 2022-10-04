#include "ros/ros.h"
#include "yh_dual/YhDual.h"



void msgCallback(const yh_dual::YhDual::ConstPtr& msg)  //어디서 꺼내오는지가 바뀜.
{
    ROS_INFO("receive msg : %d", msg->stamp.sec); //msg의 stamp의 sec을 출력한다.
    ROS_INFO("receive msg : %d", msg->stamp.nsec);//msg의 stamp의 nsec을 출력한다.
   
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_dual_time");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("yh_dual_topic",30,msgCallback);

    ros::spin(); // 대기
    
    return 0;
}