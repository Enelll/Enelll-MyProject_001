#include "YG.h"

YG::YG(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}

void YG::showInfo()
{
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getDeptname()
		<< " \t��λְ����ɾ�����������" << endl;
}

string YG::getDeptname()
{
	return "Ա��";
}
