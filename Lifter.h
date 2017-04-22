#include "Servo.h"

class Lifter{
private:
		Servo liftMotorL;
		Servo liftMotorR;

public:
		void initialize(int pinL, int pinR);
		void liftUp(int speed);
		void liftDown(int speed);
		void stop();
}