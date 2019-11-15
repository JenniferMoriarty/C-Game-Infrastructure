#include"platform.h"
#include"globals.h"

platform::platform(int x, int y, int c) {
	xPos = x;
	yPos = y;
	//pic = img;
	ID = PLATFORM;
	Color = c;
}
void platform::draw() {
	//al_draw_bitmap(pic, xPos, yPos, NULL);
	if (Color == RED) {
		al_draw_filled_rectangle(xPos, yPos, xPos + PLATFORM_WIDTH, yPos + PLATFORM_HEIGHT, al_map_rgb(190, 89, 240));
		al_draw_rectangle(xPos, yPos, xPos + PLATFORM_WIDTH, yPos + PLATFORM_HEIGHT, al_map_rgb(20, 20, 100), 3);
	}
	if (Color == BLUE) {
		al_draw_filled_rectangle(xPos, yPos, xPos + PLATFORM_WIDTH, yPos + PLATFORM_HEIGHT, al_map_rgb(90, 89, 240));
		al_draw_rectangle(xPos, yPos, xPos + PLATFORM_WIDTH, yPos + PLATFORM_HEIGHT, al_map_rgb(20, 20, 100), 3);
	}
}
