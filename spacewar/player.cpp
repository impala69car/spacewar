#include "player.h"
#include "meteor.h"
#include <iostream>

Player::Player(const Game_2d &game_2d, int w, int h, int x, int y, int r, int g, int b, int a) :
	Game_2d(game_2d), wg(w), hg(h), xg(x), yg(y), rg(r), gg(g), gb(b), ag(a)
{

}
void Player::draw() const{
	SDL_Rect player;
	player.w = wg;
	player.h = hg;
	player.x = xg;
	player.y = yg;
	SDL_SetRenderDrawColor(_renderer, 200, 0, 200,255);
	SDL_RenderFillRect(_renderer,&player);
}
void Player::flying(SDL_Event &event)
{
	if(event.type==SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_LEFT:
				xg -= 10;
				break;
			case SDLK_RIGHT:
				xg += 10;
				break;
			case SDLK_UP:
				yg -= 10;
				break;
			case SDLK_DOWN:
				yg += 10;
				break;
			default:
				break;
		}
	}
}
bool Player::collisions(int cx,int yc)
{
	int msec = 0;
	if(xg+wg<cx||xg>cx+120||yg+hg<yc||yg>yc+120)
	{
		return false;
	}
	else
	{
		xg=20;
		yg=20;
		return true;
	}
}