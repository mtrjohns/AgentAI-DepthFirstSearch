/*****************************
**** CSVFile Object cpp File *
*****************************/

#include "CSVFile.h"
#include <fstream>
#include <sstream>

CSVFile::CSVFile()
{
	setName("NoNameSet");
	setLoadedFlagFalse();
}

CSVFile::CSVFile(char * filename)
{
	setName(filename);
	setLoadedFlagFalse();
}

CSVFile::~CSVFile()
{
	//cout << "Destroyed CSV file..." << endl;
}

void CSVFile::setName(char * filename)
{
	strcpy_s(this->name, filename);
}

char* CSVFile::getName(void)
{
	return name;
}

void CSVFile::setLoadedFlagTrue()
{
	this->loadedFlag = true;
}

void CSVFile::setLoadedFlagFalse()
{
	this->loadedFlag = false;
}

bool CSVFile::getLoadedFlag()
{
	return loadedFlag;
}

int CSVFile::getMazeColumns()
{
	return this->mazeColumns;
}

int CSVFile::getMazeRows()
{
	return this->mazeRows;
}

// Specific load for a maze file
void CSVFile::loadMazeFile()
{
	ifstream mazeFile(getName());

	// check file opened correctly
	if (!mazeFile.is_open())
	{
		printf("Error opening file correctly\n");
		setLoadedFlagFalse();
	}
	else
	{
		setLoadedFlagTrue();

		//cout << "file: " << getName() << endl;

		cout << endl;

		string line;

		int index = 0;

		// while /n has not been reached in file
		while (getline(mazeFile, line))
		{
			stringstream rows(line);
			stringstream field(line);
			string cell;

			//cout << "index = " << index << endl;

			// while comma has not been reached in file
			while (getline(rows, cell, ','))
			{
				// while comma has not been reached within field
				getline(field, mazeStore[index], ',');

				index++;
			}
		}

		// set maze row amount
		istringstream(mazeStore[2]) >> this->mazeRows;
		// set maze column amount
		istringstream(mazeStore[4]) >> this->mazeColumns;
	}
	
}

// allow for file name to be passed in on loading maze file
void CSVFile::loadMazeFile(char* filename)
{
	setName(filename);
	loadMazeFile();
}

void CSVFile::closeFile()
{
	ifstream file(getName());

	if (file.is_open())
	{
		file.close();
		setLoadedFlagFalse();
	}
	else
	{
		// printf("File was not open\n");
	}
}

char* CSVFile::getMaze(int index)
{
	string storage;

	if (index > -1 && index < (this->getMazeColumns() * this->getMazeRows()) || index == 0)
	{
		index = index + 5;
		// Set Maze char*
		stringstream t(mazeStore[index]);
		t >> storage;

		//cout << "Storage = " << storage << endl;

		// convert storage string to a char*
		// add 1 to account for \0 terminator
		char * temp = new char[storage.size() + 1];
		copy(storage.begin(), storage.end(), temp);
		temp[storage.size()] = '\0';

		//cout << "temp [" << index << "] =" << temp << endl;
		return temp;
	}
	else
	{
		// Blank Else Statement
		return nullptr;
	}
}

void CSVFile::printMetaData()
{
	cout << "Maze Rows = " << this->mazeRows << endl;
	cout << "Maze Columns = " << this->mazeColumns << endl;
}