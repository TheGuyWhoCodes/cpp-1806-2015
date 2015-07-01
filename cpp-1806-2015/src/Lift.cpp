/*
 * Lift.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */

/* to do list
 * made by the owner of chris-a.rocks :))))
 * FIND OUT ALL THE PWM PORTS. need to write function def. stubs.
 */
#include <WPIlib.h>
#include <Lift.h>
#include <TDPIDController.h>

Lift::Lift() {
	elevEnc = new Encoder(1,2); //I DONT KNOW THE PORTS
	elevEnc->SetMinRate(20);
	elevEnc->SetDistancePerPulse(.0212765957);
	topLimit = new DigitalInput(1); //top limit switch
	elevMotor = new Talon(1); //elevator motor
	brake = new DoubleSolenoid(2,1); //double solenoid
	bottomLimit = new DigitalInput(1); //bottom limit switch
	photoSensor = new DigitalInput(1); //photo sensor for totes
}


Lift::~Lift() {

}

double Lift::getElevEncDist(){

	return elevEnc->Get();

}

bool Lift::isBrakeEngaged( ) {



}

double Lift::getElevMotorPower(){

	return elevMotor->Get();

}

bool Lift::isElevStopped() {



}

void setElevMotorPower(float power) {

	elevMotor->Set(power);

}
