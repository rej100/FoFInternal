#include <Windows.h>
#include <Psapi.h>
#include <TlHelp32.h>

namespace Utils
{
	DWORD calcPointer(int pointerLevel, DWORD baseAddress, DWORD offsets[]);
	MODULEINFO GetModuleInfo(char *szModule);
	void WriteToMemory(uintptr_t addressToWrite, char* valueToWrite, int byteNum);
	DWORD FindPattern(char *module, char *pattern, char *mask);
	MODULEINFO GetModuleInfoB(char *szModule);
	DWORD FindPatternB(char *module, char *pattern, char *mask);
	HANDLE GetProcessByName(char* processName);
}