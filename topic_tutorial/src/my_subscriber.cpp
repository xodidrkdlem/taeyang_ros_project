#include "ros/ros.h"  //Ros 헤더 파일
#include "std_msgs/String.h" //std_msgs 패키지의 String 메세지 헤더 파일

void msgcallback(const std_msgs::String::ConstPtr& msg) //메세지를 받았을때 행동을 정해주는중
{
 
    ROS_INFO("msg : %s", msg->data.c_str());  

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_subscriber"); // 노드 이름 초기화

    ros::NodeHandle nh; // 노드 핸들 선언 (주고 받는 연결을 핸들링 해주는 애)

    //서브스크라이버 선언
    //패키지(std_msgs)의 메시지(String)를 이용한 서브스크라이버(sub)를 선언한다.
    //토픽은 (my_topic)이며, 서브스크라이버큐(queue) 사이즈를 (100)으로 설정한다.
    //콜백 함수는 (msgcallback)이다.
    ros::Subscriber sub = nh.subscribe("my_topic", 100, msgcallback);

    // sub가 메세지를 받았을때 msgcallback 함수를 실행시켜라.

    //콜백 함수 호출을위한 함수, 메시지가 수신되기를 대기
    //수신되었을 경우 콜백 함수를 호출한다.
    
    ros::spin();
    // spin을 만나면 멈춤. 계속해서 대기하면서 콜백함수를 기다림.

    
    return 0;
}

