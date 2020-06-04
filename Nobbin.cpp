#include "Nobbin.h"

Nobbin::Nobbin()
{
	setx(0);
	sety(0);
	setLife(true);
    this->soview = 4;
	T.loadFromFile("Images/Timobbin.png");
	S.setTexture(T);
	S.setTextureRect(IntRect(0, 0, 50, 50));
	S.setPosition(getx() * 50, gety() * 50);
}

void Nobbin::Move(int* map)
{
    int mind = rand() % 200 + 1;
    int turn = rand() % 3 + 1;
    switch (mind)
    {
    case 47:
        soview = 1;
        S.setTextureRect(IntRect(150, 0, -50, 50));
        break;
    case 99:
        soview = 2;
        S.setTextureRect(IntRect(50, 0, 50, 50));
        break;
    case 148:
        soview = 3;
        S.setTextureRect(IntRect(0, 0, 50, 50));
        break;
    case 195:
        soview = 4;
        S.setTextureRect(IntRect(100, 0, 50, 50));
        break;
    default:
        break;
    }
    switch (soview)
    {
    case 1:
        if (*((int*)map + (gety() * 20) + getx() + 1) != 0)
        {
            switch (turn)
            {
            case 1:
                soview = 2;
                S.setTextureRect(IntRect(50, 0, 50, 50));
                break;
            case 2:
                soview = 3;
                S.setTextureRect(IntRect(0, 0, 50, 50));
                break;
            case 3:
                soview = 4;
                S.setTextureRect(IntRect(100, 0, 50, 50));
                break;
            }
        }
        break;
    case 2:
        if (*((int*)map + ((gety() - 1) * 20) + getx()) != 0)
        {
            switch (turn)
            {
            case 1:
                soview = 1;
                S.setTextureRect(IntRect(150, 0, -50, 50));
                break;
            case 2:
                soview = 3;
                S.setTextureRect(IntRect(0, 0, 50, 50));
                break;
            case 3:
                soview = 4;
                S.setTextureRect(IntRect(100, 0, 50, 50));
                break;
            }
        }
        break;
    case 3:
        if (*((int*)map + ((gety() + 1) * 20) + getx()) != 0)
        {
            switch (turn)
            {
            case 1:
                soview = 1;
                S.setTextureRect(IntRect(150, 0, -50, 50));
                break;
            case 2:
                soview = 2;
                S.setTextureRect(IntRect(50, 0, 50, 50));
                break;
            case 3:
                soview = 4;
                S.setTextureRect(IntRect(100, 0, 50, 50));
                break;
            }
        }
        break;
    case 4:
        if (*((int*)map + (gety() * 20) + getx() - 1) != 0)
        {
            switch (turn)
            {
            case 1:
                soview = 1;
                S.setTextureRect(IntRect(150, 0, -50, 50));
                break;
            case 2:
                soview = 2;
                S.setTextureRect(IntRect(50, 0, 50, 50));
                break;
            case 3:
                soview = 3;
                S.setTextureRect(IntRect(0, 0, 50, 50));
                break;
            }
        }
        break;
    }

    int time = freezetime.getElapsedTime().asMilliseconds();
    if (time > 170)
    {
        switch (soview)
        {
        case 1:
            if (*((int*)map + (gety() * 20) + getx() + 1) == 0)
                setx(getx() + 1);
            break;
        case 2:
            if (*((int*)map + ((gety() - 1) * 20) + getx()) == 0)
                sety(gety() - 1);
            break;
        case 3:
            if (*((int*)map + ((gety() + 1) * 20) + getx()) == 0)
                sety(gety() + 1);
            break;
        case 4:
            if (*((int*)map + (gety() * 20) + getx() - 1) == 0)
                setx(getx() - 1);
            break;
        }
        S.setPosition(getx() * 50, gety() * 50);
        freezetime.restart();
    }
}