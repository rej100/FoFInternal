#include "CichyGDI.h"

CichyGDI::CichyGDI(HWND targetWindow) : targetWindow(targetWindow)
{

}

CichyGDI::~CichyGDI()
{

}

bool CichyGDI::Initialize()
{
	if (!(targetWindow == NULL))
	{
		targetHDC = GetDC(targetWindow);
		font = CreateFont(36, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
			CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
		return true;
	}
	return false;
}

void CichyGDI::DrawLine(float StartX, float StartY, float EndX, float EndY, COLORREF color)
{
	int a = 0;
	HPEN hOPen;
	HPEN hNPen = CreatePen(PS_SOLID, 2, color);
	hOPen = (HPEN)SelectObject(targetHDC, hNPen);
	MoveToEx(targetHDC, StartX, StartY, NULL);
	a = LineTo(targetHDC, EndX, EndY);
	DeleteObject(SelectObject(targetHDC, hOPen));
}

void CichyGDI::DrawString(int x, int y, COLORREF color, const char* text)
{
	SetTextAlign(targetHDC, TA_CENTER | TA_NOUPDATECP);
	SetBkColor(targetHDC, RGB(0, 0, 0));
	SetBkMode(targetHDC, TRANSPARENT);
	SetTextColor(targetHDC, color);
	SelectObject(targetHDC, font);
	TextOutA(targetHDC, x, y, text, strlen(text));
	DeleteObject(font);
}

void CichyGDI::DrawFilledRect(int x, int y, int w, int h, HBRUSH brush)
{
	RECT rect = { x, y, x + w, y + h };
	FillRect(targetHDC, &rect, brush);
}

void CichyGDI::DrawBorderBox(int x, int y, int w, int h, int thickness, HBRUSH brush)
{
	DrawFilledRect(x, y, w, thickness, brush);
	DrawFilledRect(x, y, thickness, h, brush);
	DrawFilledRect((x + w), y, thickness, h, brush);
	DrawFilledRect(x, y + h, w + thickness, thickness, brush);
}