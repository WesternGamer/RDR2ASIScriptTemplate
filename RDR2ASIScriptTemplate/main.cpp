#include "main.h"
#include <string>
#include <vector>
#include "natives.h"
#include "enums.h"
#include "types.h"

/// <summary>
/// Main entry point of ASI script.
/// </summary>
/// <param name="hInstance">Handle to DLL module.</param>
/// <param name="reason">Reason for calling function</param>
/// <param name="lpReserved">Reserved.</param>
/// <returns></returns>
BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		scriptRegister(hInstance, Main);
		break;
	case DLL_PROCESS_DETACH:
		Dispose();
		scriptUnregister(hInstance);
		break;
	}
	return TRUE;
}

void Main() 
{

#pragma region DoNotTouch
	// Add your code above this code.
	srand(GetTickCount64());
	while (true)
	{
		Update();
		WAIT(0);
	}
#pragma endregion
}

void Update() 
{
	HUD::_DISABLE_REDUCE_TIME_SCALE_WHILE_MENU_IS_OPEN();
}

void Dispose() 
{

}