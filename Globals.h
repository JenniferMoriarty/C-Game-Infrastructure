#pragma once
#include"GameObject.h"
//constants: variables that shouldn't change once the game starts
const float FPS = 60;
const int SCREEN_W = 1200;
const int SCREEN_H = 800;
const int PLATFORM_WIDTH = 150;
const int PLATFORM_HEIGHT = 50;
const int MAP_W = 4000;
const int MAP_H = 2000;

enum DIRECTIONS { UP, DOWN, LEFT, RIGHT };
enum MYKEYS { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };
enum ITEM_IDS { ENEMY, PLATFORM, PLAYER, ITEM };
enum LEVELS {INTRO, PLAYING, LOAD, PAUSE, END};
enum COLOR {BLUE, RED, YELLOW, GREEN};


