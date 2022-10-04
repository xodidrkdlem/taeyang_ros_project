#!/usr/bin/python3
#-*- coding: utf-8 -*- 

import rospy
from yh_difference.srv import YhDifference, YhDifferenceResponse

def add(req):
    if(req.a >= req.b):
        result = req.a - req.b
    else:
        result = req.b - req.a

    rospy.loginfo("a = %d, b = %d",req.a, req.b)
    rospy.loginfo("response: result = %d",result)
    
    return YhDifferenceResponse(result)

def add_two_ints_server():
    rospy.init_node("yh_difference_server")

    my_server = rospy.Service("command_line",YhDifference ,add)

    rospy.loginfo("Service Server Ready")

    rospy.spin()

if __name__ == "__main__" :
    add_two_ints_server()
