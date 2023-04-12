#pragma once
#include <fstream>
#define FILENAME "test.txt"
#include <iostream>

#include "worker.h"
using namespace std;

class workerMan
{
public:
	workerMan();
	~workerMan();
	void showMenu();
	void exitSystem();

	int manNum;
	worker** manArr;
	void addMan();

	void save();

	bool fileIsNull;

	int getNum();

	void initMan();

	void showMan();

	int isExist(int id);

	void delMan();
};
