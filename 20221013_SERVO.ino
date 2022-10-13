#include <TimerOne.h>

const int SERVO = 9;                            //servo 상수에 9번핀을 할당

const int SERVO_PERIOD =20000;                  //사각 파형의 주기를 20000us로 설정 이러면 50HZ로 작동
const int SERVO_MINDUTY = (1024/20)*0.7;        //servo로 나가는 사각 파형의 HIGH구간을(07.ms)설정.700마이크로 초동안 값이 나가며,0도로 회전합니다.
const int SERVO_MAXDUTY = (1024/20)*2.3;


void setup() {

  Timer1.initialize();
  Timer1.pwm(SERVO, 0);

  
  Timer1.setPeriod(SERVO_PERIOD);

  Timer1.setPwmDuty(SERVO, SERVO_MINDUTY);

  delay(1000);                                //1초동안 기다립니다.

 
 
 /* for(int angle=SERVO_MINDUTY;angle<=SERVO_MAXDUTY;angle++){
   Timer1.setPwmDuty(SERVO, angle);
   delay(30);  */
 for(int cnt=0;cnt<=2;cnt++){
   Timer1.setPwmDuty(SERVO,SERVO_MINDUTY);
   delay(1000);
   Timer1.setPwmDuty(SERVO,SERVO_MAXDUTY);
   delay(1000);   
 }
   Timer1.disablePwm(SERVO);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
