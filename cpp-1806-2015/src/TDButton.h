/**
 * Team 1730
 * TDButton.h
 * 
 * This class returns true or false values for pressed or released button events..
 */        
#ifndef TDBUTTON_H_
#define TDBUTTON_H_

#include "Joystick.h"

class TDButton
{
public:
   TDButton(Joystick *stick, unsigned char button);
   virtual ~TDButton();
   void Eval();			// The evaluate function must be called once at the beginning of telop period.
   bool IsPressed();	// Returns true if the button was pressed, otherwise false.
   bool IsReleased();	// Returns true if the button was released, otherwise false.
   bool Get();			// Returns the value of the button.
   	
   
private:
   Joystick *mStick;
   unsigned char mButton;
   bool button_state;
   bool last_button_state;
};


#endif
