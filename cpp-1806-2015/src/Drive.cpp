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
	Joystick stick;
	TDButton *Button1;
	TDButton *Button2;
	TDButton *Button3;
	/*
	 * Button A: 1
	 * Button B: 2
	 * Button X: 3
	 * Button Y: 4
	 * Left Bumper: 5
	 * Right Bumper: 6
	 * Left Trigger Range: 0-1
	 * Right Trigger Range: 0-(-1)
	 * Button Back 7
	 * Button Start: 9
	 *
	 * Left X: 1
	 * Left Y: 2
	 * Right X: 4
	 * Right Y: 5
	 * Courtesy of: gist.github.com :D
	 */
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

void Drive::setSpeed(Talon* motor, int speed){
	motor->Set(speed);
}

double Drive::getSpeed(Talon* motor){
	return motor->Get();
}

double Drive::getGyroAngle(){
	return gyro->GetAngle();
}

void Drive::arcadeDrive(Joystick stick){
	rDrive->Set(stick.GetRawAxis(2)-stick.GetRawAxis(4));
	lDrive->Set(stick.GetRawAxis(2)+stick.GetRawAxis(4));
}
