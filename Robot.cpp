#include "Robot.h"

void Robot::Robot(int pinL, int pinR){
	motorL.attach(pinL, 1000, 2000);			//Initializes drivetrain motors
	motorR.attach(pinR, 1000, 2000);
}

/*void Robot::initialize(int pinL, int pinR){
	motorL.attach(pinL, 1000, 2000);			//Initializes drivetrain motors
	motorR.attach(pinR, 1000, 2000);
}*/

void Robot::driveLR(int speedL, int speedR){	//Manual control for running each
	motorL.write(90 + speedL);					//side of the drivetrain at a
	motorR.write(90 - speedR);					//given speed
}

void Robot::drive(int speed){					//Takes in a speed from -90 to 90
	motorL.write(90 + speed);					//and runs both motors at the given
	motorR.write(90 - speed);					//speed in the same direction
}

void Robot::stop(){								//Stops the drivetrain
	motorL.write(90);
	motorR.write(90);
}