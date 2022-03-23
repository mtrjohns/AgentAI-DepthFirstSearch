#include "MazeManager.h"
#include "MazePosition.h"
#include "CSVFile.h"
#include <iostream>
#include <ctime>

MazeManager::MazeManager()
{
}

MazeManager::MazeManager(CSVFile* csv)
{
	setCsvMaze(csv);
	CreateMazePositions();
	setStartPosition();
}

MazeManager::~MazeManager()
{

}

void MazeManager::setStartPosition()
{
	int i = 0;

	while (i < (this->csvLoaded->getMazeColumns() * this->csvLoaded->getMazeRows()))
	{
		if (strcmp(this->maze[i]->getLocationIdentifier(), "s") == 0)
		{
			this->startPosition = i;
			this->maze[i]->setVisited(true);
		}
		i++;
	}

	//cout << "Start Position = " << getStartPosition() 
	//	<< ", Start identifier = " << this->maze[getStartPosition()]->getLocationIdentifier() << endl;
}

// to be used to set wall bool to enable no need of checking walls in a future iteration
void MazeManager::setWallVisited()
{
	int i = 0;

	while (i < (this->csvLoaded->getMazeColumns() * this->csvLoaded->getMazeRows()))
	{
		if (strcmp(this->maze[i]->getLocationIdentifier(), "*") == 0)
		{
			this->maze[i]->setVisited(true);
		}
		i++;
	}

	//cout << "Start Position = " << getStartPosition() 
	//	<< ", Start identifier = " << this->maze[getStartPosition()]->getLocationIdentifier() << endl;
}

int MazeManager::getStartPosition(void)
{
	return this->startPosition;
}

void MazeManager::setCsvMaze(CSVFile* csv)
{
	this->csvLoaded = csv;
}

CSVFile * MazeManager::getCsvMaze(void)
{
	return this->csvLoaded;
}

char* MazeManager::getMazePositionIdentifier(int index)
{
	//cout << "in get maze position " << maze[index]->getPosX() << endl;

	return this->maze[index]->getLocationIdentifier();
}

void MazeManager::setMazePositionIdentifier(int index, char *identifier)
{
	//cout << "old identifier = " << this->maze[index]->getLocationIdentifier() << endl;
	this->maze[index]->setLocationIdentify(identifier);
	//cout << "new identifier = " << this->maze[index]->getLocationIdentifier() << endl;
}

bool MazeManager::getVisitedStatus(int index)
{
	return this->maze[index]->getVisited();
}

void MazeManager::setVisitedStatus(int index, bool status)
{
	this->maze[index]->setVisited(status);
}

int MazeManager::getPosX(int index)
{
	return this->maze[index]->getPosX();
}

int MazeManager::getPosY(int index)
{
	return this->maze[index]->getPosY();
}

int MazeManager::getMazeColumnsAmount()
{
	// return columns amount from loaded maze file object
	return this->getCsvMaze()->getMazeColumns();
}

int MazeManager::getMazeRowsAmount()
{
	// return rows amount from loaded maze file object
	return this->getCsvMaze()->getMazeRows();
}

void MazeManager::CreateMazePositions()
{
	int i = 0;
	int x = 0;
	bool visited = false;
	int counterRows = 0;
	int counterColumns = 0;
	int y = this->csvLoaded->getMazeRows() - 1;

	// Fill Maze objects
	while (counterRows < this->csvLoaded->getMazeRows())
	{
		while (x < this->csvLoaded->getMazeColumns())
		{
			//cout << "i = " << i << "(" << x << ", " << y << " = " << this->csvLoaded->getMaze(i) << endl;
			this->maze[i] = new MazePosition(x, y, this->csvLoaded->getMaze(i), visited);

			i++;
			x++;
			  
			//cout << "Visited i = " << i << "(" << x << ", " << y << " = " << this->maze[i]->getVisited() << endl;
		}

		// start of row again (for coordinate system)
		x = 0;
		// next line
		y--;

		counterRows++;
	}
	//printMaze();
	//cout << "Visited i = " << i << "(" << x << ", " << y << " = " << this->maze[i]->getVisited() << endl;
}

void MazeManager::waitTimer()
{
	// wait in between print maze to show movement slower than instant
	clock_t wait = 0.1 * 1000 + clock();
	while (wait > clock()) continue;

	// clear screen ( used to appear like maze is staying at top of console window)
	system("cls");
}

void MazeManager::printMaze()
{
	int i;
	int counter = 0;
	int index = 0;

	// wait in between print maze to show movement slower than instant
	waitTimer();

	while (counter < this->csvLoaded->getMazeRows())
	{
		for (i = 0; i < this->csvLoaded->getMazeColumns(); i++)
		{
			// print out characters at position
			cout << this->maze[index]->getLocationIdentifier() << " ";

			//cout << "visited state " << this->maze[index]->getVisited() << endl;

			index++;
		}

		cout << endl;
		counter++;
	}
	cout << endl;
}

void MazeManager::printVisited()
{
	int i;
	int counter = 0;
	int index = 0;

	waitTimer();

	while (counter < this->csvLoaded->getMazeRows())
	{
		for (i = 0; i < this->csvLoaded->getMazeColumns(); i++)
		{
			// print out characters at position
			cout << this->maze[index]->getVisited() << " ";

			//cout << "visited state " << this->maze[index]->getVisited() << endl;

			index++;
		}

		cout << endl;
		counter++;
	}
	cout << endl;
}