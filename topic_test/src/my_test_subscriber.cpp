#include "ros/ros.h"
#include "std_msgs/Int64.h"

void msgCallback(const std_msgs::Int64::ConstPtr& msg)
{
    ROS_INFO("count : %d", msg->data);
}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "my_test_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("my_test",100,msgCallback);

    ros::spin();

    return 0;
}
