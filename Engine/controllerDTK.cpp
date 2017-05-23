#include "controllerDTK.h"

ControllerDTK::ControllerDTK(int pNum){
	contNum=pNum-1;
}

XINPUT_STATE ControllerDTK::getState(){
	ZeroMemory(&contState,sizeof(XINPUT_STATE));
	XInputGetState(contNum,&contState);
	return contState;
}

bool ControllerDTK::isConnected(){
	// Zeroise the state

	ZeroMemory(&contState,sizeof(XINPUT_STATE));

	// Get the state

	DWORD Result=XInputGetState(contNum,&contState);

	if(Result==ERROR_SUCCESS){
		return true;
	} else{
		return false;
	}
}

void ControllerDTK::Vibrate(int leftVal,int rightVal){
	// Create a Vibraton State

	XINPUT_VIBRATION Vibration;

	// Zeroise the Vibration

	ZeroMemory(&Vibration,sizeof(XINPUT_VIBRATION));

	// Set the Vibration Values

	Vibration.wLeftMotorSpeed=leftVal;
	Vibration.wRightMotorSpeed=rightVal;

	// Vibrate the controller

	XInputSetState(contNum,&Vibration);
}