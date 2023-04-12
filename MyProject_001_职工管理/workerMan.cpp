#include <iostream>

#include "BOSS.h"
#include "JL.h"
#include "YG.h"
using namespace std;
#include "workerMan.h"

workerMan::workerMan()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//����һ���ַ���ʹ��ifs��ȡ���ַ�������ļ�Ϊ�գ����ַ�Ӧ��Ϊeof
	char ch;
	ifs >> ch;

	if (!ifs.is_open() || ifs.eof())
	{
		//cout << "�ļ������ڻ�Ϊ�գ�" << endl;
		this->fileIsNull = true;
		this->manNum = 0;
		this->manArr = nullptr;
		ifs.close();
		return;
	}

	int num = this->getNum();
	// cout << "Ա��������" << num << endl;
	this->manNum = num;

	this->manArr = new worker*[this->manNum];
	this->initMan();
}

workerMan::~workerMan()
{
	if (this->manArr != nullptr)
	{
		delete[] this->manArr;
	}
}

void workerMan::showMenu()
{
	cout << "=============================" << endl;
	cout << "============0.�˳�===========" << endl;
	cout << "============1.���===========" << endl;
	cout << "============2.��ʾ===========" << endl;
	cout << "============3.ɾ��===========" << endl;
	cout << "============4.�޸�===========" << endl;
	cout << "============5.����===========" << endl;
	cout << "============6.����===========" << endl;
	cout << "============7.���===========" << endl;
	cout << "=============================" << endl;
}

void workerMan::exitSystem()
{
	cout << "���˳�ϵͳ������" << endl;
	system("pause");
	exit(0);
}

void workerMan::addMan()
{
	cout << "������ӵ�������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newsize = manNum + addNum;
		worker** newspace = new worker*[newsize];

		if (this->manArr != NULL)
		{
			for (int i = 0; i < manNum; i++)
			{
				newspace[i] = this->manArr[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new YG(id, name, 1);
				break;
			case 2:
				worker = new JL(id, name, 2);
				break;
			case 3:
				worker = new BOSS(id, name, 1);
				break;
			default:
				break;
			}
			newspace[this->manNum + i] = worker;
		}
		delete[] this->manArr;
		this->manArr = newspace;
		this->manNum = newsize;

		cout << "�ɹ���ӣ�" << addNum << "λְ����" << endl;
		this->save();
		this->fileIsNull = false;
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void workerMan::save()
{
	ofstream ofs;

	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->manNum; i++)
	{
		ofs << this->manArr[i]->m_id << " "
			<< this->manArr[i]->m_name << " "
			<< this->manArr[i]->m_Did << endl;
	}
	ofs.close();
}

int workerMan::getNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int Did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		num++;
	}
	ifs.close();
	return num;
}

void workerMan::initMan()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int Did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> Did)
	{
		worker* worker = nullptr;
		if (Did == 1)
		{
			worker = new YG(id, name, Did);
		}
		else if (Did == 2)
		{
			worker = new JL(id, name, Did);
		}
		else
		{
			worker = new BOSS(id, name, Did);
		}
		this->manArr[index] = worker;
		index++;
	}
}

void workerMan::showMan()
{
	if (this->fileIsNull)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		for (int i = 0; i < this->manNum; i++)
		{
			this->manArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int workerMan::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->manNum; i++)
	{
		if (this->manArr[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workerMan::delMan()
{
	if (this->fileIsNull)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->manNum - 1; i++)
			{
				this->manArr[i] = this->manArr[i + 1];
			}
			this->manNum--;
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա����" << endl;
		}
	}

	system("pause");
	system("cls");
}
