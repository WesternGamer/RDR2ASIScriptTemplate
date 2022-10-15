#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include "natives.h"
#include "enums.h"
#include "types.h"
#include "Keyboard.h"
#include "Scripthook.h"
#include "Pools.h"

using namespace Keyboard;
using namespace Pools;
using namespace std;

namespace RDR2ASIScriptTemplate 
{
	/// <summary>
    /// Called every game update.
    /// </summary>
	void Update()
	{
		Pools::Update();
	}

	/// <summary>
	/// This function is triggered when the game closes or when you press Ctrl + R. Probably called when going online with Scripthook RDR2.
	/// </summary>
	void Dispose()
	{

	}

	/// <summary>
	/// This function is triggered when you interact with the game for the first time after the world loads.
	/// </summary>
	void OnWorldLoad()
	{
		srand(GetTickCount());

		// Put your code here.

		while (true)
		{
			Update();
			WAIT(0);
		}
	}

	/// <summary>
	/// This function is triggered when the game loads.
	/// </summary>
	void OnGameLoad()
	{

	}

	/// <summary>
	/// Main entry point of ASI script.
	/// </summary>
	/// <param name="hInstance">Handle to DLL module.</param>
	/// <param name="reason">Reason for calling function.</param>
	/// <param name="lpReserved">Reserved.</param>
	/// <returns>True</returns>
	BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved)
	{
		switch (reason)
		{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hInstance);
			OnGameLoad();
			scriptRegister(hInstance, OnWorldLoad);
			keyboardHandlerRegister(Keyboard::OnKeyboardMessage);
			break;
		case DLL_PROCESS_DETACH:
			Dispose();
			scriptUnregister(hInstance);
			keyboardHandlerUnregister(Keyboard::OnKeyboardMessage);
			break;
		}
		return true;
	}
}





