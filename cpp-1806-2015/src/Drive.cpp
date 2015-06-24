/*
 * Drive.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */

#include <Drive.h>
#include <TDPIDController.h>
#include <wpilib.h>

Drive::Drive() {
	// TODO Auto-generated constructor stub
	leftEnc = new Encoder(1,2);
	rightEnc = new Encoder(3,4);
	rDrive = new Talon(1);
	lDrive = new Talon(2);
	gyro = new Gyro(0);
}

Drive::~Drive() {
	// TODO Auto-generated destructor stub
}

double Drive::getEncDistance(Encoder* encoder){
	//reads the encoder distance (in inches)
	return encoder->GetDistance();
}

void Drive::resetEnc(Encoder* encoder){

}

void Drive::setSpeed(Talon* motor, int speed){

}

double Drive::getSpeed(Talon* motor){

}

double Drive::getGyroAngle(){

}

void Drive::arcadeDrive(Joystick stick){

}
