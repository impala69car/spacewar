#pragma once
#include <string>
#include <SDL.h>

class Game_2d
{
public:
	Game_2d(const std::string &title, int width, int height);
	~Game_2d();
	void recycle() const;
	void sr(SDL_Event &event);
	inline bool gameOver() const { return false; };

private:
	bool init();
private:
	std::string _title;
	int wgame;
	int hgame;

	bool _closed;
	SDL_Window *_game_2d;
protected:
	SDL_Renderer *_renderer;
};