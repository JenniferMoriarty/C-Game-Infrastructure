#include<iostream>
#include<allegro5\allegro.h>
#include "Engine.h"
#include"Camera.h"

using namespace std;

Engine::Engine() //constructor
{
	doExit = false;
	redraw = false;
	state = INTRO;
	level = 1;
}

void Engine::start()
{
	init(); //all the allegro and variable initialisations are hidden in here
	Camera cam;


	while (!doExit)
	{
		if (state == INTRO) {
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			al_draw_bitmap(introscreen, 100, 100, NULL);
			al_flip_display();
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				state = LOAD;
			}
		}

		if (state == LOAD) {
			cout << "LOADING" << endl;
			GameObjectClear();   
			GameObjectSetup();
			cam.Init(AllGameObjects);
			cam.setMapDim(MAP_W, MAP_H);
			state = PLAYING;
		}
		if (state == PLAYING) {
			
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			if (ev.type == ALLEGRO_EVENT_TIMER) {
				update();
			}
			else {
				input(ev);
			}
			if (redraw == true && al_is_event_queue_empty(event_queue)) {
				cam.Update();
				theImage = cam.Render();
				draw();
			}
		}
	}
}


