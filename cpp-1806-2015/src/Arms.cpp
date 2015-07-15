/*
 * Arms.cpp
 *
 *  Created on: Jun 19, 2015
 *      Author: Delfuego
 */
#include <WPIlib.h>
#include <Arms.h>
#include <controller.h>

Arms::Arms() {
	// TODO Auto-generated constructor stub
	firstStage = new DoubleSolenoid(1,2);
	secondStage = new DoubleSolenoid(1,2);
	extendStage = new DoubleSolenoid(1,2);

}

Arms::~Arms() {
	// TODO Auto-generated destructor stub
}

bool Arms::isFirstStageClosed(){
	if (firstStage->Value == firstStage->kForward){
		return true;
	}
	else {
		return false;
	}
}
bool Arms::isSecondStageClosed(){
	if (secondStage->Value == secondStage->kForward){
		return true;
	}
	else {
		return false;
	}
}
bool Arms::isExtended(){
	if (extendStage->Value == extendStage->kForward){
		return true;
	}
	else {
		return false;
	}
}
void Arms::close1Stage(){
	printf("First Stage Closed");
}
void Arms::close2Stage(){
	printf("Second Stage Closed");
}
void Arms::extend(){
	printf("Extended");
}
void Arms::open1Stage(){
	printf("First Stage Open");
}
void Arms::open2Stage(){
	printf("Second Stage Open");
}
void Arms::retract(){
	printf("Retract");
}
