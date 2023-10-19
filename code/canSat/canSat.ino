#include "../common.ino"

void setup(){
  Serial.begin(9600);
  init();
  Serial.println("Beginning ... "); 
}

void loop(){
  unsigned long time = millis();
  
  Mirf.setTADDR((byte *)"serv1");
  
  Mirf.send((byte *)&time);
  
  while(Mirf.isSending()){
  }
  Serial.println("Finished sending");
  delay(10);
  while(!Mirf.dataReady()){
    //Serial.println("Waiting");
    if ( ( millis() - time ) > 1000 ) {
      Serial.println("Timeout on response from server!");
      return;
    }
  }
  
  Mirf.getData((byte *) &time);
  
  Serial.print("Ping: ");
  Serial.println((millis() - time));
  
  delay(1000);
}