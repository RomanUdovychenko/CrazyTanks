// CrazyTanks.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;

void creatMap() {
    HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства
	HBRUSH hBrush;
	
	hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 0));
	SelectObject(hDC, hBrush);
	Rectangle(hDC, 30, 30, 900, 700);
	hBrush = CreateHatchBrush(HS_CROSS,RGB(255, 255, 255));
	SelectObject(hDC, hBrush);
	Rectangle(hDC, 40, 40, 600, 600);
	
	
}


void start() {


	//рисование карты
	creatMap();
	//генерация припятствий

	//генерация врагов

	//генерация главного танка
}

int main()
{
	start();


	int a;
		cin >> a;

	//system("pause");
    return 0;
}

