#include "BOSS.h"

BOSS::BOSS(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}

void BOSS::showInfo()
{
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getDeptname()
		<< " \t��λְ�𣺹���˾" << endl;
}

string BOSS::getDeptname()
{
	return "BOSS";
}
