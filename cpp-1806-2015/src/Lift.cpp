/*
 * Lift.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */

/* to do list
 * FIND OUT ALL THE PWM PORTS. need to write function def. stubs.
 */
#include <WPIlib.h>
#include <Lift.h>
#include <TDPIDController.h>

Lift::Lift() {
	elevEnc = new Encoder(1,2); //I DONT KNOW THE PORTS
	topLimit = new DigitalInput(1,1); //top limit switch
	elevMotor = new Talon(1,1); //elevator motor
	brake = new DoubleSolenoid(1,2); //double solennoid
	bottomLimit = new DigitalInput(1,1); //bottom limit switch
	int DigitalInput;
	photoSensor = new DigitalInput(1,0); //photo sensor for totes
}


Lift::~Lift() {

}

double Lift::getElevEncDist(){

}

bool Lift::isBrakeEngaged( ) {

}

double Lift::getElevMotorPower(){

}
