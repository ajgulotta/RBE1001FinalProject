#include <DFW.h>
#include "Robot.h"
#include "Lifter.h"
#include "Intake.h"

Robot robot;
Lifter arm;
Intake intake;

boolean flag = true;

void teleop( long time,DFW & dfw) { // function definition
	Serial.print("\r\nTeleop time remaining: ");
	Serial.print(time);
	Serial.print("\tright joystick: ");
	Serial.print(dfw.joystickrv());
	Serial.print("\tleft joystick: ");
	Serial.print(dfw.joysticklv());

  if(setup){
    robot.initialize(4, 5);
    arm.initialize(6, 7, 0);
    intake.initialize(8);
    flag = false;
  }

  
  dfw.run();

  robot.driveLR(dfw.joysticklv(), 180 - dfw.joystickrv());

  if(dfw.l2()){
    intake.collect();
  }
  if(dfw.l1()){
    intake.eject();
  }
  if(dfw.two()){
    intake.halt();
  }

  arm.halt();
  if(dfw.up()){
    arm.liftUp(50);
  }
  else if(dfw.down()){
    arm.liftDown(50);
  }
  else{
    arm.halt();
  }
}
