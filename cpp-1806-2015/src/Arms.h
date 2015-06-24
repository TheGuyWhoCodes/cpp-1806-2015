/*
 * Arms.h
 *
 *  Created on: Jun 19, 2015
 *      Author: Dillon
 */

#ifndef SRC_ARMS_H_
#define SRC_ARMS_H_

class Arms {
public:
	//constructor
	Arms();
	//destructor
	virtual ~Arms();
	//get state of arms
	bool isFirstStageClosed();		//Will return true if FirstStage is kForward

	bool isSecondStageClosed();		//Will return true if SecondStage is kForward

	bool isExtended();				//Will return true if Extend is kForward
	//close arms
	void closeFirstStage();

	void closeSecondStage();

	void extend();					//Arms extend
	//open arms
	void openFirstStage();

	void openSecondStage();

	void retract();					//Arms retract

private:
	//Pointers to pneumatic arms
	DoubleSolenoid* firstStage;
	DoubleSolenoid* secondStage;
	DoubleSolenoid* extend;

};




#endif /* SRC_ARMS_H_ */
