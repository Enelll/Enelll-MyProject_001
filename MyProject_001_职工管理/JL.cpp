#include "JL.h"

JL::JL(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}

void JL::showInfo()
{
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getDeptname()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

string JL::getDeptname()
{
	return "经理";
}
