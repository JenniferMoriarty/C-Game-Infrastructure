#pragma once
#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_image.h>
#include "player.h";
#include"Platform.h"
#include"Globals.h"
#include"Camera.h"
#include<vector>
using namespace std;


class Engine
{
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *PlayerPic;
	ALLEGRO_BITMAP *backgroundimg;
	ALLEGRO_BITMAP *introscreen;
	ALLEGRO_BITMAP *theImage;
	
	vector<gameObject *> AllGameObjects;
	vector<gameObject *>::iterator iter;

	//game engine variables
	bool doExit;
	bool keys[4];
	bool redraw;
	int state;
	int level;

	// Private functions for internal use only
	void input(ALLEGRO_EVENT ev);
	void update(); 
	void GameObjectSetup();
	void GameObjectClear();

public:
	// The Engine constructor
	Engine();
	void draw();
	void start();
	void init();

};