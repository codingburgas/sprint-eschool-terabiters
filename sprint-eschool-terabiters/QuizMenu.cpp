#include "QuizMenu.h"
#include <iostream>

int Quiz_Menu() {
    int choice;
    std::cout << "Quiz Menu:\n" << std::endl;
    std::cout << "1. Create Quiz\n";
    std::cout << "2. Take Quiz\n";
    std::cout << "3. Exit\n" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}