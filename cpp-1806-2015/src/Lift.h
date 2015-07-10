/*
 * Lift.h
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */
#include <WPIlib.h>
#ifndef SRC_LIFT_H_
#define SRC_LIFT_H_

class Lift {
public:
	Lift();
	double getElevEncDist(); 	//Elevator Encoder
	bool isBrakeEngaged(); 	//Brake on or off
	double getElevMotorPower();   //What percentage of power
	bool isElevStopped(); //Is there elevator stopped?
	void setElevMotorPower(); //Setting the Elevator motor power. i think i set it up wrong whoops
	void liftdrive(); //This is what actually drives the lift up and down

	virtual ~Lift();
private:
	Encoder *elevEnc; //elev encoder bb
	DigitalInput *topLimit; //top limit switch
	Talon *elevMotor; //THE MOTOR :))))
	DoubleSolenoid *brake;  //BRAKE TO STOP THE LIFT
	DigitalInput *bottomLimit; // bottom limit switch
	DigitalInput *photoSensor; //tote photosensor


};


#endif /* SRC_LIFT_H_ */
