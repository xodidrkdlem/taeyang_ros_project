#!/usr/bin/python3
#-*- coding: utf-8 -*- 

import rospy
from yh_service.srv import YhSrv, YhSrvResponse

def add(req):
    result = req.a*req.b 
    rospy.loginfo("a = %d, b = %d",req.a, req.b)
    rospy.loginfo("response: result = %d",result)
    return YhSrvResponse(result)

def add_two_ints_server():
    rospy.init_node("py_yh_server")

    my_server = rospy.Service("command_line",YhSrv ,add)

    rospy.loginfo("Service Server Ready")

    rospy.spin()

if __name__ == "__main__" :
    add_two_ints_server()
