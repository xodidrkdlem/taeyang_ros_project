#!/usr/bin/python             
#-*- coding: utf-8 -*-

#1.파이썬의 위치를 나타내는것.(리눅스에서 파이썬으로 ros 진행할때 꼭 써줘야됨.) 2. 한국어 에러나지말라고 써주는것.

import rospy
from std_msgs.msg import Int32   #스탠다드 메시지중에서 스트링이라는 메시지 쓰겠다는것.

def my_counter():
    rospy.init_node("py_second_pub")
    pub = rospy.Publisher("my_count", Int32, queue_size=100)   #토픽이름,메세지타입,큐사이즈

    loop_rate = rospy.Rate(20)

    msg = Int32()
    msg.data = 0

    while not rospy.is_shutdown():
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__":
    try:
        my_counter()
    except rospy.ROSInterruptException:
        pass
