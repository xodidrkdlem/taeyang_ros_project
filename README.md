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

