#pragma once
#include "Being.h"
class Death :
	public Being
{
public:
	Death();

	void Move(int* map, int PlayerX, int PlayerY);
};