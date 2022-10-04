#include "ros/ros.h"
#include "param_tutorial/Calculate.h"

#define PLUS 1            // define == 매크로 상수
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4


int my_operator = MINUS; //전역 변수로 쓴 이유, main에서도 써야되고 스위치문에서도 써야되서.
bool calculation(param_tutorial::Calculate::Request& req,
                 param_tutorial::Calculate::Response& res)

{
    switch (my_operator)                 //
    {
        case PLUS:
            res.result = req.a + req.b;
            break;
         case MINUS:
            res.result = req.a - req.b;
            break;
         case MULTIPLICATION:
            res.result = req.a * req.b;
            break;
         case DIVISION:
            res.result = req.a / req.b;
            break;
        default:
            res.result = req.a + req.b;
            break;            
    }
    ROS_INFO("a: %d, b: %d, result: %d", req.a, req.b, res.result);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"calculate_server");
    ros::NodeHandle nh;

    nh.setParam("calculation_method", MINUS); // set(설정해준다)이라는 함수는 파라미터 서버에 calculation_method 라는 이름의 변수안에 PLUS(1)를 넣어준다.

    ros::ServiceServer calculate_server = nh.advertiseService("calculate",calculation);

    ros::Rate loop_late(10);
    while (ros::ok())
    {
        nh.getParam("calculation_method", my_operator);
        //파라미터 서버에 있는 calculation_method 라는 이름의 변수를 my_operator 여기로 가져와서 할당 저장하겠다.
        ros::spinOnce();
         //스핀을 한번만 해주는 함수(콜백 한번하고 끝). ros::spin()-계속 대기하면서 콜백함수를 호출해주는것. 리퀘스트가 오면 계속 내어준다.
        loop_late.sleep();
    }
    
    
    return 0;
}


