#include "Engine.h"
void Engine::init() {
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();

	display = al_create_display(SCREEN_W, SCREEN_H);
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();

	al_start_timer(timer);
	srand(time(NULL));


	for (int i = 0; i < 4; i++)
		keys[i] = false;


	introscreen = al_load_bitmap("intro.png");

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

}