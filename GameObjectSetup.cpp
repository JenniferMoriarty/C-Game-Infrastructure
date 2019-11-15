#include"Engine.h"


void Engine::GameObjectSetup() {

	Player *Boland = new Player();
	AllGameObjects.push_back(Boland);

	if (level == 1) {
		//create bottom row of platforms
		for (int i = 0; i < 50; i++) {
			platform *newPlat = new platform(rand() % MAP_W, rand() % MAP_H, RED);
			AllGameObjects.push_back(newPlat);
	
		}
		//add a for loop to push enemies and items into game here

	}

	if (level == 2) {
		for(int j = 0; j<5; j+=20)
			for (int i = 0; i < 50; i++) {
				platform *newPlat = new platform(rand() % MAP_W, rand() % MAP_H, BLUE);
				AllGameObjects.push_back(newPlat);

			}
		//add a for loop to push enemies and items into game here
	}
	
	//game will still run after level 2, but there'll be no other game objects besides player

}

void Engine::GameObjectClear() {

	AllGameObjects.clear();
}