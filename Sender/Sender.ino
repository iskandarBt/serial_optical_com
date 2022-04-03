
#include "Laser_Tx.h"

//char data[20];

void setup() {
  pinMode(Laser, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  if(Serial.available() > 0){
    getReady(Serial.available());
    pushData();
    }  
  delay(200);   
}
