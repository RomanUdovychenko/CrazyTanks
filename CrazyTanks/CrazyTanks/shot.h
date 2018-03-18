#pragma once
class shot
{
public:
	shot();
	~shot();
private:
	int beginShotX;
	int beginShotY;
	void runShot();
	void cleanOldPosition();
};

