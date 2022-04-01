
#define SPEED 50  // time to send 1 bit (in ms)
int byteNumber = 0;

char data[20];
//char *p = data;


void setup() {
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(A5)==HIGH){
    Serial.println("wokeup !\n");
    delay(SPEED + (SPEED/2)); // delay to read in the middle of the pulse
    byteNumber = readStartByte();
    readData(byteNumber);
    Serial.println(data);
    data[0] = '\0';
  }

}


int readStartByte(){
  // Read the start byte and return the number of bytes in the data frame
  int byteNumber = 0;
  Serial.println("ReadByte function.\n");
  for(int i=7; i>=0; i--){
    bitWrite(byteNumber, i,digitalRead(A5)); 
    //Serial.print(digitalRead(A5)); // for debug  
    delay(SPEED);
  }
  //Serial.println("\n");
  return byteNumber;
   
}

char readData(int byteNumber){
  
  Serial.println("ReadData function.\n");
  for(int y=0; y < byteNumber; y++){
    for(int i=0; i <= 7; i++){
      bitWrite(data[y], 7-i, digitalRead(A5));
      //Serial.print(digitalRead(A5));
      delay(SPEED); 
    }
    //Serial.println(" "); 
  }
    
}
