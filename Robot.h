#include "Servo.h"

class Robot{
private:
		Servo motorL;
		Servo motorR;

public:
		void initialize(int pinL, int pinR);
		void driveLR(int speedL, int speedR);
		void drive(int speed);
    void driveL(int);
    void driveR(int);
		void turnLeft();
    void turnRight();
		void halt();
    Servo getLeftMotor();
    Servo getRightMotor();
};
