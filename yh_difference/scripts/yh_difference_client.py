#!/usr/bin/python3
#-*- coding: utf-8 -*- 

import rospy
from yh_difference.srv import YhDifference
import sys    #sys == system sys모듈을 import해서 


def add_two_ints_client(a,b):
    rospy.wait_for_service("command_line")
    try:
        yh_difference_client = rospy.ServiceProxy("command_line",YhDifference) #서비스 이름.서비스 타입 넣어줘야됨.
        res = yh_difference_client(a,b)
        return res.result
    except rospy.ServiceException as e:                     #except 에러가 나면 잡아주는 구문 service exception --> 서비스 통신중 에러뜨면 잡음.
        rospy.logerr("Service call failed ; %s ",e)

if __name__ == "__main__":
    rospy.init_node("yh_difference_client")

    if len(sys.argv) != 3:
        rospy.loginfo("rosrun yh_difference yh_difference_client.py a b")
        rospy.loginfo("a,b: int32 number")
        sys.exit(1)

    a = int(sys.argv[1])
    b = int(sys.argv[2])

    result = add_two_ints_client(a,b)
    rospy.loginfo("request : a = %d, b = %d",a,b)
    rospy.loginfo("response: result = %d", result)

