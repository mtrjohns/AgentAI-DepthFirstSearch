#pragma once

#include "MazeManager.h"

class DepthFirst : public MazeManager
{
private:
	int currentPosition;
	char* findObject;
	int foundObjectLocation = -1;
	MazeManager *mazeCreate[1];
	MazePosition *currentMazePosition;

public:

	DepthFirst();
	DepthFirst(MazeManager *, char*);
	~DepthFirst();

	void init(MazeManager *, char*);

	void setCurrentPosition(int);
	int getCurrentPosition();

	void setObjectToFind(char*);
	char* getObjectToFind();

	void setActiveMaze(MazeManager *);
	MazeManager* getActiveMaze();

	// movement calculation functions 
	// (can be made into seperate class in future iteration)
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	void pathController();
	
	// get item location
	void setFoundItemLocation(int);
	void printItemLocation();
	int getfoundItemLocation();
};