/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef TDPIDCONTROLLER_H_
#define TDPIDCONTROLLER_H_

#include "Base.h"
//#include "semLib.h"
#include "Timer.h"

class PIDOutput;
class PIDSource;
class Notifier;

/**
 * Class implements a PID Control Loop.
 * 
 * Creates a separate thread which reads the given PIDSource and takes
 * care of the integral calculations, as well as writing the given
 * PIDOutput
 */
class TDPIDController
{
private:
	float m_P;			// factor for "proportional" control
	float m_I;			// factor for "integral" control
	float m_D;			// factor for "derivative" control
	float m_maximumOutput;	// |maximum output|
	float m_minimumOutput;	// |minimum output|
	float m_maximumInput;		// maximum input - limit setpoint to this
	float m_minimumInput;		// minimum input - limit setpoint to this
	bool m_continuous;	// do the endpoints wrap around? eg. Absolute encoder
	bool m_enabled; 			//is the pid controller enabled
	float m_prevError;	// the prior sensor input (used to compute velocity)
	double m_totalError; //the sum of the errors for use in the integral calc
	float m_tolerance;	//the percetage error that is considered on target
	float m_setpoint;
	float m_error;
	float m_result;
	float m_period;
	
	//SEM_ID m_semaphore;
	
	PIDSource *m_pidInput;
	PIDOutput *m_pidOutput;
	Notifier *m_controlLoop;
	
	float m_minMotorLimitPOS;
	float m_minMotorLimitNEG;
	float m_deadband;
	bool m_onTarget;
	
	bool printEnabled;
	float m_timeToStopMotion;
	Timer reEnableTimer;

	static void CallCalculate(void *controller);
	void Calculate();
	DISALLOW_COPY_AND_ASSIGN(TDPIDController);
public:
	TDPIDController(float p, float i, float d,
					PIDSource *source, PIDOutput *output,
					float period = 0.05);
	~TDPIDController();
	bool IsEnabled();
	float Get();
	void SetContinuous(bool continuous = true);
	void SetInputRange(float minimumInput, float maximumInput);
	void SetOutputRangeMAX(float mimimumOutput, float maximumOutput);
	void SetOutputRangeMIN(float mimimumOutput, float maximumOutput);
	void SetPID(float p, float i, float d);
	void SetDeadband(float db);
	float GetP();
	float GetI();
	float GetD();
	
	void SetSetpoint(float setpoint);
	float GetSetpoint();

	float GetError();
	
	void SetTolerance(float percent);
	bool OnTarget();
	
	void Enable();
	void Disable();
	
	void Reset();
	
	void ReSnycAtCurrentPosition(float timeToStopMotion);
	void OverRideMotorOutput(float value);
	
	void enableDebug();
	void disableDebug();
};

#endif
