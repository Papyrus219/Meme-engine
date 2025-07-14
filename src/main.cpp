#include<iostream>
#include<functional>
#include<print>
#include"game.hpp"
#include"exceptions.hpp"
#include<vector>

int main()
{
	meme::Game game{"../../audio/"};

	try
	{
		game.telephone.Load_sound_effects(2);

		game.offices.push_back(meme::Office{"../../img/office.png",sf::Vector2i{1200,1000}});

		meme::Office &office1 = game.offices[0];

		game.Resereve_new_window(office1,"Office",sf::VideoMode{{1200,1000}});

		office1.Load_door_textures("../../img/doors",1);
		office1.Load_button_textures("../../img/buttons",1);

		office1.doors.push_back(meme::Door{game.offices[0].door_textures[0],{175,350},{150,700},5,true});
		office1.doors.push_back(meme::Door{game.offices[0].door_textures[0],{1020,340},{150,700},5});

		meme::Door &door1 = office1.doors[0];
		meme::Door &door2 = office1.doors[1];

		door1.door_sound = game.telephone.Get_sound_effect_ptr(0);
		door1.light_sound = game.telephone.Get_sound_effect_ptr(1);
		door2.door_sound = game.telephone.Get_sound_effect_ptr(0);
		door2.light_sound = game.telephone.Get_sound_effect_ptr(1);

		std::function<void()> door_f1_cl = std::bind(&meme::Door::Close, &door1);
		std::function<void()> door_f1_op = std::bind(&meme::Door::Open, &door1);
		std::function<void()> door_f2_cl = std::bind(&meme::Door::Close, &door2);
		std::function<void()> door_f2_op = std::bind(&meme::Door::Open, &door2);

		office1.buttons.push_back(meme::Button{office1.button_textures[0],{200,400},{28,25},{door_f1_op,door_f1_cl}});
		office1.buttons.push_back(meme::Button{office1.button_textures[0],{970,400},{28,25},{door_f2_op,door_f2_cl}});

		std::function<void()> door_f1_lu = std::bind(&meme::Door::Light_up, &door1);
		std::function<void()> door_f1_ld = std::bind(&meme::Door::Light_down, &door1);
		std::function<void()> door_f2_lu = std::bind(&meme::Door::Light_up, &door2);
		std::function<void()> door_f2_ld = std::bind(&meme::Door::Light_down, &door2);

		office1.buttons.push_back(meme::Button{office1.button_textures[0],{200,450},{28,25},{door_f1_ld,door_f1_lu}});
		office1.buttons.push_back(meme::Button{office1.button_textures[0],{970,450},{28,25},{door_f2_ld,door_f2_lu}});

		game.cameras.push_back(meme::Cameras{"../../img/cameras/cameras1.png",{1000,667}});
		meme::Cameras &cameras1 = game.cameras[0];

		cameras1.Cameras_setup({ {0,1,3,4,7,8,10,11},{0,1},{0,1},{0,13},{0,19},{0,3},{0,3},{0,1},{0,3},{0,1,7,8},{0,3,7,10}});
		game.Resereve_new_window(cameras1,"Cameras",sf::VideoMode{{1000,667}});

	}
	catch(meme::Camera_Exeption x)
	{
		x.What_happen();
		return 0;
	}
	catch(meme::Exeption x)
	{
		x.What_happen();
		return 0;
	}

	while(game.Is_any_window_open())
	{
		game.Render_windows();
		game.Events();
	}

	return 0;
}

