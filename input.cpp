#include "Engine.h"
#include"Globals.h"

void Engine::input(ALLEGRO_EVENT ev)
{
	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		doExit = true;
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		
		switch (ev.keyboard.keycode) {
	
		case ALLEGRO_KEY_LEFT:
			keys[LEFT] = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			keys[RIGHT] = true;
			break;
		case ALLEGRO_KEY_UP:
			keys[UP] = true;
			break;
		case ALLEGRO_KEY_DOWN:
			keys[DOWN] = true;
			break;

		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			keys[UP] = false;
			break;
		case ALLEGRO_KEY_DOWN:
			keys[DOWN] = false;
			break;
		case ALLEGRO_KEY_LEFT:
			keys[LEFT] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			keys[RIGHT] = false;
			break;
		case ALLEGRO_KEY_ESCAPE:
			doExit = true;
			break;
		}
	}

}