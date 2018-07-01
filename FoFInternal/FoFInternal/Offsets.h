#include <windows.h>
#include <iostream>
#include <vector>
#include "Utils.h"
#include "EntityList.h"

namespace Offsets
{
	extern DWORD clientAddr;
	extern DWORD localPlayerBase; //client.dll
	extern DWORD health[];

	extern DWORD cordX[];
	extern DWORD cordY[];
	extern DWORD cordZ[];

	extern DWORD localPlayerPitch[];
	extern DWORD localPlayerYaw[];
	extern DWORD localPlayerRoll[];

	extern DWORD entityList; //client.dll
	extern std::vector <Entity>entityArray;
	extern Entity localPlayer;

	extern float localPlayerPitch_t;
	extern float localPlayerYaw_t;

	extern void Initialize();
}