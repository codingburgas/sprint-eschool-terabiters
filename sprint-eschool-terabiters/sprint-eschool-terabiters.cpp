#include <iostream>
#include <string>
#include "QuizMenu.h"
#include "CreateQuiz.h"
#include "TakeQuiz.h"
#include "QuizData.h"

using namespace std;

string questions[MaxQuestions];
string answers[MaxQuestions][MaxAnswers];
int answerCounts[MaxQuestions];
int questionCount = 0;

string testNames[MaxTests];
int testCounts = 0;

int main() {


    while (true) {
        int choice = Quiz_Menu();

        switch (choice) {
        case 1:
            CreateQuiz();
            break;
        case 2:
            TakeQuiz();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
   


}