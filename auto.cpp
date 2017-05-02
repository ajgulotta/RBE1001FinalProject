#include <DFW.h>
#include "Robot.h"
#include "Lifter.h"
#include "Intake.h"

const int trackerL = 0;
const int trackerR = 1;
const int trackerM = 2;
int cvalue = 700;
boolean flag = true;
boolean firstLine = true;
boolean autoRun = true;

Robot robotB;
Lifter armA;
Intake intakeA;


void autonomous( long time,DFW & dfw) { // function definition

  
  if(flag){
	  robotB.initialize(4, 5);
    armA.initialize(10, 11, 11);
    intakeA.initialize(8);
    pinMode(22, INPUT_PULLUP);
    pinMode(23, INPUT_PULLUP);
    pinMode(24, INPUT_PULLUP);
    //flag = false;
  }


  if(digitalRead(22) == LOW && autoRun){
    while(analogRead(trackerL) > (cvalue - 300) && analogRead(trackerR) > (cvalue - 300)){
      robotB.drive(90);
    }
    robotB.halt();
    armA.moveTo(800);
    robotB.drive(90);
    delay(4000);
    robotB.halt();
    autoRun = false;
  }
  else if(digitalRead(23) == LOW && autoRun){    
    
    if(flag){
      digitalWrite(29, HIGH);
      robotB.drive(90);
      delay(2000);
      robotB.driveLR(150, 150);
      delay(900);
      //while
      while(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue){
        robotB.drive(90);
      }
      delay(200);
      //while
      while(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue){
        robotB.drive(90);
      }
      robotB.halt();
      if(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue){
        //while
        while(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue){
          robotB.driveLR(90, 30);
        }
        
        robotB.halt();
      }
      if(analogRead(trackerL) > cvalue && analogRead(trackerR) < cvalue){
        //while
        while(analogRead(trackerL) > cvalue && analogRead(trackerR) < cvalue){
          robotB.driveLR(150, 90);
        }
        robotB.halt();
      }
      robotB.drive(90);
      delay(220);
      //while
      while(analogRead(trackerM) > cvalue){
        robotB.driveLR(40, 40);
      }
      delay(250);
      robotB.halt();
      digitalWrite(29, LOW);
      flag = false;
    }
    //while
    while(analogRead(trackerR) < cvalue){
      robotB.driveLR(140, 90);
    }
    if(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue){
      digitalWrite(28, HIGH);
      robotB.drive(90);
    }
    else if(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue){
      digitalWrite(28, LOW);
      digitalWrite(27, HIGH);
      robotB.halt();
      robotB.drive(-15);
      armA.moveTo(460);
      delay(1000);
      robotB.halt();
      robotB.driveLR(10, 80);
      delay(1000);
      robotB.drive(80);
      delay(1000);
      robotB.halt();
      digitalWrite(27, LOW);
      digitalWrite(26, HIGH);
      intakeA.eject();
      delay(3000);
      intakeA.halt();
//      robotB.drive(-30);
//      delay(3000);
//      robotB.halt();
//      armA.moveTo(900);
//      digitalWrite(26, LOW);
      robotB.halt();
      autoRun = false;
    }
  else{
    robotB.halt();
  }
  //delay(100);
  
}
  else if(digitalRead(24) == LOW){
      if(time > 15000){
        robotB.drive(50);
      }
      if(time < 15000 && time > 10000){
        robotB.driveLR(140, 140);
      }
      if(time < 10000){
        robotB.drive(90);
      }
      if(time < 1000){
        robotB.halt();
      }
    }
  }
