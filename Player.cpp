#include "Player.h"

Player::Player()
{
	setx(12);
	sety(3);
	setLife(true);
	this->score = 0;
	T.loadFromFile("Images/GG.png");
	S.setTexture(T);
	S.setTextureRect(IntRect(0, 0, 50, 50));
	S.setPosition(getx() * 50, gety() * 50);
}

const int Player::getscore() const { return score; }
void Player::setscore(const int score) { this->score = score; }

void Player::Move(int* map)
{
	int time = freezetime.getElapsedTime().asMilliseconds();
	if (time > 160)
	{
			if ((Keyboard::isKeyPressed(Keyboard::A)) && (*((int*)map + (gety() * 20) + getx() - 1) != 3))
			{ setx(getx() - 1); S.setTextureRect(IntRect(100, 0, 50, 50)); freezetime.restart(); } else
			if ((Keyboard::isKeyPressed(Keyboard::D)) && (*((int*)map + (gety() * 20) + getx() + 1) != 3))
			{ setx(getx() + 1); S.setTextureRect(IntRect(150, 0, -50, 50)); freezetime.restart(); } else
			if ((Keyboard::isKeyPressed(Keyboard::W)) && (*((int*)map + ((gety() - 1) * 20) + getx()) != 3))
			{ sety(gety() - 1); S.setTextureRect(IntRect(50, 0, 50, 50)); freezetime.restart(); } else
			if ((Keyboard::isKeyPressed(Keyboard::S)) && (*((int*)map + ((gety() + 1) * 20) + getx()) != 3))
			{ sety(gety() + 1); S.setTextureRect(IntRect(0, 0, 50, 50)); freezetime.restart(); } else
			S.setTextureRect(IntRect(0, 0, 50, 50));
			S.setPosition(getx() * 50, gety() * 50);
	}
}