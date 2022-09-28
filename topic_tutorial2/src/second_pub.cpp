#include "ros/ros.h"  //ros 헤더파일
#include "std_msgs/Int32.h"   // Int 메세지 헤더 파일.

int main(int argc, char** argv)
{
    ros::init(argc,argv, "second_pub");  //노드 이름 초기화
    ros::NodeHandle nh;  //ROS 시스템과 통신을 위한 노드 핸들선언

    //퍼블리셔 선언
    //패키지의() 메세지파일()을 이용한 퍼블리셔()를 만든다.
    //토픽은 (my_count)이며, 퍼블리셔큐(queue) 사이즈는 (100)이다.

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("my_count",100);

    ros::Rate loop_rate(2); //루프 주기를 2Hz로 설정한다. 1초에 2번진동

    std_msgs::Int32 msg; 
    msg.data = 0;   //msg의 data에 0를 넣는다.

    while(ros::ok())  //ros가 켜져있는동안 (ok하는동안) publish 한다 ==True
    {
        pub.publish(msg);  //pub이 msg를 퍼블리시한다.
        loop_rate.sleep(); //위에서 정한 주기에 따라 sleep한다.(0.5초마다)
        msg.data++;

    }



    return 0;
}
