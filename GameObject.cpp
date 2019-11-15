#include "GameObject.h"


//virtual functions
void gameObject::move(vector<gameObject*>stuff) {}
void gameObject::move(bool TheKeys[4], vector<gameObject*>stuff) {}
void gameObject::draw() {}

//regular functions
int gameObject::getX() { return xPos; }
int gameObject::getY() { return yPos; }
int gameObject::getBoundX() { return xBound; }
int gameObject::getBoundY() { return yBound; }
int gameObject::getID() { return ID; }
void gameObject::setX(int x) { xPos = x; }
void gameObject::setY(int y) { yPos = y; }

int gameObject::VerticalCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, int ydir) {
	if ((ydir >= 0) &&
		(x1 + w1 > x2) &&
		(x1 < x2 + w2) &&
		(y1 + h1 > y2) && 
		(y1 < y2)) {
		
		return 1;
	}
	else
		return false;
}

