#include "Servo.h"

class Intake{
private:
		Servo intakeMotor;

public:
		void Intake(int intakePin);
		//void initialize(int intakePin);
		void collect();
		void eject();
		void stop();
}