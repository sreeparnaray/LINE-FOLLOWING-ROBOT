//LINE FOLLOWER ROBOT
//--Sreeparna Ray

#include <AFMotor.h>

//defining pins and variables
#define left A0
#define right A1

//defining motors
AF_DCMotor motor1(3, MOTOR12_1KHZ); 
AF_DCMotor motor2(4, MOTOR12_1KHZ);




void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){

  //line detected by both
  if(!analogRead(left)<=1000 && !analogRead(right)<=1000){
    //Forward
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    
  }
  //line detected by left sensor
  else if(!analogRead(left)<=1000 && analogRead(right)<=1000){
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    
  }
  //line detected by right sensor
  else if(analogRead(left)<=1000 && !analogRead(right)<=1000){
    //turn right
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    
   
  }
  //line detected by none
  else if(analogRead(left)<=1000 && analogRead(right)<=1000){
    //stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    
   
  }
  
}
