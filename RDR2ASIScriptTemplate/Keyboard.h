#pragma once
#include <Windows.h>

namespace Keyboard 
{
	void OnKeyboardMessage(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);
	bool IsKeyDown(DWORD key);
	bool IsKeyDownLong(DWORD key);
	bool IsKeyJustUp(DWORD key, bool exclusive);
	void ResetKeyState(DWORD key);
}