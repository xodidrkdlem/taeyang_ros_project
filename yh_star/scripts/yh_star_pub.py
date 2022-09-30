#!/usr/bin/python3
#-*- coding: utf-8 -*- 

import rospy
from yh_star.msg import YhStarMsg

def star_publisher():
    rospy.init_node("yh_star_pub")
    pub = rospy.Publisher("yh_star_topic", YhStarMsg,queue_size=100)

    loop_rate = rospy.Rate(2)

    msg = YhStarMsg()


    while not rospy.is_shutdown():

        msg.stamp = rospy.Time.now()
        msg.data += 1
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__":
    try:
        star_publisher()
    except rospy.ROSInterruptException:
            pass


        

