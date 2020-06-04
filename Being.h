#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class Being
{
private:
	int x;
	int y;
	bool Life;
public:
	Texture T;
	Sprite S;
	Clock freezetime;

	const int getx() const;
	void setx(const int x);
	const int gety() const;
	void sety(const int y);
	const bool getLife() const;
	void setLife(const bool Life);
};