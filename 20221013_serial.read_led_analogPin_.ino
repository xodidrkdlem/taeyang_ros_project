const int led[6] = {3,5,6,9,10,11};                   //아날로그 핀 6개 선언
const int analogPin = A0;                             //가변저항에 사용할 아날로그 핀 선언 

void setup()
{
  for(int x=0;x<=5;x++){                              //for문 사용해서 6개의 led의 pinMode 설정(핀번호,핀 모드)
  pinMode(led[x], OUTPUT);
  }
}

void loop()
{
  int sensorInput = analogRead(analogPin);            //analogRead(pin) - 읽고자 하는 아날로그 핀 번호 0~1023사이의 값을 돌려줌.
  
  if(sensorInput > 1024/7*(1+0)){   
    digitalWrite(led[0],HIGH);
  }
  else {
    digitalWrite(led[0], LOW);
  }
  
  if(sensorInput > 1024/7*(1+1)){
     digitalWrite(led[1],HIGH);
  }
  else {
    digitalWrite(led[1], LOW);
  }
  
  if(sensorInput > 1024/7*(1+2)){
    digitalWrite(led[2],HIGH);
  }
  else{
    digitalWrite(led[2], LOW);
  }  
  if(sensorInput > 1024/7*(1+3)){
    digitalWrite(led[3],HIGH);
  }
  else {
    digitalWrite(led[3], LOW);
  }
  
  if(sensorInput > 1024/7*(1+4))
    digitalWrite(led[4],HIGH);
  else digitalWrite(led[4], LOW);
  
  if(sensorInput > 1024/7*(1+5))
    digitalWrite(led[5],HIGH);
  else digitalWrite(led[5], LOW);
}

/*                                                      for문사용해서 간략하게 만든 코드
const int led[6] = {3,5,6,9,10,11};
const int analogPin = A0;

void setup()
{
  for(int x=0;x<=5;x++){
  pinMode(led[x], OUTPUT);
  }
}

void loop() {
  
  int sensorInput = analogRead(analogPin);
  
  
  for(int x=0; x<=5; x++){
    
       if(sensorInput >1024/7*(1+x))
          digitalWrite(led[x],HIGH);
    
       else digitalWrite(led[x], LOW);
    
   }
       
      
  
  
}

*/
  
  
  
  
  


  
