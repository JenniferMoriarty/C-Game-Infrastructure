#include "Player.h"

Player::Player(){
	xPos = 200;
	yPos = 200;

	xBound = 30;
	yBound = 30;

	gravity = 0;
	xVel = 4;
	yVel = 0;
	ID = PLAYER;
	CanJump = false;
	isOnGround = false;
}

void Player::move(bool TheKeys[4], vector<gameObject*>stuff){
	if (TheKeys[KEY_LEFT]) xVel--;
	if (TheKeys[KEY_RIGHT]) xVel++;
	if (TheKeys[KEY_UP] && CanJump) yVel = -10;

	//collision with platforms
	vector<gameObject *>::iterator iter;
	int x, y;
	for (iter = stuff.begin(); iter != stuff.end(); iter++) {
		if ((*iter)->getID() == PLATFORM) { //only worry about colliding with platforms here!
			x = (*iter)->getX();
			y = (*iter)->getY();

			if (VerticalCollision(xPos, yPos, 32, 32, (*iter)->getX(), (*iter)->getY(), PLATFORM_WIDTH, PLATFORM_HEIGHT, yVel) == 1) {
				gravity = -1.0;
				isOnGround = true;
			}			
		}
	}

	//update player position by adding velocity 
	xPos += xVel;
	yPos += yVel;

	//this doesn't work when going left... some sort of weird order of operations thing?
	//FRICTION 
	if(isOnGround)
		xVel *= .7; //the smaller this number, the greater the friction!


	//GRAVITY (pull down if you're up in the air)
	if (isOnGround == false) {
		yVel += .4; //falling speed
		CanJump = false; //turn off flying/double jumping
	}
	else {
		yVel = 0; //stop downward movement if we're on the ground
		CanJump = true;
	}

	//check if you're falling (so gravity can work)
	if (yPos + 30 > MAP_H)
		isOnGround = true;
	else
		isOnGround = false;

	//set terminal velocity (don't fall too fast)
	if (yVel > 5)
		yVel = 5;

	if (xVel > 5)
		xVel = 5;
	if (xVel < -5)
		xVel = -5;

	//bounds checking (don't go off screen)
	if (xPos < 0)
		xPos = 0;
	if (xPos + 32 > MAP_W)
		xPos = MAP_W - 32;

}


void Player::draw() {
	al_draw_filled_rectangle(xPos, yPos, xPos+30, yPos+30, al_map_rgb(200, 40, 130));

}

