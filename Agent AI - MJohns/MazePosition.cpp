#include "MazePosition.h"
#include "MazeManager.h"
#include <iostream>

using namespace std;

MazePosition::MazePosition()
{
	setPosX(-1);
	setPosY(-1);
	setLocationIdentify('\0');
}

// (posX, posY, locationIdentifier)
MazePosition::MazePosition(int posX, int posY, char* locationIdentifier, bool visited)
{
	setPosX(posX);
	setPosY(posY);

	// char that is present in this location in file
	setLocationIdentify(locationIdentifier);

	setVisited(visited);

	//cout << "Maze.cpp Constructor called...." << endl;
}

MazePosition::~MazePosition()
{
	//cout << "Maze.cpp Destructor called...." << endl;
}

void MazePosition::setPosX(int posX)
{
	this->posX = posX;
}

void MazePosition::setPosY(int posY)
{
	this->posY = posY;
}

void MazePosition::setLocationIdentify(char *locationIdentifier)
{
	this->locationIdentifier = locationIdentifier;
}

int MazePosition::getPosX(void)
{
	return this->posX;
}

int MazePosition::getPosY(void)
{
	return this->posY;
}

char* MazePosition::getLocationIdentifier(void)
{
	return this->locationIdentifier;
}

void MazePosition::setVisited(bool visitedValue)
{
	// if visited and NOT start position (Start will always stay as S)
	if (visitedValue == true && strcmp(getLocationIdentifier(), "S") != 0)
	{
		this->setLocationIdentify("o");
	}
	this->visited = visitedValue;
}

bool MazePosition::getVisited()
{
	return this->visited;
}

void MazePosition::print()
{
	cout << "Position X = " << getPosX() << endl;
	cout << "Position Y = " << getPosY() << endl;

	if (getLocationIdentifier() != nullptr)
	{
		cout << "Location Identifier = " << getLocationIdentifier() << endl;
	}
}