#pragma once
#include "Offsets.h"
#include "CichyGDI.h"
#include <thread>
using namespace std;

namespace Threads
{
	void Toggle(bool* killSwitch)
	{
		while (*killSwitch)
		{
			if (GetAsyncKeyState(VK_F5))
			{
				*killSwitch = false;
			}
		}
	}

	void EntityLoop(bool* killSwitch)
	{
		while (*killSwitch)
		{

			Offsets::localPlayer.health = *(int*)Utils::calcPointer(1, (Offsets::clientAddr + Offsets::localPlayerBase), Offsets::health);
			Offsets::localPlayer.x = *(float*)Utils::calcPointer(1, (Offsets::clientAddr + Offsets::localPlayerBase), Offsets::cordX);
			Offsets::localPlayer.y = *(float*)Utils::calcPointer(1, (Offsets::clientAddr + Offsets::localPlayerBase), Offsets::cordY);
			Offsets::localPlayer.z = *(float*)Utils::calcPointer(1, (Offsets::clientAddr + Offsets::localPlayerBase), Offsets::cordZ);

			Offsets::entityArray.clear();
			Entity entityTemp;
			for (int i = 0; i < 32; ++i)
			{

				if ((*(DWORD*)((Offsets::clientAddr + Offsets::entityList) + i * 0x10)) != 0)
				{

					entityTemp.health = *(int*)Utils::calcPointer(1, ((Offsets::clientAddr + Offsets::entityList) + i * 0x10), Offsets::health);
					entityTemp.x = *(float*)Utils::calcPointer(1, ((Offsets::clientAddr + Offsets::entityList) + i * 0x10), Offsets::cordX);
					entityTemp.y = *(float*)Utils::calcPointer(1, ((Offsets::clientAddr + Offsets::entityList) + i * 0x10), Offsets::cordY);
					entityTemp.z = *(float*)Utils::calcPointer(1, ((Offsets::clientAddr + Offsets::entityList) + i * 0x10), Offsets::cordZ);
					Offsets::entityArray.push_back(entityTemp);
				}
			}
		}
	}
	void Debug(bool* killSwitch)
	{
		while (*killSwitch)
		{
			system("cls");

			cout << "==============" << endl;
			cout << dec << " playerHealth: " << Offsets::localPlayer.health << endl;
			cout << dec << " playerX: " << Offsets::localPlayer.x << endl;
			cout << dec << " playerY: " << Offsets::localPlayer.y << endl;
			cout << dec << " playerZ: " << Offsets::localPlayer.z << endl;
			cout << "==============" << endl;

			for (int i = 0; i < 32; ++i)
			{
				if(Offsets::entityArray[i].health != 0)
				{ 
					cout << "==============" << endl;
					cout << dec << i << " entHealth: " << Offsets::entityArray[i].health << endl;
					cout << dec << i << " entX: " << Offsets::entityArray[i].x << endl;
					cout << dec << i << " entY: " << Offsets::entityArray[i].y << endl;
					cout << dec << i << " entZ: " << Offsets::entityArray[i].z << endl;
					cout << "==============" << endl;
				}
			}
			Sleep(100);
		}
	}
	void Draw(CichyGDI *cgdi, bool* killSwitch)
	{

		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		while (*killSwitch)
		{
			float distx, disty;
			cgdi->DrawFilledRect(20, 20, 250, 250, blueBrush);
			cgdi->DrawFilledRect(140, 140, 10, 10, greenBrush);
			for (int i = 0; i < 32; ++i)
			{
				if (Offsets::entityArray[i].health != 0)
				{
					distx = Offsets::localPlayer.x - Offsets::entityArray[i].x;
					disty = Offsets::localPlayer.y - Offsets::entityArray[i].y;
					distx = distx / 25;
					disty = disty / 25;

					cgdi->DrawFilledRect(140 + disty, 140 + distx, 10, 10, redBrush);
				}
			}
		}
	}
	int Initialize()
	{
		CichyGDI cGDI(FindWindow(0, "Fistful of Frags"));
		cGDI.Initialize();

		Offsets::Initialize();

		bool killSwitch = true;
		
		thread toggleThread(Toggle, &killSwitch);
		thread entityThread(EntityLoop, &killSwitch);
		//thread debugThread(Debug, &killSwitch);
		thread drawThread(Draw, &cGDI, &killSwitch);

		toggleThread.join();
		entityThread.join();
		//debugThread.join();
		drawThread.join();

		return 0;
	}
}