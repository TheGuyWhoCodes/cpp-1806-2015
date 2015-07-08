/*
 * Drive.h
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */
#ifndef SRC_DRIVE_H_
#define SRC_DRIVE_H_
#include <WPILib.h>

class Drive {
public:
	Drive();
	virtual ~Drive()
	Joystick stick;
	double getEncDistance(Encoder* encoder);		//reads where the encoder is rn
	void resetEnc(Encoder* encoder);				//resets the encoder values
	void setSpeed(Talon* motor, int speed);		//sets the speed for a motor
	double getSpeed(Talon* motor);				//returns the speed of motor
	double getGyroAngle();						//returns value of gryo angle
	void arcadeDrive(Joystick stick);					//the function that will actually drive


private:
	Encoder* leftEnc;
	Encoder* rightEnc;
	Talon* rDrive;
	Talon* lDrive;
	Gyro* gyro;
};

#endif /* SRC_DRIVE_H_ */
