#include "nim_game_handler.h"
#include "nim_game.h"

#include <string>
#include <iostream>

void nim_game_handler::start_game() {
	game_.print();
	std::cout << "From which pile would you like to remove from?\n";
	std::string ans;
	int pile_index = -1;
	while (pile_index == -1) {
		try {
			getline(std::cin, ans);
			int pile_index = stoi(ans) + 1;
		}
		catch (std::exception e) {
			std::cout << "Invalid input!\n";
		}
	}
}

void nim_game_handler::print() {
	std::cout << player_names_[game_.player_turn()] << "'s turn:\n";
	game_.print();
}