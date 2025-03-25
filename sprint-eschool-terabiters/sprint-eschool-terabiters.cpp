#include <iostream>
#include <fstream>
#include "QuizMenu.h"
#include "CreateQuiz.h"
#include "TakeQuiz.h"
#include "EditQuiz.h"   
#include "DeleteQuiz.h" 
#include "QuizData.h"

using namespace std;

string questions[MaxQuestions];
string answers[MaxQuestions][MaxAnswers];
int answerCounts[MaxQuestions];
int questionCount = 0;

string testNames[MaxTests];
int testCounts = 0;

int main() {
    // Load existing tests on startup
    ifstream testsFile("tests.txt");
    if (testsFile.is_open()) {
        while (getline(testsFile, testNames[testCounts]) && testCounts < MaxTests) {
            testCounts++;
        }
        testsFile.close();
    }

    while (true) {
        int choice = Quiz_Menu();
        switch (choice) {
        case 1: CreateQuiz(); break;
        case 2: TakeQuiz(); break;
        case 3: EditQuiz(); break;
        case 4: DeleteQuiz(); break;
        case 5: return 0;
        default: cout << "Invalid choice. Try again.\n";
        }
    }
}