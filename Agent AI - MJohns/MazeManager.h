#pragma once

class MazePosition;
class CSVFile;

class MazeManager
{

private:
	static const int SIZE = 1024;
	int startPosition = -1;
	CSVFile *csvLoaded;
	MazePosition* maze[SIZE];

public:
	MazeManager();
	MazeManager(CSVFile *);
	~MazeManager();

	void setStartPosition();
	void MazeManager::setWallVisited();
	int getStartPosition(void);

	void setCsvMaze(CSVFile *);
	CSVFile* getCsvMaze(void);

	// used to get access to private maze objects
	char* getMazePositionIdentifier(int);
	void setMazePositionIdentifier(int, char*);
	bool getVisitedStatus(int);
	void setVisitedStatus(int, bool);


	int getMazeColumnsAmount();
	int getMazeRowsAmount();

	int getPosX(int);
	int getPosY(int);

	void CreateMazePositions();
	void waitTimer();
	void printMaze();
	void printVisited();
};