#include<iostream>
#include"game.hpp"
#include"exceptions.hpp"
#include<functional>

int main()
{
	meme::Game game{"../../audio/"};

	try
	{
		game.telephone.Load_sound_effects(2);

		game.offices.push_back(meme::Office{"../../img/office.png",sf::Vector2i{1200,1000}});
		game.offices[0].doors.push_back(meme::Door{"../../img/door.png",{150,700},{150,700},5});
		game.offices[0].doors[0].door_sound = game.telephone.Get_sound_effect_ptr(0);
		game.offices[0].doors[0].light_sound = game.telephone.Get_sound_effect_ptr(1);

		std::function<void()> function1, function2;
		function1 = std::bind(&meme::Door::Close , &game.offices[0].doors[0]);
		function2 = std::bind(&meme::Door::Open, &game.offices[0].doors[0]);

		game.offices[0].buttons.emplace_back(meme::Button{"../../img/button.png",{500,400}, {53,50}, {function1,function2}});

		game.Resereve_new_window(game.offices[0],"Office",sf::VideoMode{{1200,1000}});
		std::cerr << game.offices[0].window_id;
	}
	catch(meme::Exeption x)
	{
		std::cerr << x.what_happen;
		return 0;
	}

	while(game.Is_any_window_open())
	{
		game.Render_windows();
		game.Events();
	}

	return 0;
}
