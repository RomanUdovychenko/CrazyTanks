#include "stdafx.h"
#include "tank.h"
#include <Windows.h>

void tank::vectorShot(int shotX, int shotY,int vector)
{
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HPEN stylePenDraw = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	HPEN stylePenClean = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	int vecX;
	int vecY;
	vecX = oldPosX +shotX;
	vecY = oldPosY +shotY;
	for (int i = 0; i < 20; i++) {
		SelectObject(hDC, stylePenDraw);

		switch (vector)
		{
		case 0:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX - 5, vecY);
			break;
		case 1:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX , vecY-5);
			break;
		case 2:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX + 5, vecY);
			break;
		case 3:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX, vecY + 5);
			break;
		default:
			break;
		}

		

		Sleep(25);

		SelectObject(hDC, stylePenClean);
		
		switch (vector)
		{
		case 0:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX - 5, vecY);
			vecX -= 20;
			break;
		case 1:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX, vecY - 5);
			vecY -= 20;
			break;
		case 2:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX + 5, vecY);
			vecX += 20;
			break;
		case 3:
			MoveToEx(hDC, vecX, vecY, NULL);
			LineTo(hDC, vecX, vecY + 5);
			vecY += 20;
			break;
		default:
			break;
		}

		
	}
}
	

	void tank::drawTank(int plusX,int plusY,int puska)
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

	//MoveToEx(hDC, oldPosX, oldPosY+10, NULL); 
	//LineTo(hDC, oldPosX+10, oldPosY);

	//MoveToEx(hDC, oldPosX+10, oldPosY , NULL);
	//LineTo(hDC, oldPosX+20 , oldPosY+10);

	//MoveToEx(hDC, oldPosX , oldPosY+10, NULL);
	//LineTo(hDC, oldPosX + 20, oldPosY + 10);
	
	posPuska = puska;

	switch (puska)
	{
	case 0:
		//left
		MoveToEx(hDC, oldPosX+10, oldPosY , NULL);
		LineTo(hDC, oldPosX , oldPosY+10);

		MoveToEx(hDC, oldPosX , oldPosY+10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);

		MoveToEx(hDC, oldPosX+10, oldPosY , NULL);
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
		LineTo(hDC, oldPosX+20, oldPosY + 10);

		MoveToEx(hDC, oldPosX+20, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);

		MoveToEx(hDC, oldPosX + 10, oldPosY, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY + 20);
		break;
	case 3:
		//down
		MoveToEx(hDC, oldPosX, oldPosY + 10, NULL);
		LineTo(hDC, oldPosX + 10, oldPosY+20);

		MoveToEx(hDC, oldPosX + 19, oldPosY+10, NULL);
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
	drawTank(-20,0,0);
	//HWND hWnd = GetConsoleWindow();//дескриптор окна
	//HDC hDC = GetDC(hWnd);//контекст устройства
	//cleanOldPosition();

	//HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	//SelectObject(hDC, hBrush);
	//nowPosX = oldPosX - 20;
	////nowPosY = oldPosY;
	//Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	//oldPosX = nowPosX;
	//oldPosY = nowPosY;
	
}

void tank::tankUp()
{
	drawTank(0, -20, 1);
	//HWND hWnd = GetConsoleWindow();//дескриптор окна
	//HDC hDC = GetDC(hWnd);//контекст устройства
	//cleanOldPosition();

	//HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	//SelectObject(hDC, hBrush);
	//nowPosX = oldPosX;
	//nowPosY = oldPosY-20;
	//Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	//oldPosX = nowPosX;
	//oldPosY = nowPosY;
}

void tank::tankRight()
{
	drawTank(20, 0, 2);
	///HWND hWnd = GetConsoleWindow();//дескриптор окна
	//HDC hDC = GetDC(hWnd);//контекст устройства
	//cleanOldPosition();

	//HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	//SelectObject(hDC, hBrush);
	//nowPosX = oldPosX+20;
	//nowPosY = oldPosY;
	//Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	//oldPosX = nowPosX;
	//oldPosY = nowPosY;
}

void tank::tankDown()
{
	drawTank(0, 20, 3);
	//HWND hWnd = GetConsoleWindow();//дескриптор окна
	//HDC hDC = GetDC(hWnd);//контекст устройства
	//cleanOldPosition();

	//HBRUSH hBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));
	//SelectObject(hDC, hBrush);
	//nowPosX = oldPosX;
	//nowPosY = oldPosY+20;
	//Rectangle(hDC, nowPosX, nowPosY, nowPosX + 20, nowPosY + 20);
	//oldPosX = nowPosX;
	//oldPosY = nowPosY;
}

void tank::shot()
{
	

	switch (posPuska)
	{
	case 0:		
		vectorShot(-3,10,0);
		break;
	case 1:
		vectorShot(10, -3,1);
		break;
	case 2:
		vectorShot(23, 10,2);
		break;
	case 3:
		vectorShot(10, 23,3);
		break;
	default:
		break;
	}
}

int tank::getX()
{
	return oldPosX;
}

int tank::getY()
{
	return oldPosY;
}


tank::~tank()
{
}
