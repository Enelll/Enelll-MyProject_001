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
	cout << "============1.�˳�===========" << endl;
	cout << "============2.���===========" << endl;
	cout << "============3.��ʾ===========" << endl;
	cout << "============4.ɾ��===========" << endl;
	cout << "============5.�޸�===========" << endl;
	cout << "============6.����===========" << endl;
	cout << "============7.����===========" << endl;
	cout << "============8.���===========" << endl;
	cout << "=============================" << endl;
}

void workerMan::exitSystem()
{
	cout << "���˳�ϵͳ������" << endl;
	system("pause");
	exit(0);
}
