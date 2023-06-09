#include <AccelStepper.h>

#define m1Pulse  24
#define m1Dir  26
#define m1Reduc 10    
#define m1MicStep 4

#define m2Pulse  28   
#define m2Dir  30
#define m2Reduc 50    
#define m2MicStep 4

#define degPerStep 1.8 

#define MotorInterface 1

AccelStepper stepper1(MotorInterface, m1Pulse, m1Dir);

AccelStepper stepper2(MotorInterface, m2Pulse, m2Dir);



void setup() {
  // put your setup code here, to run once:
    stepper1.setMaxSpeed(1000);
    stepper2.setMaxSpeed(1000);
    stepper1.setAcceleration(500);
    stepper2.setAcceleration(500);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  moveTo(1, 105);
  delay(2000);
  moveTo(2, 70);
  delay(2000);
  moveTo(1, 0);
  delay(2000);
  moveTo(2, 0);
  
}


void moveTo(int mIndex, float deg) {
  if(mIndex == 1){
    stepper1.moveTo(deg/degPerStep * m1Reduc * m1MicStep);
    stepper1.runToPosition();
  }
  if(mIndex == 2){
    stepper2.moveTo(deg/degPerStep * m2Reduc * m2MicStep);
    stepper2.runToPosition();
  }
}
