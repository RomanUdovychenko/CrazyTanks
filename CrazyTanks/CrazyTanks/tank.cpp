#include "stdafx.h"
#include "tank.h"
#include <Windows.h>

void tank::drawTank(int plusX, int plusY, int puska)
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства
	cleanOldPosition();

	HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	SelectObject(hDC, hBrush);
	nowPosX = oldPosX + plusX;
	nowPosY = oldPosY + plusY;
	Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	oldPosX = nowPosX;
	oldPosY = nowPosY;

	posPuska = puska;

	switch (puska)
	{
	case 0:
		//left
		MoveToEx(hDC, oldPosX + 10, oldPosY, NULL);
		LineTo(hDC, oldPosX, oldPosY + 10);

		MoveToEx(hDC, oldPosX, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);

		MoveToEx(hDC, oldPosX + 10, oldPosY, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);
		break;
	case 1:
		//up
		MoveToEx(hDC, oldPosX, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY);

		MoveToEx(hDC, oldPosX + 10, oldPosY, NULL);
		LineTo(hDC, oldPosX + 20, oldPosY + 10);

		MoveToEx(hDC, oldPosX, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 20, oldPosY + 10);
		break;
	case 2:
		//right
		MoveToEx(hDC, oldPosX + 10, oldPosY, NULL);
		LineTo(hDC, oldPosX + 20, oldPosY + 10);

		MoveToEx(hDC, oldPosX + 20, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);

		MoveToEx(hDC, oldPosX + 10, oldPosY, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);
		break;
	case 3:
		//down
		MoveToEx(hDC, oldPosX, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);

		MoveToEx(hDC, oldPosX + 19, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);

		MoveToEx(hDC, oldPosX, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 20, oldPosY + 10);
		break;
	default:
		break;
	}
}

void tank::cleanOldPosition()
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства

	HPEN stylePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(hDC, stylePen);
	Rectangle(hDC, oldPosX, oldPosY, oldPosX + 20, oldPosY + 20);
}

tank::tank(int posX, int posY)
{
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства

	HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	SelectObject(hDC, hBrush);
	Rectangle(hDC, posX, posY, posX + 20, posY + 20);
	oldPosX = posX;
	oldPosY = posY;
}

void tank::tankLeft()
{
	drawTank(-20, 0, 0);
}

void tank::tankUp()
{
	drawTank(0, -20, 1);
}

void tank::tankRight()
{
	drawTank(20, 0, 2);

}

void tank::tankDown()
{
	drawTank(0, 20, 3);
}



int tank::getX()
{
	return oldPosX;
}

int tank::getY()
{
	return oldPosY;
}

int tank::getPosPuska()
{
	return posPuska;
}


tank::~tank()
{
}
