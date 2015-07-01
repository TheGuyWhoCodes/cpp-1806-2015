/*
 * Stax.h
 *
 *  Created on: Jun 21, 2015
 *      Author: Jason
 */
#include "WPILib.h"
#include <Lift.h>
#include <Arms.h>

#ifndef SRC_STAX_H_
#define SRC_STAX_H_

class Stax {
public:
	double SECOND_STAGE_ENC_VALUE = 13.9; //Pretty self-explanatory
	double PAUSED_ENC_VALUE = 3.5; //The intermediate value for the elevator's interrupted stage

	Stax();
	virtual ~Stax();

	void goTo(double encValue, bool slow=false); // This sends the elevator to a location on the elevator.
	bool isRested(); //checks to see if the elevator is at rest
	void selectMode( );
	/* I think that this is the function that will
	 * change the mode that we are in based on joystick inputs and completion of different
	 * processes.
	 */
	int getMode();
	void pickUpTote();
	/* This is the process of picking up the tote from the ground to the second stage
	 * I hope that this process is so much smoother than the LabVIEW version
	 *
	 */
	void dropTotes(); //previously known as the DROP SEQUENCE :D
	void setIntakeSpeed(Talon motor, int Speed);
	void getIntakeSpeed();
private:
	enum mode {
		autoCollect,
		manualMode,
		reset,
		pauseFunction
	};	//This enum is to determine the current state of things with the robot.
	bool goingUp; //checks to see if the elevator is going up
	int intakeSpeed;


};

#endif /* SRC_STAX_H_ */
