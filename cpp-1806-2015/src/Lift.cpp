/*
 * Lift.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */

/* TODO
 * FIND OUT ALL THE PWM PORTS.
 */

#include <Lift.h>
#include <TDPIDController.h>
#include <WPIlib.h>
Lift::Lift() {
	// TODO Auto-generated constructor stub
	elevEnc = new Encoder(1,2); //I DONT KNOW THE PORTS
	topLimit = new DigitalInput(1,2); //top limit switch
	elevMotor = new Talon(1,2); //elevator motor
	brake = new DoubleSolenoid(1,2); //double solennoid
	bottomLimit = new DigitalInput(1,2); //bottom limit switch
	photoSensor = new DigitalInput(1,2); //photo sensor for totes
}


Lift::~Lift() {

}

