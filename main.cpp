#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    int playMoney;
    int playAgain;

    std::cout << "Welcome to the Slot Machine! Enter 10 to play." << std::endl;
    std::cin >> playMoney;

    do{
        playMoney -= 1;
        std::srand(std::time(0));
        const char letters[4] = {'$', '7', '#', 'X'};
    
        int RandIndex = rand() % 4;
        char Num0 = letters[RandIndex];

        int RandIndex1 = rand() % 4;
        char Num1 = letters[RandIndex1];
    
        int RandIndex2 = rand() % 4;
        char Num2 = letters[RandIndex2];
    
        char output[] = {Num0, Num1, Num2};
    
        for (int i = 0; i < 3; ++i) {
        std::cout << output[i];
        }
        std::cout << std::endl;

        if (Num0 == Num1 && Num1 == Num2 && Num0 == '#') {
        std::cout << "Congratulations! You win!" << std::endl;
        playMoney += 25; 
        } else if (Num0 == Num1 && Num1 == Num2 && Num0 == '7') {
        std::cout << "Congratulations! You win!" << std::endl;
        playMoney += 100;
        } else if (Num0 == Num1 && Num1 == Num2 && Num0 == '$') {
        std::cout << "Congratulations! You win!" << std::endl;
        playMoney += 50;
        } else if (Num0 == Num1 && Num1 == Num2 && Num0 == 'X') {
        std::cout << "Congratulations! You win!" << std::endl;
        playMoney += 10;
        } else{
        std::cout << "Sorry, you lose!" << std::endl;
        }
        std::cout << "You have $" << playMoney << " left." << std::endl;
        std::cout << "Would you like to play again? Enter 1 for yes or 0 for no." << std::endl;
        std::cin >> playAgain;

    } while (playMoney > 0 && playAgain == 1);

    std::cout << "Goodbye!" << std::endl;

    return 0;
}