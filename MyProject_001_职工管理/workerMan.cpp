#include <iostream>
using namespace std;
#include "workerMan.h"

workerMan::workerMan()
{
}

workerMan::~workerMan()
{
}

void workerMan::showMenu()
{
	cout << "=============================" << endl;
	cout << "============1.退出===========" << endl;
	cout << "============2.添加===========" << endl;
	cout << "============3.显示===========" << endl;
	cout << "============4.删除===========" << endl;
	cout << "============5.修改===========" << endl;
	cout << "============6.查找===========" << endl;
	cout << "============7.排序===========" << endl;
	cout << "============8.清空===========" << endl;
	cout << "=============================" << endl;
}

void workerMan::exitSystem()
{
	cout << "已退出系统！！！" << endl;
	system("pause");
	exit(0);
}
