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
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addMan();
			break;
		case 2:
			wm.showMan();
			break;
		case 3:
			wm.delMan();
			break;
		// case 4:
		//
		// 	break;
		// case 5:
		//
		// 	break;
		// case 6:
		//
		// 	break ;
		// case7:
		//
		// 	break;
		default:
			break;
		}
	}
	// system("pause");
	// return 0;
}
