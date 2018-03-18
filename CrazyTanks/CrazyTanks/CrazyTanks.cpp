// CrazyTanks.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tank.h"
#include<iostream>
#include<Windows.h>
#include <ctime>
#include<conio.h>

using namespace std;

void createWall();
void creatMap();
void start();


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
	createWall();
	
}

void createWall() {
	HWND hWnd = GetConsoleWindow();//дескриптор окна
	HDC hDC = GetDC(hWnd);//контекст устройства
	
	HBRUSH hBrushPerimetr = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));

	HBRUSH hBrushWall = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 255, 0));

	SelectObject(hDC, hBrushPerimetr);
	Rectangle(hDC, 30, 30, 40,610);
	Rectangle(hDC, 30, 30, 610, 40);
	Rectangle(hDC, 610, 30, 600, 610);
	Rectangle(hDC, 30, 610, 610, 600);

	SelectObject(hDC, hBrushWall);

	//random int n = min + rand() % (max - min); // n будет принадлежать диапазону [min, max)
//10 + rand() % 100 [10, 99)
	int randX;
	int randY;
	srand(time(NULL));
	for (int i = 0; i < 10;) {
		randX = 40 + rand() % (600 - 40);
		randY = 40 + rand() % (600 - 40);
		
		//cout << randX << " " << randY<<endl;
		int randFigure= 0 + rand() % (6 - 0);

		switch (randFigure)
		{
		case 0:
			if ((randX + 20) < 600 && (randY + 20) < 600) {
Rectangle(hDC, randX, randY, randX+20, randY+20);
			i++;
			}
			
			break;
		case 1:
			if ((randX + 20) < 600 && (randY + 40) < 600) {
Rectangle(hDC, randX, randY, randX + 20, randY + 40);
			i++;
			}
			
			break;
		case 2:
			if ((randX + 20) < 600 && (randY + 60) < 600) {
Rectangle(hDC, randX, randY, randX + 20, randY + 60);
			i++;
			}
			
			break;
		case 3:
			if ((randX + 20) < 600 && (randY + 20) < 600) {
Rectangle(hDC, randX, randY, randX+20, randY+20);
			i++;
			}
			
			break;
		case 4:
			if ((randX + 40) < 600 && (randY + 20) < 600) {
Rectangle(hDC, randX, randY, randX+40, randY+20);
			i++;
			}
			
			break;
		case 5:
			if ((randX + 60) < 600 && (randY + 20) < 600) {
Rectangle(hDC, randX, randY, randX+60, randY+20);
			i++;
			}
			
			break;
		default:
			break;
		}
	}


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
	tank* playerTank = new tank(100, 100);
	int a;

	//75-влево 72-верх 77-вправо 88-вниз 32-выстрел
	int ch = 0;
	while (true) {
		ch = _getch();

	
		switch (ch)
		{
		case 75:
			cout << "left";
			playerTank->tankLeft();
			break;
		case 72:
			playerTank->tankUp();
			cout << "up";
			break;
		case 77:
			playerTank->tankRight();
			cout << "right";
			break;
		case 80:
			playerTank->tankDown();
			cout << "down";
			break;
		case 32:
			cout << "spase";
			break;
		default:
			break;
		}
	}

	
		cin >> a;

	//system("pause");
    return 0;
}

