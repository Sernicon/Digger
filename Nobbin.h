#pragma once
#include "Being.h"
class Nobbin :
	public Being
{
private:
	int soview;
public:
	Nobbin();

	void Move(int* map);
};