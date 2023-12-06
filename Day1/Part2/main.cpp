#include <iostream>
#include <fstream>

using namespace std;

int findNumber(string inputString){
    int total = 0;
    int firstNumber = 0;
    int lastNumber = 0;
    bool foundFirstNumber = false;
    for (int i = 0; i < inputString.length(); i++){
        if ((inputString.at(i) > 47 && inputString.at(i) < 58)){
            lastNumber = inputString.at(i) - 48;
            if (!foundFirstNumber){
                firstNumber = inputString.at(i) - 48;
                foundFirstNumber = true;
            }
        }
        else{
            int numberFound = 0;
            string possibleNumber;
            if(i < inputString.length() - 4){
                possibleNumber = inputString.substr(i, 5);
                if(possibleNumber == "three"){
                    numberFound = 3;
                }
                if(possibleNumber == "seven"){
                    numberFound = 7;
                }
                else if(possibleNumber == "eight"){
                    numberFound = 8;
                }
            }
            if(i < inputString.length() - 3){
                possibleNumber = inputString.substr(i, 4);
                if(possibleNumber == "four"){
                    numberFound = 4;
                }
                if(possibleNumber == "five"){
                    numberFound = 5;
                }
                if(possibleNumber == "nine"){
                    numberFound = 9;
                }
            }
            if(i < inputString.length() - 2){
                possibleNumber = inputString.substr(i, 3);
                if(possibleNumber == "one"){
                    numberFound = 1;
                }
                if(possibleNumber == "two"){
                    numberFound = 2;
                }
                if(possibleNumber == "six"){
                    numberFound = 6;
                }
            }
            if (numberFound != 0){
                lastNumber = numberFound;
                if (!foundFirstNumber){
                    firstNumber = numberFound;
                    foundFirstNumber = true;
                }
            }
        }
    }
    total = firstNumber*10 + lastNumber;
    return total;
}

int main(){
    ifstream inFile;
    inFile.open("input.txt");
    if(!inFile.is_open()){
        cout << "Failed to open file. " << endl;
    }

    string newLine;
    int total = 0;
    while(getline(inFile, newLine)){
        total = total + findNumber(newLine);
    }
    cout << total << endl;
    return 0;
}