import rospy
from std_msgs.msg import Bool 
from yh_check.msg import YhCheck
  
def msg_talker():
    rospy.init_node("yh_check_camera")
    pub = rospy.Publisher("check_camera",YhCheck, queue_size= 10)

    loop_rate = rospy.Rate(2.5)  #Hz 넣어주기.

    msg = YhCheck()

    cntc = 0

    while not rospy.is_shutdown():
        #Mymsg:
        #   time stamp
        #   int32 data
        msg.stamp = rospy.Time.now()
        msg.data = cntc
        rospy.loginfo("send msg : %d", msg.stamp.secs)
        rospy.loginfo("send msg : %d", msg.stamp.nsecs)
        rospy.loginfo("send msg : %d", msg.data)

        pub.publish(msg)
        cnt += 1
        loop_rate.sleep()


if __name__ == "__main__":
    try:
        msg_talker()
    except rospy.ROSInterruptException:
            pass