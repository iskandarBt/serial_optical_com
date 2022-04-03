#include "Laser_Tx.h"


void getReady(int startByte){
  Serial.println(startByte, DEC);
  bitWrite(startByte, 8, 1);
  for(int i=8; i >= 0; i--){
     digitalWrite(Laser, bitRead(startByte,i));
     Serial.print(bitRead(startByte,i), DEC);   
     delay(SPEED);
  }
  Serial.print("\n");
}

void pushData(){
  Serial.println("pushing data ...");
  while(Serial.available() > 0){
      char Byte = Serial.read();
      for(int i=7; i >= 0; i--){
         digitalWrite(Laser, bitRead(Byte,i));
         //Serial.print(bitRead(Byte,i), DEC);   
         delay(SPEED);
      }
  }
  Serial.println("end sneding.");
  digitalWrite(Laser,LOW);
}
