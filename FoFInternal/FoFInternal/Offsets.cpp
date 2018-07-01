#include "Offsets.h"


using namespace std;

namespace Offsets
{


	DWORD clientAddr = 0x0;
	DWORD localPlayerBase = 0x5725E0; //client.dll
	DWORD health[] = { 0xA8 };
	
	DWORD cordX[] = {0x264};
	DWORD cordY[] = {0x268};
	DWORD cordZ[] = {0x26C};
	
	DWORD localPlayerPitch[] = { 0x270 };
	DWORD localPlayerYaw[] = { 0x274 };
	DWORD localPlayerRoll[] = { 0x278 };
	
	DWORD entityList = 0x0057FC64; //client.dll
	//Players are 0x10 away from eachother

	vector <Entity>entityArray;
	Entity localPlayer;
	
	extern float localPlayerPitch_t = 0;
	extern float localPlayerYaw_t = 0;

	void Initialize()
	{
		clientAddr = (DWORD)GetModuleHandle("client.dll");
	}
}



/*
clientAddr = (DWORD)GetModuleHandle("client.dll");

cout << "-------------------------" << endl;

cout << hex << "clientAddr: " << clientAddr << endl;
cout << "clientAddr + localplayerbase: " << (clientAddr + localPlayerBase) << endl;
cout << "(DWORD*)clientAddr + localplayerbase: " << (DWORD*)(clientAddr + localPlayerBase) << endl;
cout << "*(DWORD*)clientAddr + localplayerbase: " << *(DWORD*)(clientAddr + localPlayerBase) << endl;
cout << "localPlayerBase: " << Utils::calcPointer(0, (clientAddr + localPlayerBase), { 0x0 }) << endl;

cout << "localPlayerHealth: " << dec << *(int*)Utils::calcPointer(1, (clientAddr + localPlayerBase), temp) << endl;
temp[0] = cordX;
cout << "localPlayerX: " << dec << *(float*)Utils::calcPointer(1, (clientAddr + localPlayerBase), temp) << endl;


system("pause");

while (true)
{
entityArray.clear();
if (GetAsyncKeyState(VK_F5))
{
break;
}
if ((clientAddr + entityList) == 0)
{
cout << "waiting for the entity list" << endl;
}
else
{
Entity entityTemp;
for (int i = 0; i < 32; ++i)
{

if ((*(DWORD*)((clientAddr + entityList) + i * 0x10)) != 0)
{

entityTemp.health = *(int*)Utils::calcPointer(1, ((clientAddr + entityList) + i * 0x10), health);
entityTemp.x = *(float*)Utils::calcPointer(1, ((clientAddr + entityList) + i * 0x10), cordX);
entityTemp.y = *(float*)Utils::calcPointer(1, ((clientAddr + entityList) + i * 0x10), cordY);
entityTemp.z = *(float*)Utils::calcPointer(1, ((clientAddr + entityList) + i * 0x10), cordZ);
entityArray.push_back(entityTemp);

}
}
for (int i = 0; i < 32; ++i)
{
cout << "==============" << endl;
cout << dec << i << " entHealth: " << entityArray[i].health << endl;
cout << dec << i << " entX: " << entityArray[i].x << endl;
cout << dec << i << " entY: " << entityArray[i].y << endl;
cout << dec << i << " entZ: " << entityArray[i].z << endl;
cout << "==============" << endl;
}
}
Sleep(100);
system("cls");

}


for (int i = 0; i < 64; ++i)
{

if ((*(DWORD*)((clientAddr + entityList) + i * 0x10)) != 0)
{
//cout << "shouldnotbezero: " << hex << *(DWORD*)((clientAddr + entityList) + i * 0x10) << endl;
//cout << "check" << hex << ((clientAddr + entityList) + i * 0x10) << endl;
cout << dec << i << " entHealth: " << *(int*)Utils::calcPointer(1, ((clientAddr + entityList) + i * 0x10), temp) << endl;
//cout << dec << i << hex << " " << i * 0x10 << " " << *(DWORD*)((clientAddr + entityList) + i * 0x10) << endl;
}
}


cout << "-------------------------" << endl;
*/