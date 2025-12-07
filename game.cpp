#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cmath>

void guessing(int &userCin, int &rn, bool &found);

int main()
{
    bool again = true;
    while (again)
    {
        std::cout << "Welcome To Number Guessing Game" << std::endl;
        std::cout << "RULE: Guessing the number from 1 to 100, guess wisely" << std::endl
                  << std::endl;
        std::cout << "Choose Your Difficulty (number only)" << std::endl;
        std::cout << "1 Easy (10 chances)" << std::endl;
        std::cout << "2 Medium (7 chances)" << std::endl;
        std::cout << "3 Hard (5 chances)" << std::endl
                  << std::endl;

        int level;
        int chance = 0;
        while (true)
        {
            std::cin >> level;
            if (std::cin.fail() || level > 3 || level < 1)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Please input correct level" << std::endl
                          << std::endl;
                continue;
            }
            switch (level)
            {
            case 1:
                std::cout << "Easy mode selected..." << std::endl;
                std::cout << "Game Start" << std::endl;
                chance = 10;
                break;

            case 2:
                std::cout << "Medium mode selected..." << std::endl;
                std::cout << "Game Start" << std::endl;
                chance = 7;
                break;

            case 3:
                std::cout << "Hard mode selected..." << std::endl;
                std::cout << "Game Start" << std::endl;
                chance = 5;
                break;
            default:
                std::cout << "Wrong input! Please try again" << std::endl;
            }
            if (chance != 0)
            {
                break;
            }
        }
        const auto start = std::chrono::steady_clock::now();
        srand(time(0));
        int rn = rand() % 101;
        bool found = 0;
        int round = 1;
        while (!found && round <= chance)
        {
            int userCin;
            std::cout << "Round " << round << " guess: ";
            std::cin >> userCin;
            if (std::cin.fail() || userCin > 100 || userCin <= 0)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Please input number from 1 to 100" << std::endl
                          << std::endl;
                continue;
            }
            else
            {
                guessing(userCin, rn, found);
                round++;
            }
        }
        if (found == 1)
        {
            const auto end = std::chrono::steady_clock::now();
            std::cout << "Correct Answer!" << std::endl;
            std::cout << "GOOD JOB!" << std::endl;
            std::cout << "Total Guess: " << round - 1 << std::endl
                      << std::endl;
            const std::chrono::duration<double> dif = end - start;
            std::cout << "Time Used: " << std::round(dif.count()) << " s" << std::endl
                      << std::endl;
        }
        if (found == 0)
        {
            const auto end = std::chrono::steady_clock::now();
            std::cout << "Game Over! you can't guess in time" << std::endl
                      << std::endl;
            std::cout << "The correct answer is... " << rn << std::endl
                      << std::endl;
            const std::chrono::duration<double> dif = end - start;
            std::cout << "Time Used: " << std::round(dif.count()) << " s" << std::endl
                      << std::endl;
        }
        char temp;
        std::cout << "Play again? (Y/N)" << std::endl;
        while (std::cin >> temp)
        {
            if (temp == 'N' || temp == 'n')
            {
                std::cout << "Okie! Bye!" << std::endl;
                again = 0;
                break;
            }
            else if (temp == 'Y' || temp == 'y')
            {
                std::cout << "Let's Play!" << std::endl
                          << std::endl;
                break;
            }
            else
            {
                std::cout << "Wrong input!" << std::endl
                          << std::endl;
            }
        }
    }
    return 0;
}

void guessing(int &userCin, int &rn, bool &found)
{
    if (userCin > rn)
    {
        std::cout << "Wrong Answer!" << std::endl;
        if (std::abs(rn - userCin) <= 5)
        {
            std::cout << "You're so close!" << std::endl;
        }
        std::cout << "The number is less than " << userCin << std::endl
                  << std::endl;
    }
    else if (userCin < rn)
    {
        std::cout << "Wrong Answer!" << std::endl;
        if (std::abs(rn - userCin) <= 5)
        {
            std::cout << "You're so close!" << std::endl;
        }
        std::cout << "The number is more than " << userCin << std::endl
                  << std::endl;
    }
    else
    {
        found = 1;
    }
}
