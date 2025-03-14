#include <iostream> 
#include <string>  
using namespace std; 

int main() {
    // maximum limits
    const int MaxQuestions = 100; // Maximum number of questions allowed in a single test
    const int MaxAnswers = 20;   // Maximum number of answers allowed for a single question
    const int MaxTests = 20;     // Maximum number of tests that can be created

    //store quiz data
    string questions[MaxQuestions];           //to store the questions for each test
    string answers[MaxQuestions][MaxAnswers]; //to store the answers for each question multiple answers possible
    int answerCounts[MaxQuestions];           //to store the number of correct answers for each question
    int questionCount = 0;                    //to track the number of questions added to the current test

    //store test data
    string testNames[MaxTests]; //to store the names of tests
    int testCounts = 0;         //to track the number of created tests

    //the main menu loop

    int choice; cout << endl;

    while (true) {

        cout << "Quiz Menu:\n";
        cout << "1. Create Quiz\n";
        cout << "2. Take Quiz\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(); // Consume the newline character left in the input buffer

    }