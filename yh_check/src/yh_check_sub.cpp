#include "ros/ros.h"
#include "yh_check/YhCheck.h" 


bool distance = true; //함수 밖에 쓴 전역변수.
bool camera = true;

void distanceCallback(const yh_check::YhCheck::ConstPtr& msg) 
{
    distance = msg->data;
    if (distance && camera)
    {
        ROS_INFO("ok");
    }
    
}

void cameraCallback(const yh_check::YhCheck::ConstPtr& msg)
{
    camera = msg->data;
    if (distance && camera)
    {
        ROS_INFO("ok");
    }
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_check_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub_distance = nh.subscribe("check_distance",30,distanceCallback);
    ros::Subscriber sub_camera = nh.subscribe("check_camera",30,cameraCallback);

    ros::spin();

    
    return 0;

    
}

/*

#include "ros/ros.h"
#include "yh_check/YhCheck.h" 

class Mysub                  
{   
    public:
        //함수들 생성
        Mysub(coid)             ---> 생성자 함수 = ros::init(argc,argv, "yh_connect_sub");
        {
            ros::Subscriber sub_distance = nh.subscribe("check_distance",30,&Mysub::distanceCallback,this);
            ros::Subscriber sub_camera = nh.subscribe("check_camera",30,&Mysub::cameraCallback,this); -->this는 인스턴스
        }
    private:
        //변수들 생성
        ros::NodHandle nh;
        ros::Subscriber sub_distance;
        ros::Subscriber sub_camera;
        bool distance = true;
        bool camera = true;

};

*/