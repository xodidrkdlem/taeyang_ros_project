#!/usr/bin/python             
#-*- coding: utf-8 -*-                          

 #1.파이썬의 위치를 나타내는것.(리눅스에서 파이썬으로 ros 진행할때 꼭 써줘야됨.) 2. 한국어 에러나지말라고 써주는것.
import rospy
from std_msgs.msg import String   #스탠다드 메시지중에서 스트링이라는 메시지 쓰겠다는것.

def talker():
    pub = rospy.Publisher("my_topic", String, queue_size=100)  #queue_size 뭔지 물어보기
    rospy.init_node("py_publisher")
    loop_rate = rospy.Rate(10)   #이 안에는 루프주기 Hz를 넣는다. 10을 넣었기 때문에 1초에 10번. 즉 0.1초 주기.

    msg = String()
    msg.data = "krorean air"

    while not rospy.is_shutdown():   #안꺼진동안 무한 반복.
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__":        #얘가 메인일 때만 실행.
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
                                   
                                   
                                   
                                   
 