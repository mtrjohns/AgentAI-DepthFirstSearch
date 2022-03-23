#include "DepthFirst.h"
#include "MazeManager.h"

#include <iostream>
#include <stack>
#include <ctime>

using namespace std;

DepthFirst::DepthFirst()
{

}

DepthFirst::DepthFirst(MazeManager *maze, char* findItem)
{
	// initialise object
	init(maze, findItem);
}

DepthFirst::~DepthFirst()
{

}

// initialise components
void DepthFirst::init(MazeManager *maze, char* findItem)
{
	setActiveMaze(maze);
	setObjectToFind(findItem);

	//cout << "Maze Start in depth " << this->mazeCreate[0]->getStartPosition() << endl;

	setCurrentPosition(this->mazeCreate[0]->getStartPosition());

	// display start position as "P" for player
	this->mazeCreate[0]->setMazePositionIdentifier(getCurrentPosition(), "S");

	pathController();
}

void DepthFirst::setCurrentPosition(int index)
{
	this->currentPosition = index;

	// if next node is item, do not set to player X, leave item identifier in place
	if (strcmp(this->mazeCreate[0]->getMazePositionIdentifier(getCurrentPosition()), findObject) != 0)
	{
		this->mazeCreate[0]->setMazePositionIdentifier(this->getCurrentPosition(), "X");
	}
}

int DepthFirst::getCurrentPosition()
{
	return this->currentPosition;
}

void DepthFirst::setObjectToFind(char *findItem)
{
	this->findObject = findItem;
}

char * DepthFirst::getObjectToFind()
{
	return this->findObject;
}


void DepthFirst::setActiveMaze(MazeManager *maze)
{
	this->mazeCreate[0] = maze;
}

MazeManager * DepthFirst::getActiveMaze()
{
	return *mazeCreate;
}

void DepthFirst::moveLeft()
{
	//cout << "before move left " << this->getCurrentPosition() << endl;
	// decrease index by one
	this->setCurrentPosition(getCurrentPosition() -1);

	//cout << "After move left (should be 1 index less) " << this->getCurrentPosition() << endl;
}

void DepthFirst::moveRight()
{
	// if next position is less than maze width
	// this if statement not needed if all outside maze border is set as wall (*)
	// can be added to down, left and right functions too
	if (this->mazeCreate[0]->getPosX(this->getCurrentPosition() + 1) < this->mazeCreate[0]->getMazeColumnsAmount() - 1)
	{
		// increase index by one
		this->setCurrentPosition(getCurrentPosition() + 1);
	}
}

void DepthFirst::moveDown()
{
	//cout << "before move Down " << this->getCurrentPosition() << endl;

	// increase index by maze width
	this->setCurrentPosition(getCurrentPosition() + this->mazeCreate[0]->getMazeColumnsAmount());


	//cout << "After move Down (should be amount of rows in maze higher) " << this->getCurrentPosition() << endl;
}

void DepthFirst::moveUp()
{
	
	//cout << "before move Down " << this->getCurrentPosition() << endl;

	// decrease index by maze width
	this->setCurrentPosition(getCurrentPosition() - this->mazeCreate[0]->getMazeColumnsAmount());

	//cout << "After move Down (should be amount of rows in maze higher) " << this->getCurrentPosition() << endl;
}

void DepthFirst::pathController()
{
	stack<int> stackDepthFirst;

	bool itemFound = false;
	// check if next node is not a wall and has not been visited previously
	while (!itemFound || !this->mazeCreate[0]->getStartPosition())
	{
		if ((strcmp(this->mazeCreate[0]->getMazePositionIdentifier(this->getCurrentPosition() + 1), "*") != 0) && (this->mazeCreate[0]->getVisitedStatus(this->getCurrentPosition() + 1) != true))
		{
			// check if item is found
			if (strcmp(this->mazeCreate[0]->getMazePositionIdentifier(this->getCurrentPosition() + 1), findObject) == 0)
			{
				this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

				// push current position to stack
				stackDepthFirst.push(this->getCurrentPosition());

				itemFound = true;

				// set current position to new position
				moveRight();

				setFoundItemLocation(getCurrentPosition());

				// break early
				break;
			}

			// set visited status as true and change display to circle (in setvisited)
			this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

			// push position index on to stack
			stackDepthFirst.push(this->getCurrentPosition());

			moveRight();

			// set current position to new position
			this->setCurrentPosition(this->getCurrentPosition());
		}
		// check / move down
		else if ((strcmp(this->mazeCreate[0]->getMazePositionIdentifier(getCurrentPosition() + this->mazeCreate[0]->getMazeColumnsAmount()), "*") != 0) && (this->mazeCreate[0]->getVisitedStatus(this->getCurrentPosition() + this->mazeCreate[0]->getMazeColumnsAmount()) != true))
		{
			if (strcmp(this->mazeCreate[0]->getMazePositionIdentifier(this->getCurrentPosition() + this->mazeCreate[0]->getMazeColumnsAmount()), findObject) == 0)
			{
				this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

				// push current position to stack
				stackDepthFirst.push(this->getCurrentPosition());

				itemFound = true;

				// set current position to new position
				moveDown();

				setFoundItemLocation(getCurrentPosition());
			}
			// set visited status as true and change display to circle (in setvisited)
			this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

			// push position index on to stack
			stackDepthFirst.push(this->getCurrentPosition());

			moveDown();

			this->setCurrentPosition(this->getCurrentPosition());
		}
		// check / move left
		else if ((strcmp(this->mazeCreate[0]->getMazePositionIdentifier(this->getCurrentPosition() - 1), "*") != 0) && (this->mazeCreate[0]->getVisitedStatus(this->getCurrentPosition() - 1) != true))
		{
			if (strcmp(this->mazeCreate[0]->getMazePositionIdentifier(this->getCurrentPosition() - 1), findObject) == 0)
			{
				this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

				// push current position to stack
				stackDepthFirst.push(this->getCurrentPosition());

				itemFound = true;

				// set current position to new position
				moveLeft();

				setFoundItemLocation(getCurrentPosition());
			}
			// set visited status as true and change display to circle (in setvisited)
			this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

			// push position index on to stack
			stackDepthFirst.push(this->getCurrentPosition());

			moveLeft();

			this->setCurrentPosition(this->getCurrentPosition());
		}
		// check / move up
		else if ((strcmp(this->mazeCreate[0]->getMazePositionIdentifier(getCurrentPosition() - this->mazeCreate[0]->getMazeColumnsAmount()), "*") != 0) && (this->mazeCreate[0]->getVisitedStatus(this->getCurrentPosition() - this->mazeCreate[0]->getMazeColumnsAmount()) != true))
		{
			if (strcmp(this->mazeCreate[0]->getMazePositionIdentifier(this->getCurrentPosition() - this->mazeCreate[0]->getMazeColumnsAmount()), findObject) == 0)
			{
				this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

				// push current position to stack
				stackDepthFirst.push(this->getCurrentPosition());

				itemFound = true;

				// set current position to new position
				moveUp();

				setFoundItemLocation(getCurrentPosition());
				break;
			}

			// set visited status as true and change display to circle (in setvisited)
			this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

			// push position index on to stack
			stackDepthFirst.push(this->getCurrentPosition());

			moveUp();

			this->setCurrentPosition(this->getCurrentPosition());
		}
		// now check if all above statements are visited, pop stack to move back and recheck node at that point
		else
		{
			this->mazeCreate[0]->setVisitedStatus(this->getCurrentPosition(), true);

			if (!stackDepthFirst.empty())
			{
				// set current position as new stack index
				this->setCurrentPosition(stackDepthFirst.top());

				// pop stack
				stackDepthFirst.pop();
			}
			else
			{
				break;
			}
		}

		// print maze
		this->mazeCreate[0]->printMaze();

		// print maze with visited bools displayed
		//this->mazeCreate[0]->printVisited();
	}

	// print item location to screen
	this->printItemLocation();
}

int DepthFirst::getfoundItemLocation()
{
	return this->foundObjectLocation;
}

void DepthFirst::setFoundItemLocation(int index)
{
	this->foundObjectLocation = index;
}

void DepthFirst::printItemLocation()
{
	if (getfoundItemLocation() != -1)
	{
		cout << "Item found at (" << this->mazeCreate[0]->getPosX(getfoundItemLocation()) << ", "
			<< this->mazeCreate[0]->getPosY(getfoundItemLocation())
			<< "), array index [" << getfoundItemLocation() << "]" << endl;
	}
}