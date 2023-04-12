#pragma once
#include "worker.h"

class YG:public worker
{
public:
	YG(int id,string name,int Did);
	void showInfo() override;
	string getDeptname() override;
};

