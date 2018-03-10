#pragma once
#include <vector>
#include <windows.h>

class Player {
public:
	bool r_free;
	bool l_free;
	bool d_free;
	bool u_free;

private:
	int x_player;
	int y_player;
	bool moved;
	char direction;

	int bomb_amount;
	int bomb_strength;

	class Bomb
	{
		int x_bomb;
		int y_bomb;
		int stage;
		int strength;
		int counter;
		std::vector<std::pair<int, int> > fire;
	public:
		Bomb(int strength, int x, int y);
		bool update(HDC &mydc, std::vector<std::pair<int, int> > &obstacles, std::vector<std::pair<int, int> > &bricks, std::vector<std::pair<std::pair<int, int>, std::string> > &power_ups);
		void explode(HDC &mydc, std::vector<std::pair<int, int> > &obstacles, std::vector<std::pair<int, int> > &bricks, std::vector<std::pair<std::pair<int, int>, std::string> > &power_ups);
		void stage_one_animation(HDC &mydc);
		void stage_two_animation(HDC &mydc);
		void stage_three_animation(HDC &mydc);
		void place_grass(int x, int y, HDC &mydc);
		void explosion_animation(HDC &mydc, const char &a, const bool &end, const int &x, const int &y);
		bool collision(int x, int y);
	};
	
	std::vector<Bomb*> bombs;
	std::vector<std::pair<std::pair<int, int>, std::string> > power_ups;
public:
	Player();
	void move(char direction);
	void draw(HDC &mydc);

	void movement_update(std::vector<std::pair<int, int> > & obstacles);
	void bomb_update(HDC &mydc, std::vector<std::pair<int, int> > &obstacles, std::vector<std::pair<int, int> > &bricks);

	bool get_moved();
	char get_direction();
	int get_x();
	int get_y();
	void place_bomb();
	static void extras(HDC &mydc, int x, int y, std::vector<std::pair<int, int> > &bricks, std::vector<std::pair<std::pair<int, int>, std::string> > &power_ups);
	static void power_up_animations(HDC &mydc, int x, int y, std::string power_up);
};