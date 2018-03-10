#pragma once
#include <vector>
#include "Player.h"

class Game {
	const int turf_size = 13;

	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	std::vector<std::pair<int, int> > obstacles;
	std::vector<std::pair<int, int> > bricks;
	Player player;

public:
	Game();
	void update();
	void input();
	bool check_obstacles(int x, int y);
	void draw();

	void place_grass(int x, int y);

	void place_solid_wall(int x, int y);
	
	void place_brick(int x, int y);

	void brick_gen();

	~Game();
};