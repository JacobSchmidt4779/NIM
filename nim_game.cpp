// NIM.cpp : Defines the entry point for the application.
//

#include "nim_game.h"

using namespace std;

nim_game::nim_game(std::initializer_list<int>count) {
	player_turn_ = false;
	for (auto itr = count.begin(); itr != count.end(); ++itr) {
		piles_.push_back(*itr);
	}
}

bool nim_game::remove_from_pile(int pile, int num) {
	if (pile >= piles_.size()) return false;
	if (piles_[pile] < num) return false;
	piles_[pile] -= num;
	return true;
}

void nim_game::print() {
	for (int i = 0; i < piles_.size(); ++i) {
		for (int j = 0; j < piles_[i]; ++j) {
			cout << "| ";
		}
		cout << "\n";
	}
}
