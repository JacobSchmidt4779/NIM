#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

class NimGame{
    public:
        string name1,name2 = "";
        vector <int> stacks;
        int remove, stackSelect, pileAmount;
        bool turn, move, isMaximizing;

        int minimax(vector<int> stacks, bool isMaximizing) {
        int score = evaluate(stacks, isMaximizing);
        if (score != 2)
            return score;   

        vector<vector<int>> nextStates = possibleNewStates(stacks);
        vector<int> scores;

        for (auto& newStacks : nextStates) {
            scores.push_back(minimax(newStacks, !isMaximizing));
        }

        if (isMaximizing)
            return *max_element(scores.begin(), scores.end());
        else
            return *min_element(scores.begin(), scores.end());
    }

    vector<vector<int>> possibleNewStates(vector<int> stacks) {
    vector<vector<int>> result; 

    for (size_t i = 0; i < stacks.size(); ++i) {
        for (int take = 1; take <= 3 && take <= stacks[i]; ++take) {
            vector<int> newState = stacks;
            newState[i] -= take;
            result.push_back(newState);     
        }
    }
    return result;
}

    int evaluate(const vector<int>& stacks, bool isMaximizing) {
        bool allEmpty = all_of(stacks.begin(), stacks.end(), [](int x){ return x == 0; });

        if (allEmpty)
            return isMaximizing ? 1 : -1;
        return 2;
    }

    vector<int> bestMove(vector<int> stacks) {
        int bestScore = -1000;
        vector<int> bestStacks = stacks;

        vector<vector<int>> nextStates = possibleNewStates(stacks);
        for (auto& newStacks : nextStates) {
            int score = minimax(newStacks, false);
            if (score > bestScore) {
                bestScore = score;
                bestStacks = newStacks;
            }
        }
        return bestStacks;
    }


    void generateLists(){
        while (!move){
            cout << "\nHow many piles would you like? (2-5): ";
            cin >> pileAmount;
            move = (pileAmount >= 2 && pileAmount <= 5);
            if (!move){
                cout << "\nInvalid input, please try again.";
            }
        }
        srand(time(0));
        for (int i = 0; i < pileAmount; i++){
            int r = rand() % (3) + 3;
            stacks.push_back(r);
            sleep(.2);
        }
    }

    void displayGame(){
        int num = 0;
        for (int i = 0; i < stacks.size(); i++){
            if (stacks[i] < 0){
                stacks[i] = 0;
            }
        }
        for (int n: stacks){
            num+=n;
        }
        if (num <= 0){
            if (turn == true){
                cout << "Congrats, " << name1 << "wins!";
            }else {
                cout << "Congrats, " << name2 << "wins!";
            }
        exit(0);
        }
        for (int i = 0; i < stacks.size(); i++){
            cout << "Stack " << i+1 << ":";
            for (int j = 0; j < stacks[i]; j++){
                cout << " | ";
            }
            cout << "(" << stacks[i] << ")\n";
        }
        makeMove();
    }

    
    
    void makeMove(){
        if (turn == true){
            move = false;
            while (!move){
                cout << name1 << "'s Turn \nWhich stack would you like to remove from? ";
                cin >> stackSelect;
                stackSelect -= 1;
                cout << "\n How many objects would you like to remove 1-3? ";
                cin >> remove;
                if (remove > 0 && remove < 4 && stackSelect < stacks.size()  && stackSelect >= 0){
                    stacks[stackSelect] -= remove;
                    turn = false;
                    move = true;
                    displayGame();
                }else{
                    cout << "Invalid move, try again" << endl;
                }
            }
        }
        if (turn == false) {
            cout << name2 << "'s Turn (AI is thinking...)\n";
            stacks = bestMove(stacks);
            turn = true;
            displayGame();
        }

    }

    void gameSetup(){
        cout << "Enter Player Names \n" << endl << "Player One: ";
        cin >> name1;
        name2 = "AI Opponent";
        cout << "\nPlayer Two: " << name2 << endl;
        turn = true;
        generateLists();
        displayGame();
    }
};

int main(){
    NimGame game;
    game.gameSetup();

    return 0;
}