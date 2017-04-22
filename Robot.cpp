#include "Robot.h"

void Robot::initialize(int pinL, int pinR){
	motorL.attach(pinL, 1000, 2000);
	motorR.attach(pinR, 1000, 2000);
}

void Robot::driveLR(int speedL, int speedR){
	motorL.write(90 + speedL);
	motorR.write(90 - speedR);
}

void Robot::drive(int speed){
	motorL.write(90 + speed);
	motorR.write(90 - speed);
}

void Robot::stop(){
	motorL.write(90);
	motorR.write(90);
}