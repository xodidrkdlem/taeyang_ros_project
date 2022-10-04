#!/usr/bin/python3
#-*- coding: utf-8 -*- 


import rospy
from param_tutorial.srv import Calculate, CalculateResponse

PLUS = 1 
MINUS = 2
MULTIPLICATION = 3
DIVISION = 4

def calculation(req):
    my_operator = rospy.get_param("calculation_method")
    if my_operator == PLUS:
        result = req.a + req.b
    elif my_operator == MINUS:
        result = req.a - req.b
    elif my_operator == MULTIPLICATION:
        result = req.a * req.b 
    elif my_operator == DIVISION:
        if req.b == 0:
            result = 0
        else:
            result = req.a // req.b
    else:
        result = req.a + req.b

    rospy.loginfo(f"a: {req.a}, b: {req.b}, result: {result}")
    res = CalculateResponse()
    res.result = result
    return res

def calculate_server():
    rospy.init_node("calculate_server")

    rospy.set_param("calculation_method", PLUS)
    my_server = rospy.Service("calculate", Calculate, calculation ) #서버이름, srv이름,함수이름

    rospy.loginfo("Service Server ready")
    rospy.spin()

if __name__ == "__main__":
    calculate_server()
