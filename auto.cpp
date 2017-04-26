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

Robot robotA;
Lifter armA;
Intake intakeA;


void autonomous( long time,DFW & dfw) { // function definition
	Serial.print("\r\nAuto time remaining: ");
	Serial.print(time);


  Serial.println("auto test");

  
  if(flag){
	  robotA.initialize(4, 5);
    armA.initialize(6, 7, 11);
    intakeA.initialize(8);
    //flag = false;
  }

/*
  if(digitalRead(22) == LOW){
      if(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue){
        robotA.drive(30);
      }
      else if(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue && analogRead(trackerM) < cvalue){
        robotA.turnLeft();
        delay(2000);
      }
      else if(analogRead(trackerL) > cvalue && analogRead(trackerR) < cvalue && analogRead(trackerM) < cvalue){
        robotA.turnRight();
        delay(2000);
      }
      else if(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue){
        robotA.driveLR(100, 20);
      }
      else if(analogRead(trackerL) > cvalue && analogRead(trackerR) < cvalue){
        robotA.driveLR(110, 90);
      }
      else if(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue && analogRead(trackerM) > cvalue){
        robotA.drive(90);
        delay(3000);
        robotA.halt();
        exit(0);
      }

      if(time > 15000){
        robotA.drive(50);
      }
      if(time < 15000 && time > 10000){
        robotA.driveLR(140, 140);
      }
      if(time < 10000){
        robotA.drive(90);
      }
  }
  else if(digitalRead(23) == LOW){*/
  
//      if(time > 15000){
//        robotA.getRightMotor().write(0);
//        robotA.getLeftMotor().write(180);
//      }
//      else {
//        robotA.getRightMotor().write(90);
//        robotA.getLeftMotor().write(90);
//      }
//      else if(time < 15000 && time > 10000){
//        robotA.getRightMotor().write(0);
//        robotA.getLeftMotor().write(0);
//      }
//      else if(time < 10000){
//        robotA.getRightMotor().write(90);
//        robotA.getLeftMotor().write(90);
//      }
      
    
    
    
    
    /*if(flag){
      digitalWrite(29, HIGH);
      robotA.drive(90);
      delay(4000);
      armA.moveTo(460);
      robotA.driveLR(150, 150);
      delay(1400);
      //while
      if(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue){
        robotA.drive(90);
      }
      delay(300);
      //while
      if(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue){
        robotA.drive(90);
      }
      robotA.halt();
      if(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue){
        //while
        if(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue){
          robotA.driveLR(90, 30);
        }
        
        robotA.halt();
      }
      if(analogRead(trackerL) > cvalue && analogRead(trackerR) < cvalue){
        //while
        if(analogRead(trackerL) > cvalue && analogRead(trackerR) < cvalue){
          robotA.driveLR(150, 90);
        }
        robotA.halt();
      }
      robotA.drive(90);
      delay(900);
      //while
      if(analogRead(trackerM) > cvalue){
        robotA.driveLR(40, 40);
      }
      delay(300);
      robotA.halt();
      digitalWrite(29, LOW);
      flag = false;
    }
    //while
    if(analogRead(trackerR) < cvalue){
      robotA.driveLR(140, 90);
    }
    if(analogRead(trackerL) > cvalue && analogRead(trackerR) > cvalue){
      digitalWrite(28, HIGH);
      robotA.drive(90);
    }
    else if(analogRead(trackerL) < cvalue && analogRead(trackerR) > cvalue){*/
      digitalWrite(28, LOW);
      digitalWrite(27, HIGH);
      robotA.halt();
      robotA.drive(-15);
      //armA.moveTo(460);
      //delay(1000);
      robotA.halt();
      robotA.driveLR(10, 80);
      delay(800);
      robotA.drive(80);
      delay(1500);
      robotA.halt();
      digitalWrite(27, LOW);
      digitalWrite(26, HIGH);
      intakeA.eject();
      delay(3000);
      intakeA.halt();
      robotA.drive(-30);
      delay(3000);
      robotA.halt();
      //armA.moveTo(900);
      digitalWrite(26, LOW);
      robotA.halt();
   // }
  
//  else{
//    robotA.halt();
//  }
  //delay(100);
  
}

