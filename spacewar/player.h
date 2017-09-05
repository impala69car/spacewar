#pragma once
#include "meteor.h"
#include "game_2d.h"
class Player : public Game_2d
{
public:
	Player(const Game_2d &game_2d,int w, int h, int x, int y, int r,int g,int b,int a);
	
	void draw() const;
	void flying(SDL_Event &event);
	bool collisions(int cx,int yc);
private:
	int wg, hg, xg, yg, rg, gg, gb, ag;
};