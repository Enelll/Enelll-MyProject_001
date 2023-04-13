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

void workerMan::modMan()
{
	if (this->fileIsNull)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա����ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->manArr[ret];

			int newid = 0;
			string newname = "";
			int newdid = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newid;

			cout << "�������������� " << endl;
			cin >> newname;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newdid;

			worker* worker = nullptr;
			switch (newdid)
			{
			case1:
				worker = new YG(newid, newname, newdid);
				break;
			case2:
				worker = new JL(newid, newname, newdid);
				break;
			case 3:
				worker = new BOSS(newid, newname, newdid);
				break;
			default:
				break;
			}
			this->manArr[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	//������� ����
	system("pause");
	system("cls");
}

void workerMan::findMan()
{
	if (this->fileIsNull)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		int choice = 0;
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "��������ҵ�Ա����ţ�" << endl;
			int id;
			cin >> id;

			int ret = isExist(id);

			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->manArr[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (choice == 2)
		{
			string findname = "";
			cout << "��������ҵ�Ա��������" << endl;
			cin >> findname;

			bool flag = false;
			for (int i = 0; i < this->manNum; i++)
			{
				if (this->manArr[i]->m_name == findname)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< this->manArr[i]->m_id
						<< " �ŵ���Ϣ���£�" << endl;

					this->manArr[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerMan::sortMan()
{
	if (this->fileIsNull)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int choice = 0;
		cin >> choice;

		for (int i = 0; i < this->manNum; i++)
		{
			int change = i;//�����С�±�
			for (int j = i + 1; j < this->manNum; j++)
			{
				if (choice == 1)
				{
					if (this->manArr[change]->m_id > this->manArr[j]->m_id)
					{
						change = j;
					}
				}
				else
				{
					if (this->manArr[change]->m_id < this->manArr[j]->m_id)
					{
						change = j;
					}
				}
			}
			if (i != change)
			{
				worker* swap = this->manArr[i];
				this->manArr[i] = this->manArr[change];
				this->manArr[change] = swap;
			}
		}
		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->showMan();
	}
}

void workerMan::delall()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int choice = 0;
	cin >> choice;

	if (choice == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (this->manArr != NULL)
		{
			for (int i = 0; i < this->manNum; i++)
			{
				if (this->manArr[i] != NULL)
				{
					delete this->manArr[i];
				}
			}
			this->manNum = 0;
			delete this->manArr;
			this->manArr = NULL;
			this->fileIsNull = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}
