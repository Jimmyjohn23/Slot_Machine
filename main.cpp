#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function prototypes
char randomChar(int randomIndex, char Letters[]);
char randomchar1(int randomIndex1, char Letters[]);
char randomchar2(int randomIndex2, char Letters[]);
bool iWon(char Num1, char Num2, char Num3);

int main(){
    // Seed the random number generator
    srand(time(0));
    //test
    // Welcome message and instructions
    int playerMoney;
    bool playAgain = 1;
    cout << "Welcome to the slot machine game!" << endl;
    cout << "Enter $10 to play the game!" << endl;
    cin >> playerMoney;
    
    // Check if the player has enough money to play the game
    bool money = playerMoney == 10;
    if (money){
        cout << "You have $" << playerMoney << " left." << endl;
    }
    else{
        cout << "Invaild amount of money." << endl;
        return 0;
    }

    // Slot machine game
    do{
        char Num1, Num2, Num3;
        char Letters[] = {'$', 'X', '7', '#'};
        Num1 = randomChar(0, Letters);
        Num2 = randomchar1(0, Letters);
        Num3 = randomchar2(0, Letters);
        playerMoney -= 1;

        cout << "The slot machine shows: " << Num1 << Num2 << Num3 << endl;
        if (iWon(Num1, Num2, Num3)&& Num1 == 'X'){
            playerMoney += 10;
            cout << "You won $10!" << endl;
        
        }
         else if (iWon(Num1, Num2, Num3)&& Num1 == '7'){
            playerMoney += 100;
            cout << "You won $100!" << endl;
        
        }
        else if (iWon(Num1, Num2, Num3)&& Num1 == '#'){
            playerMoney += 25;
            cout << "You won $25!" << endl;
    
        }
        else if (iWon(Num1, Num2, Num3)&& Num1 == '$'){
            playerMoney += 50;
            cout << "You won $50!" << endl;
         }
        else{
            cout << "You lost!" << endl;
        }
        cout << "You have $" << playerMoney << " left." << endl;
        cout << "Do you want to play again? (Yes = 1, No = 0)" << endl;
        cin >> playAgain;
    } while (playerMoney > 0 && playAgain );

    cout << "You have $" << playerMoney << " left." << endl;
    cout << "Thank you for playing!" << endl;   
    return 0;
}
// Function definitions
char randomChar(int randomIndex, char Letters[]){
    randomIndex = rand() % 4;
    char randomChar = Letters[randomIndex];
    return randomChar;
}
char randomchar1(int randomIndex1, char Letters[]){
    randomIndex1 = rand() % 4;
    char randomChar1 = Letters[randomIndex1];
    return randomChar1;
}
char randomchar2(int randomIndex2, char Letters[]){
    randomIndex2 = rand() % 4;
    char randomChar2 = Letters[randomIndex2];
    return randomChar2;
}
bool iWon(char Num1, char Num2, char Num3){
    if(Num1 == Num2 && Num2 == Num3){
        return true;
    }
    else{
        return false;
    }
}