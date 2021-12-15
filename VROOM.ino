#include<DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
void setup(){
  int INP_B1=2;
  int INP_B2=4;
  int EN_B=6;
  int INP_A1=12;
  int INP_A2=14;
  int EN_A=16;

  int Speed0=0;
  int Speed1=37;
  int Speed2=74;
  int Speed3=111;
  int Speed4=148;
  int Speed5=185;
  int Speed6=222;
  int Speed7=255;

  Serial.begin(9600);
  Dabble.begin("VROOM");


  pinMode(EN_A, OUTPUT);  // EN A1
  pinMode(INP_A1, OUTPUT);  // INP A1
  pinMode(6, OUTPUT); // INP A1

  pinMode(15,OUTPUT); // EN B1
  pinMode(4,OUTPUT);  // IN1 B1
  pinMode(2,OUTPUT);  // IN2 B1
}

void loop() {
  int INP_B1=2;
  int INP_B2=4;
  int EN_B=6;
  int INP_A1=12;
  int INP_A2=14;
  int EN_A=16;

  Dabble.processInput();
  int xval = GamePad.getXaxisData();
  int yval = GamePad.getYaxisData();
  
  if(yval>0 && xval < 4 && xval > -4){
    analogWrite(EN_A, speed0); 
    digitalWrite(INP_A1, LOW);
    digitalWrite(INP_A2, HIGH);
    
    analogWrite(EN_B, speed0); 
    digitalWrite(INP_B̥1, LOW);
    digitalWrite(INP_A2, HIGH);

    }
  else if(yval<0 && xval < 4 && xval > -4){
        analogWrite(2, speed0);
     
      }
    }
  else if(yval<0 && xval < 4 && xval > -4){
    analogWrite(2, speed0);;
     
  }
  else if(yval<0 && xval < 4 && xval > -4){
    analogWrite(2, speed0);
     
  }
  else if(xval>0 && yval < 4 && yval > -4){
      analogWrite(2, speed0);

    }
  else if(xval<0 && yval < 4 && yval > -4){
      analogWrite(2, speed0);
    }
  else{
      analogWrite(2, speed0);
 
    }
}