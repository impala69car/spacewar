#include "player.h"
#include "game_2d.h"
#include "meteor.h"
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <ctime>
Meteor::Meteor(const Game_2d &game_2d, int w, int h, int x, int y, int r, int g, int b, int a) :
	Game_2d(game_2d), wg(w), hg(h), xg(x), yg(y), rg(r), gg(g), gb(b), ag(a)
{

}
void Meteor::draw() const
{
	SDL_Rect meteor;
	meteor.w = wg;
	meteor.h = hg;
	meteor.x = xg;
	meteor.y = yg;
	SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
	SDL_RenderFillRect(_renderer, &meteor);
}
bool Meteor::gravity(int mypos)
{
	SDL_Delay(30);
	xg-=10;
	if(xg<30)
	{
		xg = 800;
		yg = mypos;
		return true;
	}
	else
	{
		return false;
	}
}
int Meteor::Xcollision()
{
	return xg;
}
int Meteor::Ycollision()
{
	return yg;
}
