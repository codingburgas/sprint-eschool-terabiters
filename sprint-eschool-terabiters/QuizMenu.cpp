#include "QuizMenu.h"
#include <iostream>

using namespace std;

int Quiz_Menu() {
    int choice;
    cout << "Quiz Menu:\n\n";
    cout << "1. Create Quiz\n";
    cout << "2. Take Quiz\n";
    cout << "3. Exit\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}
