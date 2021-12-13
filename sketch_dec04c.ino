#include<DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
void setup(){
  int INP_B1=2;
  int INP_B2=4;
  int ENB=15;
  Serial.begin(9600);
  Dabble.begin("IRON_MAN");
  pinMode(15,OUTPUT); // EN B
  pinMode(4,OUTPUT);  
  pinMode(2,OUTPUT);
  pinMode(18,OUTPUT);  
  pinMode(19,OUTPUT);
}

void loop() {
  Dabble.processInput();
  int xval = GamePad.getXaxisData();
  int yval = GamePad.getYaxisData();
  
  if(yval>0 && xval < 4 && xval > -4){
    digitalWrite(2, HIGH); 
    digitalWrite(4, LOW);
    digitalWrite(15, HIGH);
    Serial.println("Forward");
    Serial.println();
    Serial.print(xval);
    Serial.print(yval);
    }
  else if(yval<0 && xval < 4 && xval > -4){
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH); 
    digitalWrite(15, HIGH);
    Serial.println("Backward");
    Serial.println();
    Serial.print(xval);
    Serial.print(yval);
    }
  else if(xval>0 && yval < 4 && yval > -4){
    digitalWrite(2, HIGH); 
    digitalWrite(4, LOW);
    digitalWrite(15, HIGH);
    Serial.println("Right");
    Serial.println();
    Serial.print(xval);
    Serial.print(yval);
    }
  else if(xval<0 && yval < 4 && yval > -4){
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH); 
    digitalWrite(15, HIGH);
    Serial.println("Left");
    Serial.println();
    Serial.print(xval);
    Serial.print(yval);
    }
  else{
    digitalWrite(4, LOW); 
    digitalWrite(2, LOW);
    digitalWrite(15, LOW);
    Serial.println("Stop");
    Serial.println();
    Serial.print(xval);
    Serial.print(yval);
    }
}
