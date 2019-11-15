#pragma once
#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_primitives.h>
#include"GameObject.h"
class platform : public gameObject {

public:
	platform(int x, int y, int c);
	void draw();
};

