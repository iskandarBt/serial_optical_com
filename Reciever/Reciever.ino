#include "Laser_Rx.h"

char data_buff[20];

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(A5)==HIGH){
    Serial.println("wokeup !\n");
    delay(SPEED + (SPEED/4)); // delay to read in the middle of the pulse
    int byteNumber = readStartByte();
    readData(byteNumber);
    Serial.println(data_buff);
    flushBuffer();
  }

}
