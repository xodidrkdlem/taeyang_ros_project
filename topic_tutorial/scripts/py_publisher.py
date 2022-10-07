#!/usr/bin/python3                                                   
#-*- coding: utf-8 -*-                                              

#1.파이썬의 위치를 나타내는것.(리눅스에서 파이썬으로 ros 진행할때 꼭 써줘야됨.)
#2. 한국어 에러나지말라고 써주는것. 
import rospy                                                          #rospy를 불러온다.
from std_msgs.msg import String                                       #스탠다드 메시지중에서 스트링이라는 메시지 불러온다.

def talker():                                                         #함수 만들기.
    pub = rospy.Publisher("my_topic", String, queue_size=100)         #퍼블리쉬 만들기(topic 이름, 메세지 타입, 큐사이즈)
    rospy.init_node("py_publisher")                                   #노드 선언(노드이름)
    loop_rate = rospy.Rate(10)                                        #루프 주기 

    msg = String()                                                    #msg라는 변수안에 import한 String을 넣어준다. -->그렇게 된다면 msg를 사용하는것이 String을 사용하는것이 된다. 
    msg.data = "krorea air"                                           #msg.data 라는 변수안에  = "korea air"라는 문자열을 넣어준다. 

    while not rospy.is_shutdown():                                    #while(~하는동안) +  not shutdown(꺼지지않는) = 꺼지지않는 동안(무한루프)
        pub.publish(msg)                                              #퍼블리쉬 선언
        loop_rate.sleep()                                             #위에서 정한 주기에 따라 대기.0.1초마다 값을 보내주게끔,보내고,쉬고,보내고 쉬고(Hz주기에따라)

if __name__ == "__main__":                                            #(if __name__ == "__main__":) = 메인일 때만 실행.
    try:                                                              #try: 실행할 코드(여기서는 talker라는 함수)
        talker()                                                      
    except rospy.ROSInterruptException:                               #except(예외)
        pass                                                          #except에 예외 이름을 지정해서 특정 예외가 발생했을 때만 처리 코드를 실행
                                   
                                   
                                   
                                   
 