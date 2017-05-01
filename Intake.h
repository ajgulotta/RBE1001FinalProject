#include "Servo.h"

class Intake{
private:
		Servo intakeMotor;

public:
		void initialize(int intakePin);
		void collect();
		void eject();
		void halt();
};
