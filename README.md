# taeyang_ros_project
ros study.

### 2022년 09월 27일 
topic_tutorial 패키지 생성
c언어로 퍼블리셔, 서브스크라이버 생성
터미널로 실행

### 2022년09월 28일
python으로 퍼블리셔, 서브스크라이버 생성
터미널로 실행

## ros 명령어(roscore)

- ROS master 실행. (roscore)
- 노드 켜기전에 항상 먼저 실행.(각 노드를 잇고,정보를 처리)



### catkin_create_pkg

-현재 위치한 작업 공간에 패키지를 생성한다.
catkin_create_pkg 패키지이름 의존성
'''bash
    catkin_create_pkg <패키지이름> <의존성1>
    <의존성2> ....
'''
'''bash
    catkin_create_pkg topic_tutorial roscpp
    rospy std_msgs
'''

## 과제1
- topic_test 패키지를 만들고, cpp, python 중 원하는 언어를 선택하여 노드를 만든다.
- publisher 노드 1개, subscriber 노드 1개
- publisher 노드의 이름은 my_test_publisher이고 std_msgs 패키지의 Int 64 메시지를 publish한다.
- subscriber 노드의 이름은 my_test_subscriber이고 std_msgs 패키지의 Int64 메시지를 subscribe한다.
-publisher 노드는 메시지에 0부터 100까지 숫자를 담아서 0.25ch wnrlfh publish 한다.
- subscriber 노드는 메시지에 담긴숫자를 출력한다.
- 메시지에 담는 숫자는 매번 1씩 증가시키고 100에 도달하면 다시 0부터 보낸다.
