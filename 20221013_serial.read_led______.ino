const int led = 13;
void setup() {
  Serial.begin(115200);
  pinMode(led,OUTPUT);
}

void loop() {
  if(Serial.available()){
    char userInput = Serial.read();

    switch(userInput){
      case 'n' :                            //'n'처럼 한글자만 사용 가능. 여러글자 예를 들어 'on' 실행 안됨.
      digitalWrite(led,HIGH);
      break;
      case 'f' :
      digitalWrite(led,LOW);
      break;
      default:
        break;
    }
    
  }
 

 
  
}
