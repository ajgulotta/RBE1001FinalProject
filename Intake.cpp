#include "Intake.h"

void Intake::Intake(int intakePin){
	intakeMotor.attach(intakePin, 1000, 2000);	//Initializes intake motor
}

/*void Intake::initialize(int intakePin){
	intakeMotor.attach(intakePin, 1000, 2000);	//Initializes intake motor
}*/

void Intake::collect(){							//Intake drum spins in to collect eggs
	intakeMotor.write(180);
}

void Intake::eject(){							//Intake drum spins out to eject eggs
	intakeMotor.write(0);
}

void Intake::stop(){							//Stops intake drum
	intakeMotor.write(90);
}