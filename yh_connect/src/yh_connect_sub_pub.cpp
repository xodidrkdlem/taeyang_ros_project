#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include "std_msgs/Float64.h"

ros::Publisher pub;

void msgCallback(const std_msgs::Int64::ConstPtr& msg)
{
    if (msg->data %5 == 0)
    {
        std_msgs::Float64 float_msg;
        float_msg.data = (float)msg->data/3.0f;  //(float)을 써주면 int msg.data가 float으로 바뀐다.
        pub.publish(float_msg); 
        ROS_INFO("sibal~");
    }
   
}
int main(int argc, char** argv)
{
    ros::init(argc,argv, "yh_connect_sub_pub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("yh_topic",30,msgCallback);
    pub = nh.advertise<std_msgs::Float64>("yh_topic2",10);

    ros::spin(); 
    
    return 0;
}