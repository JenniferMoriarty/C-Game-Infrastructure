#include "Engine.h"
#include"Globals.h"

void Engine::draw()
{
	al_set_target_bitmap(al_get_backbuffer(display));
	//Draw the results of the camera render to the display.
	al_draw_bitmap(theImage, 0, 0, NULL);

	al_flip_display();

}

