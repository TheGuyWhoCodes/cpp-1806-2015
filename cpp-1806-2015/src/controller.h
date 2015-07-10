

#ifndef IMU_H_
#define IMU_H_

class Controller {
public:
		Joystick stick;    //Joysticks
		TDButton *Button1; //Button A
		TDButton *Button2; //Button B
		TDButton *Button3; //Button X
		TDButton *Button4; //Button Y
		TDButton *Button5; //Left Bumper
		TDButton *Button6; //Right Bumper
		TDButton *Button7; //Back Button
		TDButton *Button8;
		TDButton *Button9; //Start Button
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
};