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
	leftEnc -> SetDistancePerPulse(0.212765957);
	rightEnc = new Encoder(3,4);
	rightEnc -> SetDistancePerPulse(0.212765957);
	rDrive = new Talon(1);
	lDrive = new Talon(2);
	gyro = new Gyro(0);
	bool slowSpeed = true;

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

void setSlow(bool slow){
	Drive.slowSpeed = slow;
}
void Drive::arcadeDrive(Joystick stick){
	double power = 0;	 //This is the power variable based on the left y axis
	double turn = 0;	 //This is the turn variable based on right x axis
if((stick.GetRawAxis(2) < -.1 )||(stick.GetRawAxis(2) > .1)){ //Deadzone for the left y axis
	power = .45*stick.GetRawAxis(2);
	printf("The Thrust is " + power);
}
else {
	power = 0;
}
if((stick.GetRawAxis(4) < -.1 )||(stick.GetRawAxis(4) > .1)){ //Deadzone for the right x axis
	turn = .45*stick.GetRawAxis(4);
	printf("The Turn is " + turn);
}
else {
	turn = 0;
}

if (Drive.slowSpeed){
	printf("Speed is slowed");
	power = power*.45/.75;
	turn = turn*.45/.75;
}
rDrive = (power - turn);
lDrive = (power + turn);
}
}
