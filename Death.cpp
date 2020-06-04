#include "Death.h"

Death::Death()
{
    setx(0);
    sety(0);
    setLife(true);
    T.loadFromFile("Images/Death.png");
    S.setTexture(T);
    S.setTextureRect(IntRect(0, 0, 50, 50));
    S.setPosition(getx() * 50, gety() * 50);
}

void Death::Move(int* map, int PlayerX, int PlayerY)
{
	int time = freezetime.getElapsedTime().asMilliseconds();
	if (time > 500)
	{
		if (abs(PlayerX - getx()) > abs(PlayerY - gety()))
		{
			if (getx() > PlayerX) { setx(getx() - 1); S.setTextureRect(IntRect(100, 0, 50, 50)); freezetime.restart(); }
			if (getx() < PlayerX) { setx(getx() + 1); S.setTextureRect(IntRect(150, 0, -50, 50)); freezetime.restart(); }
		}
		else
		{
			if (gety() > PlayerY) { sety(gety() - 1); S.setTextureRect(IntRect(50, 0, 50, 50)); freezetime.restart(); }
			if (gety() < PlayerY) { sety(gety() + 1); S.setTextureRect(IntRect(0, 0, 50, 50)); freezetime.restart(); }
		}
		S.setPosition(getx() * 50, gety() * 50);
	}
}