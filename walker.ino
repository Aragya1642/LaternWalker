#include <Servo.h>
#include "constants.h"

Servo hipL;
Servo hipR;
Servo kneeL;
Servo kneeR;
Servo ankleL;
Servo ankleR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hipL.attach(9);
  hipR.attach(8);
  kneeL.attach(7);
  kneeR.attach(6);
  ankleL.attach(5);
  ankleR.attach(4);

  hipL.write(hipLOffset);
  kneeL.write(kneeLOffset);
  ankleL.write(ankleLOffset);
  
  hipR.write(hipROffset);
  kneeR.write(kneeROffset);
  ankleR.write(ankleROffset);

  delay(5000);
}

void resetRight(){
  hipR.write(hipROffset);
  kneeR.write(80);
  ankleR.write(ankleROffset);

  delay(50);
}

void resetLeft(){
  hipL.write(hipLOffset);
  kneeL.write(kneeLOffset);
  ankleL.write(ankleLOffset);
  
  delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // move hip right to set up for foot to come down
  for (int i = hipROffset; i < 180; i+=2){
    hipR.write(i);
    delay(20);
  }

  // move knee to be perpendicular to the ground
  for (int i = kneeROffset; i > 160; i-=2){
    kneeR.write(i);
    delay(20);
  }

  // move both hip and knee down to line up again to reset position
  for (int i = 0; i < 12; i++){
    hipR.write(hipR.read() - i);
    kneeR.write(kneeR.read() - i);
    delay(20);
  }
  resetRight();

  // move left knee to be parallel to the ground
  for (int i = kneeLOffset; i > 0; i-=2){
    kneeL.write(i);
    delay(20);
  }

  // move left hip to set up for foot to come down
  for (int i = hipLOffset; i > 0; i-=2){
    hipL.write(i);
    delay(20);
  }

  // move both hip and knee down to line up again to reset position
  for (int i = 0; i < 12; i++){
    hipL.write(hipL.read() + i);
    kneeL.write(kneeL.read() + i);
    delay(20);
  }
  resetLeft();

  
  hipR.write(hipROffset);
  kneeR.write(kneeROffset);
  delay(50);
}
