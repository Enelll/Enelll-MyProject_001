#include "YG.h"

YG::YG(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}

void YG::showInfo()
{
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getDeptname()
		<< " \t岗位职责：完成经理交给的任务" << endl;
}

string YG::getDeptname()
{
	return "员工";
}
