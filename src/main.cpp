#include<iostream>
#include<vector>
#include<functional>
#include<print>
#include"game.hpp"
#include"system/events.hpp"
#include"exceptions.hpp"
#include"animatrons/papyrus.hpp"


int main()
{
	meme::Game game{"../../audio/"};

	try
	{
		game.telephone.Load_sound_effects(2);
		game.time_manager.emplace(9,64780);

		sf::Vector2i office_sprite_size{1200,1000};
		game.offices.push_back(meme::Office{"../../img/office.png",office_sprite_size});

		meme::Office &office1 = game.offices[0];
		office1.parameters_ptr = std::make_shared<meme::Parameters>(50000);

		game.Resereve_new_window(office1,"Office",sf::VideoMode{{1200,1000}});

		office1.Load_door_textures("../../img/doors",1);
		office1.Load_button_textures("../../img/buttons",1);

		sf::Vector2f left_door_possition{175,350};
		sf::Vector2f right_door_possition{1020,340};
		sf::Vector2i door_size{150,700};
		int door_variants_amount{5};
		bool flip_sprite{true};
		office1.doors.push_back(meme::Door{game.offices[0].door_textures[0],left_door_possition,door_size,door_variants_amount,meme::Direction::LEFT,flip_sprite});
		office1.doors.push_back(meme::Door{game.offices[0].door_textures[0],right_door_possition,door_size,door_variants_amount,meme::Direction::RIGHT});

		meme::Door &left_door = office1.doors[0];
		meme::Door &right_door = office1.doors[1];

		left_door.subject.Add_observer(office1.parameters_ptr.get());
		right_door.subject.Add_observer(office1.parameters_ptr.get());

		left_door.door_sound = game.telephone.Get_sound_effect_ptr(0);
		left_door.light_sound = game.telephone.Get_sound_effect_ptr(1);
		right_door.door_sound = game.telephone.Get_sound_effect_ptr(0);
		right_door.light_sound = game.telephone.Get_sound_effect_ptr(1);

		std::function<void()> left_door_f_close = std::bind(&meme::Door::Close, &left_door);
		std::function<void()> left_door_f_open = std::bind(&meme::Door::Open, &left_door);
		std::function<void()> right_door_f_close = std::bind(&meme::Door::Close, &right_door);
		std::function<void()> right_door_f_open = std::bind(&meme::Door::Open, &right_door);
		sf::Vector2i power_button_size{28,25};
		sf::Vector2f power_button1_possition{200,400};
		sf::Vector2f power_button2_possition{970,400};
		office1.buttons.push_back(meme::Button{office1.button_textures[0],power_button1_possition,power_button_size,{left_door_f_open,left_door_f_close}});
		office1.buttons.push_back(meme::Button{office1.button_textures[0],power_button2_possition,power_button_size,{right_door_f_open,right_door_f_close}});

		std::function<void()> door1_f_light_up = std::bind(&meme::Door::Light_up, &left_door);
		std::function<void()> door1_f_light_down = std::bind(&meme::Door::Light_down, &left_door);
		std::function<void()> door2_f_light_up = std::bind(&meme::Door::Light_up, &right_door);
		std::function<void()> door2_f_light_down = std::bind(&meme::Door::Light_down, &right_door);
		sf::Vector2i light_button_size{28,25};
		sf::Vector2f light_button1_possition{200,450};
		sf::Vector2f light_button2_possition{970,450};
		office1.buttons.push_back(meme::Button{office1.button_textures[0],light_button1_possition,light_button_size,{door1_f_light_down,door1_f_light_up}});
		office1.buttons.push_back(meme::Button{office1.button_textures[0],light_button2_possition,light_button_size,{door2_f_light_down,door2_f_light_up}});

		sf::Vector2i camera_sprite_size{1000,667};
		game.cameras.push_back(meme::Cameras{"../../img/cameras/cameras1.png",camera_sprite_size});
		meme::Cameras &cameras1 = game.cameras[0];

		std::vector<std::vector<int>> cameras_animatron_values{{0,1,3,4,7,8,10,11},{0,1},{0,1},{0,13,26,39,52,65},{0,19},{0,3},{0,3},{0,1},{0,3},{0,1,7,8},{0,3,7,10}};
		cameras1.Cameras_setup(std::move(cameras_animatron_values));

		sf::Vector2i camera_panel_sprite_size{300,300};
		sf::Vector2f camera_panel_possition{0,0};
		std::vector<sf::Vector2i> camera_panel_hitboxes_possitions{{89,20},{49,61},{129,60},{18,125},{4,18},{223,23},{181,131},{94,160},{240,128},{104,240},{233,241}};
		sf::Vector2f camera_panel_hit_box_size{47,33};
		cameras1.Camera_panel_setup("../../img/cameras/camera_panel1.png",camera_panel_sprite_size,camera_panel_possition,camera_panel_hitboxes_possitions,camera_panel_hit_box_size);
		game.Resereve_new_window(cameras1,"Cameras",sf::VideoMode{{1000,667}});

		game.jumpscare_textures.emplace_back("../../img/animatrons/Jumpscares1.png");

		std::shared_ptr<meme::Papyrus> papyrus = std::make_shared<meme::Papyrus>(1,std::vector{0,1,2,7,9},cameras1,&office1,20000);
		left_door.subject.Add_observer(papyrus.get());
		papyrus->subject.Add_observer(&left_door);
		papyrus->Setup_jumpscare(game.jumpscare_textures[0],{1200,1000},{{0,2000},{1320,2000}},22,2);
		papyrus->dificulty = 20;
		game.animatrons.push_back(std::static_pointer_cast<meme::Animatron>(papyrus));
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

	try
	{
		game.Start_night();

		while(game.Is_any_window_open())
		{
			game.Render_windows();
			game.Events();
			game.Animatron_update();

			game.Tic();
		}
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

	return 0;
}
