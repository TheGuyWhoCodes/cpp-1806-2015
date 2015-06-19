
/**
 * Team 1730
 * TDButton.cpp
 * 
 * This class returns true or false values for pressed or released button events..
 */        

#include "TDButton.h"


TDButton::TDButton(Joystick *stick, unsigned char button){
	button_state = last_button_state = 0;
	mStick = stick;
	mButton = button;
}
   
TDButton::~TDButton(){
	
}
void TDButton::Eval()			// The evaluate function must be called once at the beginning of telop period.
{
	last_button_state = button_state;
	button_state = mStick->GetRawButton(mButton);
}

bool TDButton::IsPressed()	// Returns true if the button was pressed, otherwise false.
{
	if(button_state && !last_button_state)
		return true;
	else
		return false;
}

bool TDButton::IsReleased()	// Returns true if the button was released, otherwise false.
{
	if(!button_state && last_button_state)
		return true;
	else
		return false;
}

bool TDButton::Get()			// Returns the value of the button.
{
	return button_state;
}




