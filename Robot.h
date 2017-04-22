#include "Servo.h"

class Robot{
private:
		Servo motorL;
		Servo motorR;

public:
		void initialize(int pinL, int pinR);
		void driveLR(int speedL, int speedR);
		void drive(int speed);
		void stop();
}