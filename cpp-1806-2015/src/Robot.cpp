//basic C++ libs
#include "math.h"
//Basic Robot Functions
#include "WPIlib.h"
//Driven's Button Code
#include "TDButton.h"
//Driven's PID Controller
#include "TDPIDController.h"
//RobotSubsytem Classes
#include "Drive.h"
#include "Stax.h" // ties Lift class and Arm class together
#include "Arms.h"
#include <sstream>


class Robot: public SampleRobot
{

private:
	LiveWindow *lw;
	void Autonomous(){


	}

	void OperatorControl(){
		while (IsOperatorControl() && IsEnabled()){
			Drive::arcadeDrive();
		}

	}

	void Test() {


	}
}

START_ROBOT_CLASS(Robot);
