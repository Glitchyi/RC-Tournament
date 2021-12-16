#include<DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
int INP_B1=2;
int INP_B2=4;
int EN_B=6;
int INP_A1=12;
int INP_A2=14;
int EN_A=16;



void setup(){


  Serial.begin(9600);
  Dabble.begin("VROOM");


  pinMode(EN_A, OUTPUT);  // EN A1
  pinMode(INP_A1, OUTPUT);  // INP A1
  pinMode(INP_A2, OUTPUT); // INP A1
  ledcAttachPin(EN_A,0);
  ledcSetup(0,5000,8);
  
  pinMode(EN_B,OUTPUT); // EN B1
  pinMode(INP_B1,OUTPUT);  // IN1 B1
  pinMode(INP_B2,OUTPUT);  // IN2 B1
  ledcAttachPin(EN_B,1);
  ledcSetup(1,5000,8);
}

void loop() {
  int speed=36;
  
  Dabble.processInput();
  int xval = GamePad.getXaxisData(); // get x-axis data
  int yval = GamePad.getYaxisData(); // get y-axis data
  
 
  
  if (GamePad.isTrianglePressed()){ // TURN LEFT
    
    ledcWrite(0, speed*7);  //for controlling the speed of the motor A
    ledcWrite(1, speed*7);  //for controlling the speed of the motor B
    
    digitalWrite(EN_A, HIGH);  //for controlling the speed of the motor

    digitalWrite(INP_A1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_A2, LOW); 
    
    //digitalWrite(EN_B, HIGH); //for controlling the speed of the motor

    //digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    //digitalWrite(INP_B2, LOW); 
    delay(1000);
  }
   if (yval>0){
    ledcWrite(0, speed*yval);  //for controlling the speed of the motor A
    ledcWrite(1, speed*yval);  //for controlling the speed of the motor B
  }
   if (xval>0){
    ledcWrite(0, speed*xval);  //for controlling the speed of the motor A
    ledcWrite(1, speed*xval);  //for controlling the speed of the motor B
  }

  if(yval==0 && xval < 4 && xval > -4){

    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, LOW); 
    Serial.write("NO");
    digitalWrite(INP_B1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 

  }else if (yval==1 && xval < 4 && xval > -4){
    
    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, HIGH); 
    
    ledcWrite(1, speed1); //for controlling the speed of the motor

    digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 

  }else if (yval==2 && xval < 4 && xval > -4){

    ledcWrite(0, speed2);  //for controlling the speed of the motor

    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, HIGH); 
    
    ledcWrite(1, speed2); //for controlling the speed of the motor

    digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 

  }else if (yval==3 && xval < 4 && xval > -4){

    ledcWrite(0, speed3);  //for controlling the speed of the motor

    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, HIGH); 
    
    ledcWrite(1, speed3); //for controlling the speed of the motor

    digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 

  }else if ((yval==4 && xval < 4 && xval > -4)){

    ledcWrite(0, speed4);  //for controlling the speed of the motor

    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, HIGH); 
    
    ledcWrite(1, speed4); //for controlling the speed of the motor

    digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 

  }else if ((yval==5 && xval < 4 && xval > -4)){

    ledcWrite(0, speed5);  //for controlling the speed of the motor

    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, HIGH); 
    
    ledcWrite(1, speed5); //for controlling the speed of the motor

    digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 

  }else if ((yval==6 && xval < 4 && xval > -4)){

    ledcWrite(0, speed6);  //for controlling the speed of the motor

    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, HIGH); 
    
    ledcWrite(1, speed6); //for controlling the speed of the motor

    digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 

  }else if ((yval==7 && xval < 4 && xval > -4)){

    ledcWrite(0, speed7);  //for controlling the speed of the motor

    digitalWrite(INP_A1, LOW); //for controlling the direction of the motor
    digitalWrite(INP_A2, HIGH); 
    
    ledcWrite(1, speed7); //for controlling the speed of the motor

    digitalWrite(INP_B1, HIGH); //for controlling the direction of the motor
    digitalWrite(INP_B2, LOW); 
  }



}

