#!/usr/bin/python             
#-*- coding: utf-8 -*-


#1.파이썬의 위치를 나타내는것.(리눅스에서 파이썬으로 ros 진행할때 꼭 써줘야됨.)
#2. 한국어 에러나지말라고 써주는것. 

import rospy
from std_msgs.msg import String

def msgCallback(msg):
    rospy.loginfo("msg : %s",msg.data)

def listener():
    rospy.init_node("py_subscriber")
    rospy.Subscriber("my_topic", String, msgCallback, queue_size=100)  #큐사이즈는 안넣어도 임의로 넣어짐.


    rospy.spin()



if __name__== "__main__":
    listener()

