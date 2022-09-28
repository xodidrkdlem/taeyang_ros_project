#!/usr/bin/python             
#-*- coding: utf-8 -*-

#1.파이썬의 위치를 나타내는것.(리눅스에서 파이썬으로 ros 진행할때 꼭 써줘야됨.) 2. 한국어 에러나지말라고 써주는것.

import rospy
from std_msgs.msg import Int64

def msgCallback(msg):
    rospy.loginfo("msg : %d",msg.data)

def my_listener():
    rospy.init_node("py_test_subscriber")
    rospy.Subscriber("my_test", Int64 , msgCallback, queue_size=100)  #토픽이름, 메세지 타입, 콜백 함수, 큐사이즈


    rospy.spin()



if __name__== "__main__":
    my_listener()
