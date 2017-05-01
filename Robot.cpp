#include "Robot.h"


void Robot::initialize(int pinL, int pinR){
	motorL.attach(pinL, 1000, 2000);			//Initializes drivetrain motors
	motorR.attach(pinR, 1000, 2000);
}

void Robot::driveLR(int speedL, int speedR){	//Manual control for running each
	motorL.write(speedL);					//side of the drivetrain at a
	motorR.write(speedR);					//given speed
}

void Robot::drive(int speed){					//Takes in a speed from -90 to 90
	motorL.write(90 + speed);					//and runs both motors at the given
	motorR.write(90 - speed);					//speed in the same direction
}

void Robot::driveL(int speed){
  motorL.write(90 + speed);
}

void Robot::driveR(int speed){
  motorR.write(90 - speed);
}

void Robot::turnLeft(){           //Turns 90 degrees left
  motorL.write(0);
  motorR.write(0);
  //delay(2000);
}

void Robot::turnRight(){          //Turns 90 degrees right
  motorL.write(180);
  motorR.write(180);
  //delay(2000);
}

void Robot::halt(void){								//Stops the drivetrain
	motorL.write(90);
	motorR.write(90);
}

Servo Robot::getLeftMotor(){
  return motorL;
}


Servo Robot::getRightMotor(){
  return motorR;
}



