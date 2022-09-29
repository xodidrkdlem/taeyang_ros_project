#include "ros/ros.h"
// #include "std_msgs/Int64.h" 아래 우리가 만든 메세지 헤더 파일은 이런 형태로 만들어준다.
#include "msg_tutorial/Mymsg.h"  //Mymsg 메시지 헤더파일


int main(int argc,char**argv)
{
    ros::init(argc,argv, "msg_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<msg_tutorial::Mymsg>("burger",20);
    //
   
    ros::Rate loop_rate(1); //1초에 2번 0.5초에 1번  Hz주기

    msg_tutorial::Mymsg msg;
    int cnt = 0;


    while(ros::ok())
    {
        msg.stamp = ros::Time::now();//현재 시간을 msg의 stamp에 담는다.현재시간을 알려주는 함수 ros::Time
        msg.data = cnt;  //cnt 변수의 값을 msg의 data에 담는다.
        ROS_INFO("send msg :%d", msg.stamp.sec);  //stamp.sec을 출력한다.(초)
        ROS_INFO("send msg :%d", msg.stamp.nsec);  //stamp.nsec을 출력한다.(나노second,초뒤에 1.??????에서 ??????임.)
        ROS_INFO("send msg :%d", msg.data);  //data를 출력한다.
        pub.publish(msg);
        cnt++;
        loop_rate.sleep();
    }


    return 0;
}

