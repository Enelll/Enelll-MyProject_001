#include "JL.h"

JL::JL(int id, string name, int Did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Did = Did;
}

void JL::showInfo()
{
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getDeptname()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

string JL::getDeptname()
{
	return "����";
}
