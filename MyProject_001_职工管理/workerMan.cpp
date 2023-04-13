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

	//创建一个字符，使用ifs读取该字符，如果文件为空，该字符应该为eof
	char ch;
	ifs >> ch;

	if (!ifs.is_open() || ifs.eof())
	{
		//cout << "文件不存在或为空！" << endl;
		this->fileIsNull = true;
		this->manNum = 0;
		this->manArr = nullptr;
		ifs.close();
		return;
	}

	int num = this->getNum();
	// cout << "员工人数：" << num << endl;
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
	cout << "============0.退出===========" << endl;
	cout << "============1.添加===========" << endl;
	cout << "============2.显示===========" << endl;
	cout << "============3.删除===========" << endl;
	cout << "============4.修改===========" << endl;
	cout << "============5.查找===========" << endl;
	cout << "============6.排序===========" << endl;
	cout << "============7.清空===========" << endl;
	cout << "=============================" << endl;
}

void workerMan::exitSystem()
{
	cout << "已退出系统！！！" << endl;
	system("pause");
	exit(0);
}

void workerMan::addMan()
{
	cout << "输入添加的人数：" << endl;
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

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

		cout << "成功添加：" << addNum << "位职工！" << endl;
		this->save();
		this->fileIsNull = false;
	}
	else
	{
		cout << "输入有误！" << endl;
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
		cout << "文件为空或不存在" << endl;
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
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入想要删除的职工号：" << endl;
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
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该员工！" << endl;
		}
	}

	system("pause");
	system("cls");
}

void workerMan::modMan()
{
	if (this->fileIsNull)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号：" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->manArr[ret];

			int newid = 0;
			string newname = "";
			int newdid = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newid;

			cout << "请输入新姓名： " << endl;
			cin >> newname;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}

void workerMan::findMan()
{
	if (this->fileIsNull)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		int choice = 0;
		cout << "请选择查找方式：" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "请输入查找的员工编号：" << endl;
			int id;
			cin >> id;

			int ret = isExist(id);

			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->manArr[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (choice == 2)
		{
			string findname = "";
			cout << "请输入查找的员工姓名：" << endl;
			cin >> findname;

			bool flag = false;
			for (int i = 0; i < this->manNum; i++)
			{
				if (this->manArr[i]->m_name == findname)
				{
					cout << "查找成功,职工编号为："
						<< this->manArr[i]->m_id
						<< " 号的信息如下：" << endl;

					this->manArr[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workerMan::sortMan()
{
	if (this->fileIsNull)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int choice = 0;
		cin >> choice;

		for (int i = 0; i < this->manNum; i++)
		{
			int change = i;//最大最小下标
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
		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->showMan();
	}
}

void workerMan::delall()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

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
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
