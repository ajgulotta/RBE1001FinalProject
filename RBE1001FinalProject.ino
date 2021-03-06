/* This is the RBE 1001 Template as of
 *
 * 3/28/17
 *
 * This Template
 * is designed to run the autonomous and teleop sections of the final
 * competition. Write and test your autonomous and teleop code on your
 * own and place the code in auto.cpp or teleop.cpp respectively.
 * The functions will be called by the competition framework based on the
 * time and start button. DO NOT change this file, your code will be called
 * by the framework. The framework will pass your code a reference to the DFW
 * object as well as the amount of MS remaining.
 */
#include <DFW.h>
#include "Robot.h"
#include "Lifter.h"
#include "Intake.h"

//Robot robotB;
int ledpindebug = 13; //Wireless controller Debug pin. If lit then there is no communication.
DFW dfw(ledpindebug, autonomous, teleop); // Instantiates the DFW object and setting the debug pin. 
                                          //The debug pin will be set high if no communication is 
                                          //seen after 2 seconds

void setup() {
	Serial.begin(9600); // Serial output begin. Only needed for debug
	dfw.begin(); // Serial1 output begin for DFW library. Buad and port #."Serial1 only"
  //robotB.initialize(4, 5);
}
void loop() {
	dfw.run();
}

void robotShutDown(void){
  //robotB.halt();
}

Robot getRobot(){
  //return robotB;
}

