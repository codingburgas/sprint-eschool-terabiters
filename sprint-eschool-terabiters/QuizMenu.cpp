#include "QuizMenu.h"
#include <iostream>

using namespace std;

int Quiz_Menu() {

    int choice;

    cout << "Quiz Menu:\n" << endl;
    cout << "1. Create Quiz\n";
    cout << "2. Take Quiz\n";
    cout << "3. Edit Quiz\n";
    cout << "4. Delete Quiz\n"; 
    cout << "5. Exit\n" << endl;
    cout << "Enter your choice: ";

    cin >> choice;
    cin.ignore();

    return choice;
}