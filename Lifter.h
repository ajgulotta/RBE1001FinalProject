#include "Servo.h"

class Lifter{
private:
		Servo liftMotorL;
		Servo liftMotorR;
		int potPin;
		int potPos;

public:
		void initialize(int pinL, int pinR, int liftPotPin);
		void moveTo(int position);
		void liftUp(int speed);
		void liftDown(int speed);
		void stop();
}