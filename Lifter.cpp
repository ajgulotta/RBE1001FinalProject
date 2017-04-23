#include "Lifter.h"
#include "Arduino.h"

Lifter::Lifter(){}

void Lifter::initialize(int pinL, int pinR, int liftPotPin){
	liftMotorL.attach(pinL, 1000, 2000);			//Initializes motors
	liftMotorR.attach(pinR, 1000, 2000);
	potPin = liftPotPin;							//Assigns potentiometr pin
	potPos = analogRead(potPin);					//Updates initial pot position
}

void Lifter::moveTo(int position){							//Moves lifter to given pot position
	potPos = analogRead(potPin);
	if(potPos < position){							//Starting below target position
		while(potPos < (position - 10)){			//Moves lifter
			potPos = analogRead(potPin);
			liftUp(90);
		}
		stop();
		while(potPos > (position + 10)){			//Corrects in case of overshoot
			potPos = analogRead(potPin);
			liftDown(90);
		}
		stop();
	}
	else if(potPos > position){						//Starting above target position
		while(potPos > (position + 10)){			//Moves lifter
			potPos = analogRead(potPin);
			liftDown(90);
		}
		stop();
		while(potPos < (position - 10)){			//Corrects in case of overshoot
			potPos = analogRead(potPin);
			liftUp(90);
		}
		stop();
	}
}

void Lifter::liftUp(int speed){						//Moves lifter up at given speed
	liftMotorL.write(90 - speed);
	liftMotorR.write(90 + speed);
}

void Lifter::liftDown(int speed){					//Moves lifter down at given speed
	liftMotorL.write(90 + speed);
	liftMotorR.write(90 - speed);
}

void Lifter::stop(){								//Stops lifter
	liftMotorL.write(90);
	liftMotorR.write(90);
}