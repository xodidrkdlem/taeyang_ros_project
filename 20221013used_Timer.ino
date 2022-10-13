#include <TimerOne.h>                           //Timer1관련 함수를 사용하기 위해 헤더파일 포함.(TimerOne/스케치-> 라이브러리 포함하기->라이브러리 관리 ->TimerOne 검색후 설치 )

const int LED = 10;                             // pwm이 가능한 핀 번호 설정

void setup() {
  Timer1.initialize();                          //아두이노 칩 내부에 있는 Timer1 모듈 초기화
  Timer1.pwm(LED,0);                            //led로 사각 파형 보내도록 설정.0은 HIGH의 개수를 나타내며 1023까지 사용가능

  Timer1.setPeriod(1000);                 //1000000us는 1초. 뒤에 100은 초당 100번 100Hz
                     //0~1023까지 상하비 조정가능.
  
    

}

void loop() {
  for(int t_high=0;t_high<=1023;t_high++){
    Timer1.setPwmDuty(LED,t_high);
    delay(100);
  }
  // put your main code here, to run repeatedly:

}
