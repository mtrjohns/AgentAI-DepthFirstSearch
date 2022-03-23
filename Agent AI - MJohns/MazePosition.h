#pragma once

#include "MazeManager.h"

class MazePosition : public MazeManager
{
private:
	int posX = -1;
	int posY = -1;
	char* locationIdentifier = nullptr;
	bool visited = false;

public:
	MazePosition();

	// (posX, posY, locationIdentifier)
	MazePosition(int, int, char*, bool);

	void setPosX(int);
	void setPosY(int);

	int getPosX(void);
	int getPosY(void);

	// what char is at this maze position
	char* getLocationIdentifier(void);
	void setLocationIdentify(char*);

	// visited = true, not visited = false
	void setVisited(bool);
	bool getVisited();

	void print();

	~MazePosition();
};