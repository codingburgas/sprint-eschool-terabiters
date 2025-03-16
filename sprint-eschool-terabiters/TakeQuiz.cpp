#include "TakeQuiz.h"
#include "QuizData.h"
#include "CalculatePercent.h"
#include <iostream>

using namespace std;

void TakeQuiz() {


    if (testCounts > 0) {//chek if there's a test

        cout << "\nSelect a Test:\n";

        //shows the created tests
        for (int i = 0; i < testCounts; i++) {
            cout << i + 1 << ". " << testNames[i] << endl;
        }

        int testChoice;
        cout << "Enter the test number: ";
        cin >> testChoice;
        cin.ignore();

        //this makes sure that the test number testChoice exists within available tests
        if (testChoice >= 1 && testChoice <= testCounts) {
            int selectedTestIndex = testChoice - 1; //get the index of the selected test, since the indexes start from 0 not 1


            int score = 0;

            //runs the test
            for (int i = 0; i < questionCount; i++) {

                cout << "\nQuestion " << i + 1 << ": " << questions[i] << endl;

                string userAnswer;

                cout << "Your answer: ";
                getline(cin, userAnswer);

                
                bool correct = false;

                for (int j = 0; j < answerCounts[i]; j++) {

                    if (userAnswer == answers[i][j]) {//check if the answer is correct
                        correct = true;
                        break; 
                    }

                } if (correct) {
               
                    cout << "Correct!\n";
                    score++;

                } else {
                  cout << "Incorrect.\n"; 
                }
            }

          
            cout << "\nYour score: " << score << " out of " << questionCount << "\n Your have "<<percent(score, questionCount)<<"%\n";

        }
        else { cout << "Invalid test number.\n"; }
    }
    else { cout << "No tests available.\n"; }
}