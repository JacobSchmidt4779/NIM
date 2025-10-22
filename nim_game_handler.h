#pragma once

#include "nim_game.h";

#include <string>;

class nim_game_handler {
private:
	std::string player_names_[2];
	nim_game game_;

public:
	nim_game_handler() : player_names_(), game_({ 1, 3, 5, 9 }) { player_names_[0] = "Player 1"; player_names_[1] = "Player 2"; };
	void start_game();
	void print();
};