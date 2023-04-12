#include <iostream>
#include <string>

#include "workerMan.h"
using namespace std;

int main()
{
	workerMan wm;
	int chiose;
	while (true)
	{
		wm.showMenu();
		cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ£º" << endl;
		cin >> chiose;

		switch (chiose)
		{
		case 1:
			wm.exitSystem();
			break;
		}
	}
	system("pause");
	return 0;
}
