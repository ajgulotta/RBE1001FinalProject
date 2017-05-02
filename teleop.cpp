#include <DFW.h>
#include "Robot.h"
#include "Lifter.h"
#include "Intake.h"

Robot robot;
Lifter arm;
Intake intake;

boolean flagT = true;

void teleop( long time,DFW & dfw) { // function definition
//	Serial.print("\r\nTeleop time remaining: ");
//	Serial.print(time);
//	Serial.print("\tright joystick: ");
//	Serial.print(dfw.joystickrv());
//	Serial.print("\tleft joystick: ");
//	Serial.print(dfw.joysticklv());

  if(setup){
    robot.initialize(4, 5);
    arm.initialize(10, 11, 0);
    intake.initialize(8);
    flagT = false;
  }


  if(dfw.getCompetitionState() != powerup){
    robot.getRightMotor().write(180-dfw.joystickrv());     //DFW.joystick will return 0-180 as an int into rightmotor.write
    robot.getLeftMotor().write(dfw.joysticklv());      //DFW.joystick will return 0-180 as an int into leftmotor.write
  }

  if(dfw.l2()){
    intake.collect();
  }
  if(dfw.l1()){
    intake.eject();
  }
  if(dfw.two()){
    intake.halt();
  }
  if(dfw.one()){
    robot.halt();
  }

  arm.halt();
  if(dfw.up()){
    arm.liftUp(90);
  }
  else if(dfw.down()){
    arm.liftDown(90);
  }
  else{
    arm.halt();
  }
}
