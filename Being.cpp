#include "Being.h"

const int Being::getx() const { return x; }
void Being::setx(const int x) { this->x = x; }
const int Being::gety() const { return y; }
void Being::sety(const int y) { this->y = y; }
const bool Being::getLife() const { return Life; }
void Being::setLife(const bool Life) { this->Life = Life; }