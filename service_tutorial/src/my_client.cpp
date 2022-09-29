#include "ros/ros.h"
#include "service_tutorial/AddTwoints.h" //서비스 헤더파일 ,, 빌드시 생성

#include <cstdlib> //atoi 함수 사용을 위한 라이브러리(문자열을 정수로 바꿔주는 함수)

int main(int argc, char** argv)  //이거 쓰는 이유: 프로그램 실행할 때 가져올수있는애가몇개인지(argc), 뭔지(argv)
{
    ros::init(argc,argv,"my_client");

    //rosrun 패키지 이름 노드이름 a b
    //argv = {노드이름, a, b}
    if (argc !=3)                           //인자 개수가 3이 아니면! 인자 개수(argc),이 코드에서 설정한 인자개
    {
        ROS_INFO("command : rosrun service_tutorial my_client arg1 arg2");              
        ROS_INFO("arg1, arg2 : int32, int32 number");
        return 1;   //return 1은 비정상 종료를알려주는 숫자. 0을 해도 상관은 없음.
    }    

    ros::NodeHandle nh;
    //서비스 클라이언트 ()를 선언한다.
    //서비스 이름은 ()이고 패키지()의 ()서비스 파일을 사용한다.
    ros::ServiceClient my_client = nh.serviceClient<service_tutorial::AddTwoints>("add_two_ints");
    
    // 노드 실행시 입력된 변수를 서비스 요청 값의 a,b에 저장된다.
    service_tutorial::AddTwoints srv;
    srv.request.a = atoi(argv[1]);
    srv.request.b = atoi(argv[2]);


    if(my_client.call(srv))  //srv를 보내는것 위에 requesta,b 요런애들
    {
        ROS_INFO("send srv: srv.request.a = %d, srv.request.b = %d",srv.request.a,srv.request.b);
        ROS_INFO("receive srv: srv.response.result = %d",srv.response.result);
    }

    else
    {
        ROS_ERROR("Failed to call service");   //에러인 경우에 사용,ERROR쓰면 빨간 글씨로 나옴.

        return 1;
    }
    return 0;   
}

