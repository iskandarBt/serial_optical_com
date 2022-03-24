
#define SPEED 2

int i = 0;
int wake = 0b10101101;
void setup() {
  Serial.begin(9600);
}

void loop() {
  bool match = false;
  if(digitalRead(A5)==HIGH){
    delay(1);
    match = checkSender();
    Serial.println(match ? "true" : "false");
  }
  if(match){
    readData(8);
  }
}

bool checkSender(){
  bool match = false;
  
  for(int i=7; i>=0; i--){
    if(digitalRead(A5) == bitRead(wake,i)){
      Serial.print(digitalRead(A5)); // for debug
      match = true;
    }
    else{
      match =false;
      return match;
    }
    
    delay(SPEED);
  }
  Serial.println(" ");
  return match;
  
}

void readData(int frameSize){
  for(int i=0; i <= frameSize-1; i++){
    Serial.print(digitalRead(A5));
    delay(SPEED);  
  }
  Serial.println(" ");
}
