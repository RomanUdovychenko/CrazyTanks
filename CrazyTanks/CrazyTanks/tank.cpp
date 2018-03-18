#include "stdafx.h"
#include "tank.h"
#include <Windows.h>

void tank::cleanOldPosition()
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства

	//HBRUSH hBrush = CreateHatchBrush(NULL_BRUSH, RGB(255, 255, 255));
	//SelectObject(hDC, NULL_BRUSH);
	//HBRUSH hBrush = CreateBrushIndirect();
	HPEN stylePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hDC, stylePen);
	Rectangle(hDC, oldPosX, oldPosY, oldPosX + 20, oldPosY + 20);
}

tank::tank(int posX,int posY)
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства

	HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	SelectObject(hDC, hBrush);
	Rectangle(hDC,posX ,posY, posX+20, posY+20);
	oldPosX = posX;
	oldPosY = posY;
}

void tank::tankLeft()
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства
	cleanOldPosition();

	HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	SelectObject(hDC, hBrush);
	nowPosX = oldPosX - 20;
	nowPosY = oldPosY;
	Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	oldPosX = nowPosX;
	oldPosY = nowPosY;
	
}

void tank::tankUp()
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства
	cleanOldPosition();

	HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	SelectObject(hDC, hBrush);
	nowPosX = oldPosX;
	nowPosY = oldPosY-20;
	Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	oldPosX = nowPosX;
	oldPosY = nowPosY;
}

void tank::tankRight()
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства
	cleanOldPosition();

	HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	SelectObject(hDC, hBrush);
	nowPosX = oldPosX+20;
	nowPosY = oldPosY;
	Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	oldPosX = nowPosX;
	oldPosY = nowPosY;
}

void tank::tankDown()
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства
	cleanOldPosition();

	HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	SelectObject(hDC, hBrush);
	nowPosX = oldPosX;
	nowPosY = oldPosY+20;
	Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	oldPosX = nowPosX;
	oldPosY = nowPosY;
}


tank::~tank()
{
}
