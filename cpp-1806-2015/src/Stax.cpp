/*
 * Stax.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: Jason
 */

#include "Stax.h"
#include "Lift.h"
#include "Arms.h"
#include "WPILib.h"

Stax::Stax() {
	// TODO Auto-generated constructor stub

}

Stax::~Stax() {
	// TODO Auto-generated destructor stub
}

void goTo(double encValue, bool Slow){
	while (!isRested()){
		/*
		 * insert the PID code here for the elevator. I know, right.
		 * This sounds like a lot
		 *
		 * it is
		 * 10/10
		 *
		 * I can make Arduino write his own PID
		 */
	}
}

bool isRested(){
	/*
	 * This function checks
	 * 1. The Velocity of the Elevator
	 * 2. The Acceleration of the Elevator
	 *
	 */
	return true;
}

void selectMode(){
	/*
	 * I was thinking that this would be a whole bunch of
	 * if statements that determine what mode the elevator
	 * will be in.
	 */
}

int getMode(){
	return Stax::currentMode;
}

void pickUpTote(){
	/*
	 * This is going to be a rough function right here.
	 * But It will encompass the process of picking
	 * up the totes from the floor to the second stage.
	 * It will be a state machine tho!
	 */
}

void dropTotes(){
	/*
	 * Another state machine
	 * This one will INTERUPT the function pickUpTote()
	 * Just like in the old code
	 */
}

void setIntakeSpeed(Talon motor, int speed){
	if((speed>100)||(speed<100)){
		motor->Set(speed); //Ask Dillon. This needs help
	}
	else {
		printf("Intake Speed Invalid"); //look this function up. cplusplus.com isn't helping
	}
}

void goingUp(){

}
