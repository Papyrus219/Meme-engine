#include<iostream>
#include"game.hpp"
#include"exceptions.hpp"

int main()
{

	meme::Game game;

	try
	{
		game.window = new sf::RenderWindow;
		game.window->create(sf::VideoMode{{1200,1000}},"office");

		game.offices.push_back(meme::office{"../../img/office.png",sf::Vector2i{1200,1000}});
		game.offices[0].doors.push_back(meme::Door{"../../img/door.png",{100,200},{1020,340},5});
	}
	catch(meme::Exeption x)
	{
		std::cerr << x.what_happen;
		return 0;
	}

	while(true)
	{
		game.Render_office();
	}

	return 0;
}
