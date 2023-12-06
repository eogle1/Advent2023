#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findNumber(string inputLine){
    int firstNumber = 0;
    int lastNumber = 0;
    bool foundFirstNumber = false;
    for (int i = 0; i < inputLine.length(); i++){
        if (inputLine.at(i) > 47 && inputLine.at(i) < 58){
            lastNumber = inputLine.at(i) - 48;
            if (!foundFirstNumber){
                firstNumber = inputLine.at(i) - 48;
                foundFirstNumber = true;
            }
        }
    }
    int total = firstNumber*10 + lastNumber;
    return total;
}

int main(){
    ifstream inFile;
    inFile.open("input.txt");
    if(!inFile.is_open()){
        throw exception();
    }

    string newLine;
    int total = 0;
    while(getline(inFile, newLine)){
        total = total + findNumber(newLine);
    }
    cout << total << endl;
    return 0;
}