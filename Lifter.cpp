#include "Lifter.h"

void Lifter::initialize(int pinL, int pinR){
	liftMotorL.attach(pinL, 1000, 2000);
	liftMotorR.attach(pinR, 1000, 2000);
}

void Lifter::liftUp(int speed){
	liftMotorL.write(90 - speed);
	liftMotorR.write(90 + speed);
}

void Lifter::liftDown(int speed){
	liftMotorL.write(90 + speed);
	liftMotorR.write(90 - speed);
}

void Lifter::stop(){
	liftMotorL.write(90);
	liftMotorR.write(90);
}