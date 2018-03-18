#pragma once
class tank
{

private:
	int nowPosX;
	int nowPosY;
	int oldPosX;
	int oldPosY;

	void cleanOldPosition();
public:
	tank(int, int);
	void tankLeft();
	void tankUp();
	void tankRight();
	void tankDown();
	
	


	~tank();
};

