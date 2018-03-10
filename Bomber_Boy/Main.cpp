#include <iostream>
#include <windows.h>
#include <ctime>

#include "Game.h"

int main() {
	for (int i = 0; i < 20; i++) {
		std::cout << std::endl;
	}
	Sleep(100);

	bool game_over = false;
	srand(time(0));

	Game game;
	while (!game_over) {
		game.update();
		Sleep(30);
	}

	std::cin.ignore();
	return 0;
}