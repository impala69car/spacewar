#pragma once

#pragma once
#include "game_2d.h"
class Meteor : public Game_2d
{
public:
	Meteor(const Game_2d &game_2d,int w, int h, int x, int y, int r,int g,int b,int a);
	void draw() const;
	bool gravity(int mypos);
	int Xcollision();
	int Ycollision();
private:
	int wg, hg, xg, yg, rg, gg, gb, ag;
};