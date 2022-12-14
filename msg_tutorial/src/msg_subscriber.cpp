#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h" //Mymsg 메세지 헤더 파일 //빌드시 자동 생성


//void msgcallback(const std_msgs::String::ConstPtr& msg)
void msgCallback(const msg_tutorial::Mymsg::ConstPtr& msg)  //어디서 꺼내오는지가 바뀜.
{
    ROS_INFO("receive msg : %d", msg->stamp.sec); //msg의 stamp의 sec을 출력한다.
    ROS_INFO("receive msg : %d", msg->stamp.nsec);//msg의 stamp의 nsec을 출력한다.
    ROS_INFO("receive msg : %d", msg->data); //msg의 data를 출력한다.
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "msg_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("burger",30,msgCallback);

    ros::spin(); // 대기
    
    return 0;
}