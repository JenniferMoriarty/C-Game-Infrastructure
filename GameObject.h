#pragma once
#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>
#include<vector>
using namespace std;

class gameObject {
private: 

protected: 
	int xPos;
	int yPos;
	float xVel;
	float yVel;
	int ID;
	int xBound;
	int yBound;
	bool isOnGround;
	int Color;
	ALLEGRO_BITMAP *pic;

public: 
	int getX();
	int getY();
	int getID();
	int getBoundX();
	int getBoundY();
	void setX(int x);
	void setY(int y);

	//virtual functions
	virtual void move(bool TheKeys[4], vector<gameObject*>stuff);
	virtual void move(vector<gameObject*>stuff);
	virtual void draw();
	int VerticalCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, int ydir);
};


