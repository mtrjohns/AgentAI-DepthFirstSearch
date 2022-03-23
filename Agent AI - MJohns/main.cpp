#include <iostream>

#include "CSVFile.h"
#include "MazeManager.h"
#include "TestHarness.h"
#include "DepthFirst.h"

using namespace std;

int main(int argc, char* argv[])
{
	// input from user
	int in;

	TestHarness *test = nullptr;

	CSVFile *mazeFile = new CSVFile();
	mazeFile->loadMazeFile("Maze.csv");

	MazeManager *mazeCreate = new MazeManager(mazeFile);

	CSVFile *maze2File = new CSVFile();
	maze2File->loadMazeFile("Maze2.csv");
	MazeManager *maze2Create = new MazeManager(maze2File);

	DepthFirst *depthFirst = nullptr;


	cout << "Depth First Search Menu." << endl
		<< "1. Depth first search Maze for object 'i'" << endl
		<< "2. Depth first search Maze for no object" << endl
		<< "3. Depth first search Maze2 for object 'i'" << endl
		<< "4. Depth first search Maze2 for no object" << endl
		<< "5. Test Harness Results" << endl
		<< "0. quit" << endl;

	cout << "Plese enter your choice: ";
	cin >> in;

	switch (in)
	{
	case 0:
		// quit case statement
		break;
	case 1:
		mazeFile->printMetaData();
		depthFirst = new DepthFirst(mazeCreate, "i");
		break;
	case 2:
		mazeFile->printMetaData();
		depthFirst = new DepthFirst(mazeCreate, ".");
		break;
	case 3:
		maze2File->printMetaData();
		depthFirst = new DepthFirst(maze2Create, "i");
		break;
	case 4:
		maze2File->printMetaData();
		depthFirst = new DepthFirst(maze2Create, ".");
		break;
	case 5:
		test = new TestHarness();
		test->testMaze();
		test->testCSVFile();
		break;
	default:
		break;
	}

	delete test;
	delete mazeFile;
	delete maze2File;
	delete mazeCreate;
	delete maze2Create;
	delete depthFirst;
}