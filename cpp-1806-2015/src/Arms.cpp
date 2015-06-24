/*
 * Arms.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */

#include <Arms.h>
#include <WPIlib.h>

Arms::Arms() {
	// TODO Auto-generated constructor stub
	firstStage = new DoubleSolenoid(1,2);
	secondStage = new DoubleSolenoid(1,2);
	extend = new DoubleSolenoid(1,2);

}

Arms::~Arms() {
	// TODO Auto-generated destructor stub
}

