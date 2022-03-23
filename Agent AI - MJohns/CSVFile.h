#pragma once

/********************************
**** CSVFile Object Header File *
********************************/
#include "MazeManager.h"
//class MazeManager;
#include <iostream>
using namespace std;

class CSVFile
{
private:
	// Maximum storage value
	static const unsigned int NAME_MAX = 1024;
	// Array to store file name
	char name[NAME_MAX];
	bool loadedFlag;
	int mazeRows = -1;
	int mazeColumns = -1;
	string mazeStore[NAME_MAX];

public:
	CSVFile();
	CSVFile(char*);
	~CSVFile();

	void setName(char*);
	char* getName(void);

	void setLoadedFlagTrue();
	void setLoadedFlagFalse();
	bool getLoadedFlag();      

	int getMazeColumns();
	int getMazeRows();

	void loadMazeFile();
	void loadMazeFile(char * filename);
	void closeFile();

	char* getMaze(int index);

	void printMetaData();
};