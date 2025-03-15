#include <iostream>
#include "QuizMenu.h"
#include "CreateQuiz.h"
#include "TakeQuiz.h"
#include "QuizData.h"

using namespace std;

string questions[MaxQuestions]; //to store questions
string answers[MaxQuestions][MaxAnswers]; //to store answers
int answerCounts[MaxQuestions]; //to store the number of answers per question
int questionCount = 0; //for the number of questions in a test

string testNames[MaxTests];
int testCounts = 0; //for the number of tests

int main() {
    while (true) {
        int choice = Quiz_Menu();
        switch (choice) {
        case 1: { //Create Quiz option
            CreateQuiz();
            break;
        }
        case 2: { //Take Quiz option
            TakeQuiz();
            break;
        }
        case 3: { //Exit option
            return 0; //exit the program
        }
        default: {
            cout << "Invalid choice. Try again.\n";
            break;
        }
        }
    }
}