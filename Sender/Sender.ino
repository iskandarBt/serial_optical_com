#define Laser 12
#define SPEED 50
int Byte = 0;
void setup() {
  pinMode(Laser, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    Serial.println("get ready ...");
    getReady(Serial.available());
    while(Serial.available() > 0){
      Byte = Serial.read();
      Serial.println("pushing data ...");
      pushData(Byte);
    }
  }
  //Serial.println("\nwaiting ..."); 
  delay(50); 
    
}

void getReady(int startByte){
  bitWrite(startByte, 8, 1);
  for(int i=8; i >= 0; i--){
     digitalWrite(Laser, bitRead(startByte,i));
     Serial.print(bitRead(startByte,i), DEC);   
     delay(SPEED);
  }
  Serial.print("\n");
}

void pushData(int Byte){
  
  for(int i=7; i >= 0; i--){
     digitalWrite(Laser, bitRead(Byte,i));
     Serial.print(bitRead(Byte,i), DEC);   
     delay(SPEED);
  }
  Serial.print("\n");
  digitalWrite(Laser,LOW);

}
