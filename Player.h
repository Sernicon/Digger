#pragma once
#include "Being.h"

class Player :
	public Being
{
private:
	int score;
public:
	Player();

	const int getscore() const;
	void setscore(const int x);

	void Move(int *map);
};