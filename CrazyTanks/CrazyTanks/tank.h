#pragma once
#include <thread>
class tank
{

private:
	int nowPosX;
	int nowPosY;
	int oldPosX;
	int oldPosY;
	int posPuska;

	//void vectorShot(int,int,int);
	void drawTank(int,int,int);
	void cleanOldPosition();

  


public:
	tank(int, int);
	void tankLeft();
	void tankUp();
	void tankRight();
	void tankDown();
	//void shot();
	//std::thread thr(void shot());
	int getX();
	int getY();
	int getPosPuska();
	
	


	~tank();
};

