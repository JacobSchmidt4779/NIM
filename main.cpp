#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>

using namespace std;

class NimGame{
    public:
        string name1,name2 = "";
        vector <int> stacks;
        int remove, stackSelect, pileAmount;
        bool turn, move;

    void generateLists(){
        while (!move){
            cout << "\nHow many piles would you like? (2-10): ";
            cin >> pileAmount;
            move = (pileAmount >= 2 && pileAmount <= 10);
            if (!move){
                cout << "\nInvalid input, please try again.";
            }
        }
        srand(time(0));
        for (int i = 0; i < pileAmount; i++){
            int r = rand() % (20) + 5;
            stacks.push_back(r);
            sleep(.2);
        }
    }

    void displayGame(){
        for (int i = 0; i < stacks.size(); i++){
            if (stacks[i] <=0){
                if (turn == true){
                    cout << "Congrats, " << name1 << "wins!";
                }else {
                    cout << "Congrats, " << name2 << "wins!";
                }
            exit(0);
            }else{
            cout << "Stack " << i+1 << ":";
            for (int j = 0; j < stacks[i]; j++){
                cout << " | ";
            }
            cout << "(" << stacks[i] << ")\n";
            }
        }
        makeMove();
    }

    void minMax(){
        
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
                    displayGame();
                    turn = false;
                    move = true;
                }else{
                    cout << "Invalid move, try again" << endl;
                }
            }
        }
        if (turn == false){
            move = false;
            while (!move){
                cout << name1 << "'s Turn \nWhich stack would you like to remove from? ";
                cin >> stackSelect;
                stackSelect -= 1;
                cout << "\n How many objects would you like to remove 1-3? ";
                cin >> remove;
                if (remove > 0 && remove < 4 && stackSelect < stacks.size()  && stackSelect >= 0){
                    stacks[stackSelect] -= remove;
                    displayGame();
                    turn = true;
                    move = true;
                }else{
                    cout << "Invalid move, try again" << endl;
                }
            }
        }
    }

    void gameSetup(){
        cout << "Enter Player Names \n" << endl << "Player One: ";
        cin >> name1;
        cout << "\nPlayer Two: ";
        cin >> name2;
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