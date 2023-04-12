#pragma once
#include "worker.h"

class JL:public worker
{
public:
	JL(int id,string name,int Did);
	void showInfo() override;
	string getDeptname() override;
};

