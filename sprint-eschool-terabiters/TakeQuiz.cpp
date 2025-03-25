#include "TakeQuiz.h"
#include "QuizData.h"
#include "CalculatePercent.h"
#include <iostream>
#include <fstream>

using namespace std;

void TakeQuiz() {
    // Load test names from tests.txt
    ifstream testsFile("tests.txt");

    if (!testsFile.is_open()) {
        cout << "No tests available.\n";
        return;
    }

    // Store tests and display numbered list
    string testNames[100];
    int count = 0;
    cout << "\nAvailable Tests:\n";
    string testName;
    while (getline(testsFile, testName)) {
        if (testName.empty() || testName.find_first_not_of(' ') == string::npos) continue;
        if (count < 100) {
            testNames[count] = testName;
            cout << (count + 1) << ". " << testName << endl;
            count++;
        }
    }
    testsFile.close();

    if (count == 0) {
        cout << "No tests available.\n";
        return;
    }

    // Get numeric test selection
    int testChoice;
    cout << "Enter the number of the test you want to take: ";
    cin >> testChoice;
    cin.ignore();

    if (testChoice < 1 || testChoice > count) {
        cout << "Invalid selection.\n";
        return;
    }

    string selectedTestName = testNames[testChoice - 1];

    // Open selected test file (rest remains unchanged)
    ifstream inFile(selectedTestName + ".txt");
    if (inFile.is_open()) {
        inFile >> questionCount;
        inFile.ignore();

        for (int i = 0; i < questionCount; i++) {
            getline(inFile, questions[i]);
            inFile >> answerCounts[i];
            inFile.ignore();
            for (int j = 0; j < answerCounts[i]; j++) {
                getline(inFile, answers[i][j]);
            }
        }
        inFile.close();

        int score = 0;
        for (int i = 0; i < questionCount; i++) {
            cout << "\nQuestion " << i + 1 << ": " << questions[i] << endl;
            string userAnswer;
            cout << "Your answer: ";
            getline(cin, userAnswer);

            bool correct = false;
            for (int j = 0; j < answerCounts[i]; j++) {
                if (userAnswer == answers[i][j]) {
                    correct = true;
                    break;
                }
            }

            if (correct) {
                cout << "Correct!\n";
                score++;
            }
            else {
                cout << "Incorrect.\n";
            }
        }

        cout << "\nYour score: " << score << " out of " << questionCount << "\nYou have " << percent(score, questionCount) << "%\n";
    }
    else {
        cout << "Error: Unable to open the test file.\n";
    }
}