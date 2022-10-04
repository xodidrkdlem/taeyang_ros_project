import rospy
from std_msgs.msg import Bool 
from yh_check.msg import YhCheck  
from yh_check import msg_talker
def msgCallback(msg):
    if(cntd/4== 0):
    rospy.loginfo("msg : %d",msg.data)

def my_listener():
    rospy.init_node("yh_check_sub")
    rospy.Subscriber("check_camera","check_distance", YhCheck, msgCallback, queue_size=100)  #토픽이름, 메세지 타입, 콜백 함수, 큐사이즈


    rospy.spin()



if __name__== "__main__":
    my_listener()
