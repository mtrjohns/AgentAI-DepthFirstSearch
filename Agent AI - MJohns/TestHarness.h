/****************************
*** Test Harness header *****
****************************/
#pragma once

class TestHarness
{

public:
	TestHarness(void);
	~TestHarness(void);

	bool testMaze();
	bool testCSVFile();

private:
	bool testMazeCreate();
	bool testMazeSetup();
	bool testMazeDestroy();
    bool testMazePrint();


	bool testCSVFileCreate();
    bool testCSVFileSetFilepath();
    bool testCSVFileLoadedFlag();
    bool testCSVFileLoadFile();
	bool testCSVFileCloseFile();
	bool testCSVFilePrintMeta();
};