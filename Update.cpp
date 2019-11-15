#include "Engine.h"
#include "player.h"


void Engine::update(){
	redraw = true;

	//level update: set to move up a level if you reach right edge of world map
	for (iter = AllGameObjects.begin(); iter != AllGameObjects.end(); iter++) {
		if ((*iter)->getID() == PLAYER) {
			if ((*iter)->getX() > MAP_W - 50) {//switch levels if you get to the end of the map
				level++;
				state = LOAD;
			}
		}
	}
	//update all the stuff
	for (iter = AllGameObjects.begin(); iter != AllGameObjects.end(); iter++) {
		(*iter)->move(keys, AllGameObjects);

	}
}