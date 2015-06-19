/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "TDPIDController.h"
#include "Notifier.h"
#include "PIDSource.h"
#include "PIDOutput.h"
#include <math.h>

/**
 * Allocate a PID object with the given constants for P, I, D
 * @param Kp the proportional coefficient
 * @param Ki the integral coefficient
 * @param Kd the derivative coefficient
 * @param source The PIDSource object that is used to get values
 * @param output The PIDOutput object that is set to the output value
 * @param period the loop time for doing calculations. This particularly effects calculations of the
 * integral and differental terms. The default is 50ms.
 */
TDPIDController::TDPIDController(float Kp, float Ki, float Kd,
								PIDSource *source, PIDOutput *output,
								float period)
{
	//m_semaphore = semBCreate(SEM_Q_PRIORITY, SEM_FULL);

	m_controlLoop = new Notifier(TDPIDController::CallCalculate, this);
	
	m_onTarget = 0;
    m_error = 0;
	
	m_P = Kp;
	m_I = Ki;
	m_D = Kd;
	m_maximumOutput = 1.0;
	m_minimumOutput = -1.0;
	
	m_maximumInput = 0;
	m_minimumInput = 0;
	
	m_continuous = false;
	m_enabled = false;
	m_setpoint = 0;

	m_prevError = 0;
	m_totalError = 0;
	m_tolerance = .05;

	m_result = 0;
	m_minMotorLimitPOS = 0;
	m_minMotorLimitNEG = 0;
	
	m_deadband = 0;
	
	m_pidInput = source;
	m_pidOutput = output;
	m_period = period;
	
	m_timeToStopMotion = 1.0;
	printEnabled = 0;
	m_controlLoop->StartPeriodic(m_period);
}

/**
 * Free the PID object
 */
TDPIDController::~TDPIDController()
{
	//semFlush(m_semaphore);
	delete m_controlLoop;
}

/**
 * Call the Calculate method as a non-static method. This avoids having to prepend
 * all local variables in that method with the class pointer. This way the "this"
 * pointer will be set up and class variables can be called more easily.
 * This method is static and called by the Notifier class.
 * @param controller the address of the PID controller object to use in the background loop
 */
void TDPIDController::CallCalculate(void *controller)
{
	TDPIDController *control = (TDPIDController*) controller;
	control->Calculate();
}

 /**
  * Read the input, calculate the output accordingly, and write to the output.
  * This should only be called by the Notifier indirectly through CallCalculate
  * and is created during initialization.
  */	
void TDPIDController::Calculate()
{

	if (m_pidInput == 0)
		return;
	if (m_pidOutput == 0)
		return;
	float input = m_pidInput->PIDGet();
	
	if (m_enabled)
	{
		m_error = m_setpoint - input;
		if (m_continuous)
		{
			if (fabs(m_error) > 
				(m_maximumInput - m_minimumInput) / 2)
			{
				if (m_error > 0)
					m_error = m_error  - m_maximumInput + m_minimumInput;
				else
					m_error = m_error  +
					m_maximumInput - m_minimumInput;
			}
		}

		if (((m_totalError + m_error) * m_I < m_maximumOutput) &&
				((m_totalError + m_error) * m_I > m_minimumOutput))
			m_totalError += m_error;

				
		m_result = m_P * m_error + m_I * m_totalError + m_D * (m_error - m_prevError);
		m_prevError = m_error;
		
		if (m_result > m_maximumOutput)
			m_result = m_maximumOutput;
		else if (m_result < m_minimumOutput)
			m_result = m_minimumOutput;
		
				
		if (fabs(m_error)< 1.0)		// If the error is less than one count
			m_onTarget=true;		// The target has been reached..
		if (fabs(m_error)> m_deadband)
			m_onTarget=false;		// A new target was given
		
		if (fabs(m_error)<m_deadband) // if the position is less than the deadband
		{					
			m_result = 0;							// Disable the motors output
		}
		
		if (m_minMotorLimitPOS>0.00){					// Added this specifically to address issues with the ARM at ST Louis
			if (m_result > 0.0 && m_result < m_minMotorLimitPOS)
					m_result = m_minMotorLimitPOS;
		}
		
		if (m_minMotorLimitNEG<0.00){					// Added this specifically to address issues with the ARM at ST Louis
			if (m_result < 0.0 && m_result > m_minMotorLimitNEG)
					m_result = m_minMotorLimitNEG;
		}
		
		m_pidOutput->PIDWrite(m_result);
		
		if (printEnabled)
			printf("input %f setpt %f err %f motor %f onTarget %d\r\n",input, m_setpoint, m_error, m_result,m_onTarget);
	}
	else
	{
		if (printEnabled && reEnableTimer.Get() > 0.001)
			printf("waiting for timer  %f  > %f\r\n", reEnableTimer.Get(),m_timeToStopMotion);
		
		if(reEnableTimer.Get() > m_timeToStopMotion){
			if (printEnabled)
				printf("Resync COMPLETED\r\n");
			
			reEnableTimer.Stop();				// Stop the timer, reset to 0 seconds
			reEnableTimer.Reset();
			m_setpoint = m_pidInput->PIDGet();	// Syncronize the PID controller with position
			if (printEnabled)
				printf("new setpoint is %f",m_setpoint);
			
			m_prevError = 0;					// Reset PID controller vars
			m_totalError = 0;
			m_result = 0;
			m_enabled = true;					// RE-Enable PID Controller
		}
	
	}

}

/**
 * Set the PID Controller gain parameters.
 * Set the proportional, integral, and differential coefficients.
 * @param p Proportional coefficient
 * @param i Integral coefficient
 * @param d Differential coefficient
 */
void TDPIDController::SetPID(float p, float i, float d)
{

		m_P = p;
		m_I = i;
		m_D = d;

}

/**
 * Get the Proportional coefficient
 * @return proportional coefficient
 */
float TDPIDController::GetP()
{

		return m_P;

}

/**
 * Get the Integral coefficient
 * @return integral coefficient
 */
float TDPIDController::GetI()
{

		return m_I;

}

/**
 * Get the Differential coefficient
 * @return differential coefficient
 */
float TDPIDController::GetD()
{

		return m_D;

}

/**
 * Return the current PID result
 * This is always centered on zero and constrained the the max and min outs
 * @return the latest calculated output
 */
float TDPIDController::Get()
{
	float result;

		result = m_result;

	return result;
}

void TDPIDController::SetDeadband(float db){
	m_deadband = db;
}

/**
 *  Set the PID controller to consider the input to be continuous,
 *  Rather then using the max and min in as constraints, it considers them to
 *  be the same point and automatically calculates the shortest route to
 *  the setpoint.
 * @param continuous Set to true turns on continuous, false turns off continuous
 */
void TDPIDController::SetContinuous(bool continuous)
{

		m_continuous = continuous;


}

/**
 * Sets the maximum and minimum values expected from the input.
 * 
 * @param minimumInput the minimum value expected from the input
 * @param maximumInput the maximum value expected from the output
 */
void TDPIDController::SetInputRange(float minimumInput, float maximumInput)
{

		m_minimumInput = minimumInput;
		m_maximumInput = maximumInput;	

	SetSetpoint(m_setpoint);
}

/**
 * Sets the minimum and maximum values to write.
 * 
 * @param minimumOutput the minimum value to write to the output
 * @param maximumOutput the maximum value to write to the output
 */
void TDPIDController::SetOutputRangeMAX(float minimumOutput, float maximumOutput)
{

		m_minimumOutput = minimumOutput;
		m_maximumOutput = maximumOutput;

}
void TDPIDController::SetOutputRangeMIN(float minimumOutput, float maximumOutput)
{

		m_minMotorLimitNEG = minimumOutput;
		m_minMotorLimitPOS = maximumOutput;
		printf("PID SETUP:\n");
		printf(" m_minMotorLimitNEG: %1.2f",m_minMotorLimitNEG);
		printf(" m_minMotorLimitPOS: %1.2f",m_minMotorLimitPOS);

}

/**
 * Set the setpoint for the PIDController
 * @param setpoint the desired setpoint
 */
void TDPIDController::SetSetpoint(float setpoint)
{

		if (m_maximumInput > m_minimumInput) {
			if (setpoint > m_maximumInput)
				m_setpoint = m_maximumInput;
			else if (setpoint < m_minimumInput)
				m_setpoint = m_minimumInput;
			else
				m_setpoint = setpoint;
		}
		else
			m_setpoint = setpoint;

}

/**
 * Returns the current setpoint of the PIDController
 * @return the current setpoint
 */
float TDPIDController::GetSetpoint()
{
	float setpoint;

		setpoint = m_setpoint;

	return setpoint;
}

/**
 * Retruns the current difference of the input from the setpoint
 * @return the current error
 */
float TDPIDController::GetError()
{
	float  error;

		error = m_error;

	return error;
}

/*
 * Set the percentage error which is considered tolerable for use with
 * OnTarget.
 * @param percentage error which is tolerable
 */
void TDPIDController::SetTolerance(float percent)
{

		m_tolerance = percent;

}

/*
 * Return true if the error is within the percentage of the total input range,
 * determined by SetTolerance. This asssumes that the maximum and minimum input
 * were set using SetInput.
 */
bool TDPIDController::OnTarget()
{
	//bool temp;
	//CRITICAL_REGION(m_semaphore)
	//{
	//	temp = (fabs(m_error)<m_tolerance / 100 * 
	//			(m_maximumInput - m_minimumInput));
	//}
	//END_REGION;
	return m_onTarget;
}

/**
 * Begin running the PIDController
 */
void TDPIDController::Enable()
{

		if (printEnabled)
			printf("PID enable funcation was called\r\n");
		m_enabled = true;

}
/**
 * Stop running the PIDController, this sets the output to zero before stopping.
 */
void TDPIDController::Disable()
{


		if(m_enabled){
			if (printEnabled)
				printf("PID disable funcation was called\r\n");
			m_pidOutput->PIDWrite(0);
			m_enabled = false;
		}

}

/**
 * Reset the previous error,, the integral term, and disable the controller.
 */
void TDPIDController::Reset()
{
	Disable();
	

		m_prevError = 0;
		m_totalError = 0;
		m_result = 0;

}

void TDPIDController::ReSnycAtCurrentPosition(float timeToStopMotion)
{

		if (printEnabled)
			printf("RESYNC   RESYNC   RESYNC   RESYNC\r\n");
		if (!m_enabled && reEnableTimer.Get()<0.001)
		{	
			m_pidOutput->PIDWrite(0);			// stop the motor if running
			
			m_timeToStopMotion = timeToStopMotion; // store the time to wait for motion to stop
			
			reEnableTimer.Stop();				// start the timer running
			reEnableTimer.Reset();				// start the timer running
			reEnableTimer.Start();				// start the timer running
		
		}

}

void TDPIDController::OverRideMotorOutput(float value)
{

		//printf("override motor output -> %f\r\n",value);
		m_enabled = false;
		m_pidOutput->PIDWrite(value);

}
void TDPIDController::enableDebug()
{

		printEnabled = true;

}
void TDPIDController::disableDebug()
{

		printEnabled = false;

}

bool TDPIDController::IsEnabled()
{
	if (m_enabled)
	{
		return true;
	}else return false;
}

