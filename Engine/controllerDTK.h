#pragma once

#include <windows.h>
#include <Xinput.h>
#pragma comment(lib, "XInput.lib")
class ControllerDTK{
private:
	XINPUT_STATE contState;
	int contNum;
public:
	ControllerDTK(int pNum);
	XINPUT_STATE getState();
	bool isConnected();
	void Vibrate(int leftVal=0,int rightVal=0);
};