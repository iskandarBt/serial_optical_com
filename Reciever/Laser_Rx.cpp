#include "Laser_Rx.h"

extern char data_buff[20];

int readStartByte(){
  // Read the start byte and return the number of bytes in the data frame
  int byteNumber = 0;
  Serial.println("Reading Start Byte...");
  for(int i=7; i>=0; i--){
    bitWrite(byteNumber, i,digitalRead(A5)); 
    //Serial.print(digitalRead(A5)); // for debug  
    delay(SPEED);
  }
  //Serial.println(" ");
  return byteNumber;    
}

void readData(int byteNumber){
  
  Serial.println("Reading data ...");
  for(int y=0; y < byteNumber; y++){
    for(int i=0; i <= 7; i++){
      bitWrite(data_buff[y], 7-i, digitalRead(A5));
      //Serial.print(digitalRead(A5));
      delay(SPEED); 
    }
    //Serial.println(" "); 
  }   
}

//***************************
void flushBuffer(){
  for(int i=0; i<20; i++){
    data_buff[i] = 0;
  }
}
