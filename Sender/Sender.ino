
#define Laser 12
#define SPEED 2

void setup() {
  pinMode(Laser, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("get ready ...");
  getReady(); 
  Serial.println("\n pushing data ...");
  pushData(0b10010101, 8);
  Serial.println(" \n waiting ..."); 
  delay(4000); 
    
}

void getReady(){
  int wake = 0b10101101;
  for(int i=7; i >= 0; i--){
     digitalWrite(Laser, bitRead(wake,i));
     Serial.print(bitRead(wake,i), DEC);   
     delay(SPEED);
  }
}

void pushData(int frame, int frameSize){
  
  for(int i=frameSize-1; i >= 0; i--){
     digitalWrite(Laser, bitRead(frame,i));
     Serial.print(bitRead(frame,i), DEC);   
     delay(SPEED);
  }
  digitalWrite(Laser,LOW);

}
