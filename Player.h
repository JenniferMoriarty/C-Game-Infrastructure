#pragma once
#include <allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include<iostream>
#include"GameObject.h"
#include"Globals.h"

using namespace std;

class Player : public gameObject
{
	
private:
	int dir;
	bool CanJump;
	float gravity;

public:

	Player();

	void move(bool TheKeys[4], vector<gameObject*>stuff);

	void draw();

};
