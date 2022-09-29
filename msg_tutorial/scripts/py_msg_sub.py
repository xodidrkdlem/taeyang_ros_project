#!/usr/bin/python
#-*- coding: utf-8 -*-  
                                  #한글 안쓸꺼면 안써도됨.(utf)

import rospy
#from std_msgs.msg import String
from msg_tutorial.msg import Mymsg

def msgCallback(msg):
    rospy.loginfo("recieve msg : %d",msg.stamp.secs)
    rospy.loginfo("recieve msg : %d",msg.stamp.nsecs)
    rospy.loginfo("recieve msg : %d",msg.data)

def msg_listener():
    rospy.init_node("py_msg_sub")
    rospy.Subscriber("burger",Mymsg,msgCallback,queue_size= 30)

    rospy.spin()

if __name__ == "__main__":
    msg_listener()


