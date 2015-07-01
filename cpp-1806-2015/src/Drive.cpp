/*
 * Drive.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */

#include <Drive.h>
#include <TDPIDController.h>
#include <WPILib.h>

Drive::Drive() {
	// TODO Auto-generated constructor stub
	leftEnc = new Encoder(1,2);
	leftEnc -> SetDistancePerPulse(0.212765957)
	rightEnc = new Encoder(3,4);
	rightEnc -> SetDistancePerPulse(0.212765957)
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
	encoder->Reset();
}

void Drive::setSpeed(Talon* motor, float speed){
	motor->Set(speed);
}

double Drive::getSpeed(Talon* motor){
	return motor->Get();
}

double Drive::getGyroAngle(){
	return GetAngle();
}

void Drive::arcadeDrive(double power, double turn){
	lDrive->Set(power + turn);
	rDrive->Set(power - turn);
}
