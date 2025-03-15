#include "TakeQuiz.h"
#include "QuizData.h"
#include <iostream>

using namespace std;

void TakeQuiz() {
    //Take Quiz option


    if (testCounts > 0) {

        cout << "\nSelect a Test:\n";

        //shows the list of available tests
        for (int i = 0; i < testCounts; i++) {
            cout << i + 1 << ". " << testNames[i] << endl;

        }

        //input wich test you want to take
        int testChoice;
        cout << "Enter the test number: ";
        cin >> testChoice;
        cin.ignore();

        //this makes sure that the test number testChoice exists within available tests
        if (testChoice >= 1 && testChoice <= testCounts) {

            int selectedTestIndex = testChoice - 1; //get the index of the selected test, since the indexes start from 0 not 1

            //run selected test 
            int score = 0;
            for (int i = 0; i < questionCount; i++) {

                cout << "\nQuestion " << i + 1 << ": " << questions[i] << endl;

                string userAnswer; //to store the answer

                cout << "Your answer: ";
                getline(cin, userAnswer);

                //check if the answer is correct
                bool correct = false;
                for (int j = 0; j < answerCounts[i]; j++) {
                    if (userAnswer == answers[i][j]) {
                        correct = true;
                        break; //exit loop
                    }
                }


                if (correct) {
                    cout << "Correct!\n";

                    score++;

                }
                else { cout << "Incorrect.\n"; }


            }

            cout << "\nYour score: " << score << " out of " << questionCount << endl;

        }
        else { cout << "Invalid test number.\n"; }

    }
    else { cout << "No tests available.\n"; }




}