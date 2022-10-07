#!/usr/bin/python3                                               #1.파이썬의 위치를 나타내는것.(리눅스에서 파이썬으로 ros 진행할때 꼭 써줘야됨.) 
#-*- coding: utf-8 -*-                                          #2. 한국어 에러나지말라고 써주는것.

import rospy                                                    #(rospy를 불러와서 쓰겠다!(import))              
from msg_tutorial.msg import Mymsg                              #(msg.tutorial.msg안에(from)있는 Mymsg를 불러오겠다.


def msg_talker():                                               #함수 msg_talker라고 이름 붙인 함수 만들기
    rospy.init_node("py_msg_pub")                               #ros에서 사용할 노드를 선언해준다. (선언해준다 == 이것이 사용할 노드의 이름이다.) 
    pub = rospy.Publisher("burger",Mymsg, queue_size= 10)       #사용할 퍼블리쉬를 만들어준다.(서버간 통신에서 사용할 채널이름,사용할 문자 타입이 있는 곳,큐사이즈)
    loop_rate = rospy.Rate(5)                                   #Hz 정해주기.(1초당 몇번{여기서는 5번} 주기로 움직이는지) == (초당 몇번의 통신이 오갈지.1/5= 0.2초)
    msg = Mymsg()                                                         
    cnt = 0

    while not rospy.is_shutdown():
        #Mymsg:
        #   time stamp
        #   int32 data
        msg.stamp = rospy.Time.now()
        msg.data = cnt
        rospy.loginfo("send msg : %d", msg.stamp.secs)
        rospy.loginfo("send msg : %d", msg.stamp.nsecs)
        rospy.loginfo("send msg : %d", msg.data)

        pub.publish(msg)
        cnt += 1
        loop_rate.sleep()


if __name__ == "__main__":
    try:
        msg_talker()
    except rospy.ROSInterruptException:
            pass







 