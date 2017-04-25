#include "Servo.h"

class Lifter{
private:
		Servo liftMotor;
		int potPin;
		int potPos;

public:
		void Lifter(int pin, int liftPotPin);
		//void initialize(int pinL, int pinR, int liftPotPin);
		void moveTo(int position);
		void liftUp(int speed);
		void liftDown(int speed);
		void stop();
}