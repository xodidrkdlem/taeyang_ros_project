#include "ros/ros.h"
#include "service_tutorial/AddTwoints.h"  //서비스 헤더 파일


//service 통신의 server는 요청이 왔을 때 뭘해줘야되는지 정해줘야됨.

bool add(service_tutorial::AddTwoints::Request& req,                 //서비스 요청이 있을 경우 실행되는 콜백 함수
         service_tutorial::AddTwoints::Response& res)                //서비스 요청은 req, 서비스 응답은 res로 설정.

{
    res.result = req.a + req.b; //result는 Response안에 , int32 a,int32 b는 request안에 있어서 이렇게 표현
    ROS_INFO("request: a = %d, b = %d",req.a, req.b);

    ROS_INFO("response: result = %d", res.result);

    return true; //응답을 잘했다 라는 뜻.

}

int main(int argc, char** argv)
{
    ros::init(argc,argv, "my_server");
    ros::NodeHandle nh;
    
    ros::ServiceServer my_server = nh.advertiseService("add_two_ints",add);  //여기서 add_two_ints는 (서비스 이름)토픽이름이라고 생각하면됨.
                                                      //서비스 서버()를 선언한다.  서비스 이름은()이고,
                                                      //요청이 왔을때 ()를 실행한다. ()패키지의 ()서비스 파일을 이용한다.
     ROS_INFO("Service Server Ready.");                                                 
    
    ros::spin(); //서버는 요청이 들어오는걸 항상 대기 해야되므로. 
    
    return 0;
}