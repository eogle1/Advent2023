#include <iostream>
#include <fstream>

using namespace std;

int getGameID(string game){
    int cutLocation = game.find(":");
    game.erase(cutLocation);
    game.erase(0, 5);
    int ID = stoi(game);
    return ID;
} //working

bool isPullPossible(string pull){
    return false;
} //haven't started

bool isGamePossible(string game){
    bool isPossible = true;
    int cutLocation = game.find(":");
    game.erase(0, cutLocation + 2);
    string pull;
    while(game.find(";") != string::npos){
        pull = game.substr(0, game.find(";"));
        isPossible = isPullPossible(pull);
        if(!isPossible){
            return false;
        }
    }
    return true;
} //everything prior to loop tested, working; loop untested

int main(){
    ifstream inFile;
    inFile.open("input");
    if(!inFile.is_open()){
        cout << "Failed to open file. " << endl;
    }

    string newGame;
    int total = 0;
    while(getline(inFile, newGame)){
        int ID = getGameID(newGame);
        bool isPossible = isGamePossible(newGame);
        if(isPossible){
            total = total + ID;
        }
    }
    cout << total << endl;
    return 0;
}