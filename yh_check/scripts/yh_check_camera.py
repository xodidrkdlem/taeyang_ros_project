#!/usr/bin/python             
#-*- coding: utf-8 -*-



import rospy
from yh_check.msg import YhCheck


def camera():
    rospy.init_node("yh_check_camera")
    pub = rospy.Publisher("check_camera",YhCheck, queue_size= 10)

    loop_rate = rospy.Rate(2.5)  #Hz 넣어주기.

    msg = YhCheck()

   

    while not rospy.is_shutdown():
       
        msg.stamp = rospy.Time.now()
        msg.data = not msg.data
        rospy.loginfo("send msg : %d", msg.stamp.secs)
        rospy.loginfo("send msg : %d", msg.stamp.nsecs)
        rospy.loginfo("send msg : %d", msg.data)

        pub.publish(msg)
        
        loop_rate.sleep()

     


if __name__ == "__main__":
    try:
        camera()
    except rospy.ROSInterruptException:
            pass