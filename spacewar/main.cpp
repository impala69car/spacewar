#include "game_2d.h"
#include "player.h"
#include "meteor.h"
#include <iostream>
#include <fstream>
void flying(Game_2d &game,Player &player)
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		player.flying(event);
		game.sr(event);
	}
}
int main(int argc, char **argv)
{
	int deadcount = 0;
	int metcount=0;
	std::string filen = "leaders.txt";
	std::ofstream fout(filen);
	Game_2d game_2d("spacewar", 800,600);
	Player pl(game_2d,20,20,80,50,200,0,200,255);
	Meteor lifecount(game_2d,120,120,700,800,200,0,200,255);
	Meteor meteorid1(game_2d,120,120,700,500,200,0,200,255);
	Meteor meteorid2(game_2d,120,200,700,100,200,0,200,255);
	Meteor meteorid3(game_2d,120,120,950,250,200,0,200,255);
	Meteor meteorid4(game_2d,120,120,1100,50,200,0,200,255);
	int p[13]={0, 50,100,150,200,250,300,350,400,450,500,550,600};
	while(!game_2d.gameOver())
	{
		meteorid1.draw();
		meteorid2.draw();
		meteorid3.draw();
		meteorid4.draw();
		if(meteorid1.gravity(rand() % p[11] + p[0]))
		{
			metcount+=1;
		}
		if(meteorid2.gravity(rand() % p[11] + p[0]))
		{
			metcount+=1;
		}
		if(meteorid3.gravity(rand() % p[11] + p[0]))
		{
			metcount+=1;
		}
		if(meteorid4.gravity(rand() % p[11] + p[0]))
		{
			metcount+=1;
		}
		flying(game_2d,pl);
		pl.draw();
		if(pl.collisions(meteorid1.Xcollision(), meteorid1.Ycollision())==true)
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<metcount<<std::endl;
			std::cout<<metcount<<std::endl;
		}
		if(pl.collisions(meteorid2.Xcollision(), meteorid2.Ycollision())==true)
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<metcount<<std::endl;
			std::cout<<metcount<<std::endl;
		}
		if(pl.collisions(meteorid3.Xcollision(), meteorid3.Ycollision())==true)
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<metcount<<std::endl;
			std::cout<<metcount<<std::endl;
		}
		if(pl.collisions(meteorid4.Xcollision(), meteorid4.Ycollision())==true)
		{
			deadcount+=1;
			fout<<deadcount<<std::endl;
			std::cout<<deadcount<<std::endl;
			fout<<metcount<<std::endl;
			std::cout<<metcount<<std::endl;
		}
		game_2d.recycle();
	}
	fout.close();
	return 0;
}