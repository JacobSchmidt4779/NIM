// NIM.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>

class nim_game {
private:
	bool player_turn_;
	std::vector<int> piles_;

public: 
	nim_game() : player_turn_(false), piles_() {};
	nim_game(std::initializer_list<int> count);
	bool player_turn() const { return player_turn_; };
	bool remove_from_pile(int pile, int num);
	void print();
};
