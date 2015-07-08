//basic C++ libs
#include <iostream> //file io
#include "math.h"
//Basic Robot Functions
#include "wpilib.h"
//Driven's Button Code
#include "TDButton.h"
//Driven's PID Controller
#include "TDPIDController.h"
//RobotSubsytem Classes
#include "Drive.h"
#include "Stax.h" // ties Lift class and Arm class together

class Robot: public IterativeRobot
{

private:
	LiveWindow *lw;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		Drive::arcadeDrive(stick);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
