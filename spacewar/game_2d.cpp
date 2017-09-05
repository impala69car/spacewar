#include "game_2d.h"
#include <iostream>

using namespace std;
Game_2d::Game_2d(const string &title, int width,int height) :
	_title(title), wgame(width),hgame(height)
{
	_closed = !init();
}

Game_2d::~Game_2d()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_game_2d);
	SDL_Quit();
}
bool Game_2d::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) !=0)
	{
		std::cerr<< "FAILED to initialize SDL. \n";
		return 0;
	}
	_game_2d = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		wgame,hgame,0);
	if(_game_2d==nullptr)
	{
		std::cerr<<"Failed to create wondow./n";
		return 0;
	}
	_renderer = SDL_CreateRenderer(_game_2d, -1,SDL_RENDERER_ACCELERATED);
	if(_renderer==nullptr)
	{
		std::cerr << "Failed to create renderer.\n";
		return 0;
	}
	return true;
}
void Game_2d::recycle() const
{
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer,0,0,200,255);
	SDL_RenderClear(_renderer);
}
void Game_2d::sr(SDL_Event &event)
{
	switch (event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			std::cout<<"You clicked your mouse.\n";
			break;
		default:
			break;
		}
}