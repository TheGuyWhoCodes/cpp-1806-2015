//Basic Robot Functions
#include "WPILib.h"
//Driven's Buton Code
#include "TDButton.h"
//Driven's PID Controller
#include "TDPIDController.h"
//RobotSubsytem Classes
#include "Drive.h"
#include "Lift.h"
#include "Arms.h"
#include "Stax.h" // ties Lift and Arms together

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

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
