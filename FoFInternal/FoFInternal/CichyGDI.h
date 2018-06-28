#include <Windows.h>
class CichyGDI
{
public:
	CichyGDI(HWND targetWindow);
	~CichyGDI();

	HFONT font;

	bool Initialize();
	void DrawLine(float StartX, float StartY, float EndX, float EndY, COLORREF color);
	void DrawString(int x, int y, COLORREF color, const char* text);
	void DrawFilledRect(int x, int y, int w, int h, HBRUSH brush);
	void DrawBorderBox(int x, int y, int w, int h, int thickness, HBRUSH brush);
	HWND targetWindow;
	HDC targetHDC;
private:
};