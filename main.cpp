#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    // Declare variables
    int playMoney;
    int playAgain;
    
    // Welcome message and prompt user to enter 10 to play
        std::cout << "Welcome to the Slot Machine! Enter 10 to play." << std::endl;
        std::cin >> playMoney;

    // Check if user entered 10 to play
        if (playMoney == 10) {
        std::cout << "You have $" << playMoney << " to play with." << std::endl;
        std::cout << "Good luck! Press enter to continue" << std::endl;
        
        } else {
        std::cout << "You must enter 10 to play." << std::endl;

        return 0;
        }
    
    // Play the game
    do{
        playMoney -= 1;
        std::srand(std::time(0));
        const char letters[4] = {'$', '7', '#', 'X'};
    
    // Generate random numbers
        int RandIndex = rand() % 4;
        char Num0 = letters[RandIndex];

        int RandIndex1 = rand() % 4;
        char Num1 = letters[RandIndex1];
    
        int RandIndex2 = rand() % 4;
        char Num2 = letters[RandIndex2];
    
        char output[] = {Num0, Num1, Num2};
    
    // Display the random numbers
        for (int i = 0; i < 3; ++i) {
        std::cout << output[i];
        }
        std::cout << std::endl;

    // Check if user wins or loses and update the amount of money
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

    // Display the amount of money left and ask user if they want to play again
        std::cout << "You have $" << playMoney << " left." << std::endl;
        std::cout << "Would you like to play again? Enter 1 for yes or 0 for no." << std::endl;
        std::cin >> playAgain;

    } while (playMoney > 0 && playAgain == 1);

    // Display goodbye message if user is out of moneyS
    std::cout << "You're out of money. Goodbye!" << std::endl;

    return 0;
}