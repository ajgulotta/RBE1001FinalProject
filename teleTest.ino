#include <DFW.h>
#include <Servo.h>
#include <Robot.h>
#include <Lifter.h>
#include <Intake.h>

int ledpindebug = 13;
DFW dfw(ledpindebug);

void setup(){
	dfw.begin();
	Robot robot = new Robot(4, 5);
	Lifter arm = new Lifter(6, 0);
	Intake intake = new Intake(7);
}

void loop(){
	dfw.run();
	if(dfw.joysticklv() > )
	robot.driveLR(dfw.joysticklv(), dfw.joystickrv());

}