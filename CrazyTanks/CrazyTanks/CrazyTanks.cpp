// CrazyTanks.cpp: определяет точку входа для консольного приложения.
//
#include <thread>
#include "stdafx.h"
#include "tank.h"
#include<iostream>
#include<Windows.h>
#include <ctime>
#include<conio.h>

using namespace std;


int playingField[1000][1000];

void createWall();
void creatMap();
void start();


void Shot(int posPushka, int oldPosX, int oldPosY);

void tempShow() {
	for (int i = 40; i <= 600; i++) {
		cout << playingField[i][40];

	}
}

void creatMap() {
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HBRUSH hBrush;

	hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 0));
	SelectObject(hDC, hBrush);
	Rectangle(hDC, 30, 30, 900, 700);
	hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 255));
	SelectObject(hDC, hBrush);
	Rectangle(hDC, 40, 40, 600, 600);
	for (int i = 40; i <= 600; i++) {
		playingField[40][i] = 1;
		playingField[i][40] = 1;
	}
	for (int i = 600; i >= 40; i--) {
		playingField[580][i] = 1;
		playingField[i][580] = 1;
	}
	createWall();

}

void createWall() {
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);

	HBRUSH hBrushPerimetr = CreateHatchBrush(HS_VERTICAL, RGB(0, 255, 255));

	HBRUSH hBrushWall = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 255, 0));

	SelectObject(hDC, hBrushPerimetr);
	Rectangle(hDC, 30, 30, 40, 610);
	Rectangle(hDC, 30, 30, 610, 40);
	Rectangle(hDC, 610, 30, 600, 610);
	Rectangle(hDC, 30, 610, 610, 600);

	SelectObject(hDC, hBrushWall);

	int randX;
	int randY;
	srand(time(NULL));
	for (int i = 0; i < 10;) {
		bool enableDraw = true;

		randX = 40 + rand() % (600 - 40);
		randY = 40 + rand() % (600 - 40);

		int randFigure = 0 + rand() % (6 - 0);

		switch (randFigure)
		{
		case 0:
			if ((randX + 20) < 600 && (randY + 20) < 600) {
				for (int i = 0; i < 20; i++) {
					if (enableDraw == false) {
						break;
					}
					for (int j = 0; j < 20; j++) {
						if (playingField[randX + i][randY + j] == 1) {
							enableDraw = false;
							break;
						}
					}
				}

				if (enableDraw = true) {
					Rectangle(hDC, randX, randY, randX + 20, randY + 20);
					for (int i = 0; i < 20; i++) {
						for (int j = 0; j < 20; j++) {
							playingField[randX + i][randY + j] = 1;
						}
					}
					i++;
				}
			}

			break;
		case 1:
			if ((randX + 20) < 600 && (randY + 40) < 600) {
				for (int i = 0; i < 20; i++) {
					if (enableDraw == false) {
						break;
					}
					for (int j = 0; j < 40; j++) {
						if (playingField[randX + i][randY + j] == 1) {
							enableDraw = false;
							break;
						}
					}
				}

				if (enableDraw = true) {
					Rectangle(hDC, randX, randY, randX + 20, randY + 40);
					for (int i = 0; i < 20; i++) {
						for (int j = 0; j < 40; j++) {
							playingField[randX + i][randY + j] = 1;
						}
					}
					i++;
				}
			}

			break;
		case 2:
			if ((randX + 20) < 600 && (randY + 60) < 600) {
				for (int i = 0; i < 20; i++) {
					if (enableDraw == false) {
						break;
					}
					for (int j = 0; j < 60; j++) {
						if (playingField[randX + i][randY + j] == 1) {
							enableDraw = false;
							break;
						}
					}
				}


				if (enableDraw = true) {
					Rectangle(hDC, randX, randY, randX + 20, randY + 60);
					for (int i = 0; i < 20; i++) {
						for (int j = 0; j < 60; j++) {
							playingField[randX + i][randY + j] = 1;
						}
					}
					i++;
				}
			}

			break;
		case 3:
			if ((randX + 20) < 600 && (randY + 20) < 600) {
				for (int i = 0; i < 20; i++) {
					if (enableDraw == false) {
						break;
					}
					for (int j = 0; j < 20; j++) {
						if (playingField[randX + i][randY + j] == 1) {
							enableDraw = false;
							break;
						}
					}
				}

				if (enableDraw = true) {
					Rectangle(hDC, randX, randY, randX + 20, randY + 20);
					for (int i = 0; i < 20; i++) {
						for (int j = 0; j < 20; j++) {
							playingField[randX + i][randY + j] = 1;
						}
					}
					i++;
				}
			}

			break;
		case 4:
			if ((randX + 40) < 600 && (randY + 20) < 600) {
				for (int i = 0; i < 40; i++) {
					if (enableDraw == false) {
						break;
					}
					for (int j = 0; j < 20; j++) {
						if (playingField[randX + i][randY + j] == 1) {
							enableDraw = false;
							break;
						}
					}
				}

				if (enableDraw = true) {
					Rectangle(hDC, randX, randY, randX + 40, randY + 20);
					for (int i = 0; i < 40; i++) {
						for (int j = 0; j < 20; j++) {
							playingField[randX + i][randY + j] = 1;
						}
					}
					i++;
				}
			}

			break;
		case 5:
			if ((randX + 60) < 600 && (randY + 20) < 600) {
				for (int i = 0; i < 60; i++) {
					if (enableDraw == false) {
						break;
					}
					for (int j = 0; j < 20; j++) {
						if (playingField[randX + i][randY + j] == 1) {
							enableDraw = false;
							break;
						}
					}
				}

				if (enableDraw = true) {
					Rectangle(hDC, randX, randY, randX + 60, randY + 20);
					for (int i = 0; i < 60; i++) {
						for (int j = 0; j < 20; j++) {
							playingField[randX + i][randY + j] = 1;
						}
					}
					i++;
				}
			}

			break;
		default:
			break;
		}
	}


}

void start() {

	creatMap();
}

	

	

int main()
{
	start();
	int startPositionX = 0;
	int startPositionY = 0;
	bool enableDraw = false;
	



	while (!enableDraw)
	{
		startPositionX = 200 + rand() % (500 - 200);
		startPositionY = 500 + rand() % (500 - 499);
		enableDraw = true;
		for (int i = 0; i < 20; i++) {
			if (enableDraw == false) {
				break;
			}
			for (int j = 0; j < 20; j++) {
				if (playingField[startPositionX + i][startPositionY + j] == 1) {
					enableDraw = false;
					break;
				}
			}


		}
	}

	tank* playerTank = new tank(startPositionX, startPositionX);

	int ch = 0;
	bool enableMove = true;
	while (true) {
		ch = _getch();

		enableMove = true;
		switch (ch)
		{
		case 75://"left";
			for (int i = 0; i < 21; i++) {
				if (enableMove == false) {
					break;
				}
				for (int j = 0; j < 21; j++) {
					if (playingField[playerTank->getX() - i][playerTank->getY() + j] == 1) {
						enableMove = false;
						break;
					}
				}
			}
			
			if (enableMove == true) {
				playerTank->tankLeft();
			}

			break;
		case 72://"up";
			for (int i = 0; i < 21; i++) {
				if (enableMove == false) {
					break;
				}
				for (int j = 0; j < 21; j++) {
					if (playingField[playerTank->getX() + i][playerTank->getY() - j] == 1) {

						enableMove = false;
						break;
					}
				}
			}

			if (enableMove == true) {
				playerTank->tankUp();
			}
			
			break;
		case 77://"right";
			for (int i = 0; i < 21; i++) {
				if (enableMove == false) {
					break;
				}
				for (int j = 0; j < 21; j++) {
					if (playingField[playerTank->getX() + i][playerTank->getY() + j] == 1) {
						enableMove = false;
						break;
					}
				}
			}

			if (enableMove == true) {
				playerTank->tankRight();
			}
			
			break;
		case 80:
			for (int i = 0; i < 21; i++) {
				if (enableMove == false) {
					break;
				}
				for (int j = 0; j < 21; j++) {
					if (playingField[playerTank->getX() - i][playerTank->getY() + j] == 1) {
						enableMove = false;
						break;
					}
				}
			}

			if (enableMove == true) {
				playerTank->tankDown();
			}
			//"down";
			break;
		case 32://"Shot"
				int x = playerTank->getX();
				int y = playerTank->getY();
				int p = playerTank->getPosPuska();

				std::thread threadShot(Shot, std::ref(p), std::ref(x), std::ref(y));
				threadShot.detach();
				threadShot.~thread();
			break;
		}
	}
	return 0;
}

void vectorShot(int shotX, int shotY, int vector, int oldPosX, int oldPosY)
{
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HPEN stylePenDraw = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	HPEN stylePenClean = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	int vecX;
	int vecY;
	vecX = oldPosX + shotX;
	vecY = oldPosY + shotY;
	bool enableMoveShot = true;
	int i = 0;
	while (enableMoveShot) {
		SelectObject(hDC, stylePenDraw);

		switch (vector)
		{
		case 0:
			for (int i = 0; i <= 5; i++) {
				if (playingField[vecX - 5][vecY] == 1 || vecX - 5 < 40) {
					enableMoveShot = false;
					break;
				}

			}
			if (enableMoveShot) {
				MoveToEx(hDC, vecX, vecY, NULL);
				LineTo(hDC, vecX - 5, vecY);
			}

			break;
		case 1:
			for (int i = 0; i <= 5; i++) {
				if (playingField[vecX][vecY - 5] == 1 || vecY - 5 < 40) {
					enableMoveShot = false;
					break;
				}

			}
			if (enableMoveShot) {
				MoveToEx(hDC, vecX, vecY, NULL);
				LineTo(hDC, vecX, vecY - 5);

			}

			break;
		case 2:
			for (int i = 0; i <= 5; i++) {
				if (playingField[vecX + 5][vecY] == 1 || vecX + 5 > 600) {
					enableMoveShot = false;
					break;
				}
			}
			if (enableMoveShot) {
				MoveToEx(hDC, vecX, vecY, NULL);
				LineTo(hDC, vecX + 5, vecY);
			}

			break;
		case 3:
			for (int i = 0; i <= 5; i++) {
				if (playingField[vecX][vecY + 5] == 1 || vecY + 5 > 600) {
					enableMoveShot = false;
					break;
				}
			}
			if (enableMoveShot) {
				MoveToEx(hDC, vecX, vecY, NULL);
				LineTo(hDC, vecX, vecY + 5);
			}

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

		}


	}
}

void Shot(int posPushka, int oldPosX, int oldPosY)
{
	switch (posPushka)
	{
	case 0:
		vectorShot(-3, 10, 0, oldPosX, oldPosY);
		break;
	case 1:
		vectorShot(10, -3, 1, oldPosX, oldPosY);
		break;
	case 2:
		vectorShot(23, 10, 2, oldPosX, oldPosY);
		break;
	case 3:
		vectorShot(10, 23, 3, oldPosX, oldPosY);
		break;
	default:
		break;
	}


}



