/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef BSTIMER_H_
#define BSTIMER_H_

#include "HAL/Semaphore.hpp"
#include "Base.h"


/**
 * Timer objects measure accumulated time in seconds.
 * The timer object functions like a stopwatch. It can be started, stopped, and cleared. When the
 * timer is running its value counts up in seconds. When stopped, the timer holds the current
 * value. The implementation simply records the time when started and subtracts the current time
 * whenever the value is requested.
 */
class BSTimer
{
public:
	BSTimer();
	virtual ~BSTimer();
	double Get();
	void Reset();
	void Start();
	void Stop();
	bool HasPeriodPassed(double period);

	static double GetFPGATimestamp();
	static double GetPPCTimestamp();

private:
	double m_startTime;
	double m_accumulatedTime;
	bool m_running;
	MUTEX_ID m_semaphore;
	DISALLOW_COPY_AND_ASSIGN(BSTimer);
};

#endif
