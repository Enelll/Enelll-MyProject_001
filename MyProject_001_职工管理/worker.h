#pragma once
#include <string>
#include <iostream>
using namespace std;

class worker
{
public:
	int m_id;
	std::string m_name;
	int m_Did;

	virtual void showInfo()=0;
	virtual string getDeptname()=0;
};

