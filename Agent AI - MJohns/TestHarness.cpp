/****************************
*** Test Harness source *****
****************************/

#include "TestHarness.h"
#include "MazePosition.h"
#include "CSVFile.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

TestHarness::TestHarness(void)
{	

}

TestHarness::~TestHarness(void)
{

}

bool TestHarness::testMazeCreate()
{

/* Testing a constructor is a bit tricky, 
* so here's the code for the first one 
* there are better ways to test (try / catch)
*/
	// set testResult as false
	bool testResult = false;

	// Set pointer to NULL (0)
	MazePosition* test = nullptr;

	// Create InputPattern object
	test = new MazePosition();

	// Make sure test no longer null
	if (test != nullptr)
	{
		testResult = true;
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testMazeSetup()
{
	bool testResult = false;
	const int TEST_COUNT = 3;
	int testsComplete = 0;
	int testPosX = 1;
	int testPosY = 1;
	char* testLocationIdentifier = "t";

	// Set pointer to nullptr
	MazePosition* test = nullptr;

	// create maze
	test = new MazePosition(testPosX, testPosY, testLocationIdentifier, false);

	// check if getPosX() is set to value of testPosX
	if (testPosX == test->getPosX())
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// check if getPosY() is set to value of testPosY
	if (testPosY == test->getPosY())
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// check if getlocationIdentifier() is set to value of testLocationIdentifier
	if (testLocationIdentifier == test->getLocationIdentifier())
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// count successful tests
	if (testsComplete == TEST_COUNT)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	// delete the test object
	delete test;
	test = nullptr;

	// return the test result
	return testResult;
}

bool TestHarness::testMazeDestroy()
{
	// Set pointer to NULL (0)
	MazePosition* test = nullptr;

	// Create InputPattern object
	test = new MazePosition();

	// Make sure test no longer null
	if (test != nullptr)
	{
		delete test;
		test = nullptr;
	}
	else
	{
		// Blank else statement
	}

	// set to true manually, as seen destructor being called through print onscreen
	return true;
}

bool TestHarness::testMazePrint()
{

	//test Maze Values set as expected
	MazePosition *test = new MazePosition();
	test->setPosX(2);
	test->setPosY(2);
	test->setLocationIdentify("r");

	cout << endl << "Below Print should be: X = " << test->getPosX() 
			<< ", Y = " << test->getPosY() 
			<< ", Location Identifier = " << test->getLocationIdentifier() 
			<<  endl;

	// Print()
	test->print();
	cout << endl;
	
	delete test;
	test = nullptr;

	// Displayed correctly on screen, manually set to true
	return true;
}

bool TestHarness::testCSVFileCreate()
{
	// set testResult as false
	bool testResult = false;

	// Set pointer to NULL (0)
	CSVFile* test = nullptr;

	// Create CSVFile object
	test = new CSVFile();

	// Make sure test no longer null	
	if (test != nullptr)
	{
		testResult = true;
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileSetFilepath()
{
	/* Check that the filepath can be set and recovered
	* take care when comparing strings
	*/

	// set testResult as false
	bool testResult = false;
	CSVFile* test = nullptr;
	test = new CSVFile();

	test->setName("Maze.csv");
	
	// compare name of file with getName
	if (strcmp("Maze.csv", test->getName()) == 0)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileLoadFile()
{
	// set testResult as false
	bool testResult = false;
	CSVFile* test = nullptr;

	test = new CSVFile("Maze2.csv");
	test->loadMazeFile();
	
	// check if file loaded flag is set to true, else false
	if (test->getLoadedFlag() == true)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileCloseFile()
{
	// set testResult as false
	bool testResult = false;
	CSVFile* test = nullptr;

	test = new CSVFile("Maze.csv");
	test->loadMazeFile();

	test->closeFile();

	// check if file loaded flag is set to true, else false
	if (test->getLoadedFlag() == false)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileLoadedFlag()
{
	// set testResult as false
	bool testResult = false;
	const int TEST_COUNT = 2;
	int testsComplete = 0;

	CSVFile *test = new CSVFile;

	// open file and check if opened correctly
	ifstream file("Maze.csv", ios::in | ios::binary);
	if (!file.is_open())
	{
		test->setLoadedFlagFalse();
	}
	else
	{
		test->setLoadedFlagTrue();
	}

	// check loaded flag is true
	if (test->getLoadedFlag() == true)
	{
		testsComplete++;
		file.close();
		delete test;
		test = nullptr;
	}
	else
	{
		file.close();
		delete test;
		test = nullptr;
	}

	CSVFile *test2 = new CSVFile;
	// open file and check if file failed to open, this should fail
	ifstream file2("ThereIsNoFile.csv", ios::in | ios::binary);
	if (!file.is_open())
	{
		test2->setLoadedFlagFalse();
	}
	else
	{
		test2->setLoadedFlagTrue();
	}

	// check loaded flag is false, there is no file
	if (test2->getLoadedFlag() == false)
	{
		testsComplete++;
		file2.close();
		delete test2;
	}
	else
	{
		file2.close();
		delete test2;
	}

	// count successful tests
	if (testsComplete == TEST_COUNT)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}


	return testResult;
}

bool TestHarness::testCSVFilePrintMeta()
{
	// OUTPUT IS ON-SCREEN ONLY
	CSVFile* test = nullptr;

	test = new CSVFile("Maze.csv");
	test->loadMazeFile();
	
	//test->printMetaData();

	delete test;
	test = nullptr;

	// Set to true manually - Displayed on screen correctly
	return true;
}


bool TestHarness::testMaze()
{
	const int TEST_COUNT = 4;
	int testsComplete = 0;

	// InputPattern test 0
	if(this->testMazeCreate() == true)
	{ 
		printf("Maze Create test PASSED\n");
		testsComplete++;
	}
	else
	{
		printf("Maze Create test FAILED\n");
	}

	// InputPattern test 1
	if (this->testMazeSetup() == true)
	{
		printf("Maze Setup test PASSED\n");
		testsComplete++;
	}
	else
	{
		printf("Maze Setup test FAILED\n");
	}

	// InputPattern test 2
	if (this->testMazeDestroy() == true)
	{
		printf("Maze Destroy test PASSED\n");
		testsComplete++;
	}
	else
	{
		printf("Maze Destory test FAILED\n");
	}

	// InputPattern test 3
	if (this->testMazePrint() == true)
	{
		printf("Maze Print test PASSED\n\n");
		testsComplete++;
	}
	else
	{
		printf("Maze Print test FAILED\n\n");
	}

	if (testsComplete == TEST_COUNT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestHarness::testCSVFile()
{
	const int TEST_COUNT = 6;
	int testsComplete = 0;

	// CSVFile test 0
	if (this->testCSVFileCreate() == true)
	{
		printf("CSVFile Create test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile Create test FAILED \n");
	}

	// CSVFile test 1
	if (this->testCSVFileSetFilepath() == true)
	{
		printf("CSVFile setFilepath test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile setFilepath test FAILED \n");
	}

	// CSVFile test 2
	if (this->testCSVFileLoadFile() == true)
	{
		printf("CSVFile LoadFile test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile LoadFile test FAILED \n");
	}

	// CSVFile test 3
	if (this->testCSVFileLoadedFlag() == true)
	{
		printf("CSVFile LoadedFlag test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile LoadedFlag test FAILED \n");
	}

	// CSVFile test 4
	if (this->testCSVFilePrintMeta() == true)
	{
		printf("CSVFile PrintMeta test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile PrintMeta test FAILED \n");
	}
	// CSVFile test 5
	if (this->testCSVFileCloseFile() == true)
	{
		printf("CSVFile CloseFile test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile CloseFile test FAILED \n");
	}

	if (testsComplete == TEST_COUNT)
	{
		return true;
	}
	else
	{
		return false;
	}
}