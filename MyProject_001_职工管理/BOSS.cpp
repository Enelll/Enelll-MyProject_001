#include "BOSS.h"

BOSS::BOSS(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}

void BOSS::showInfo()
{
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getDeptname()
		<< " \t岗位职责：管理公司" << endl;
}

string BOSS::getDeptname()
{
	return "BOSS";
}
