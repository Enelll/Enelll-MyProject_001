#pragma once
#include "worker.h"

class BOSS :public worker
{
public:
	BOSS(int id, string name, int Did);
	void showInfo() override;
	string getDeptname() override;
};

