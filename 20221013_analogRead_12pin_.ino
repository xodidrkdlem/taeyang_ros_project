const int led[12] = {2,3,4,5,6,7,8,9,10,11,12,13};
const int analogPin = A0;

void setup()
{
  for(int x=0;x<=11;x++){
  pinMode(led[x], OUTPUT);
  }  
}

void loop() {
  
 int sensorInput = analogRead(analogPin);
  
  
  for(int x=0; x<=11; x++){
    
       if(sensorInput >1024/13*(1+x))
          digitalWrite(led[x],HIGH);
    
       else digitalWrite(led[x], LOW);
    
   }
       
      
 
  
}

  
  
  
  
  
