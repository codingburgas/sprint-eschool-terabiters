#include <iostream> 

//#include <string>  
using namespace std;

int Quiz_Menu() {
    int choice;
        
    cout << "Quiz Menu:\n" << endl;
    cout << "1. Create Quiz\n";
    cout << "2. Take Quiz\n";
    cout << "3. Exit\n" << endl;
    cout << "Enter your choice: ";

    cin >> choice;
    cin.ignore(); //consume the newline character left in the input buffer

    return choice;

}