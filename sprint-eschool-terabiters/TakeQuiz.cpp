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

    // Display available tests
    cout << "\nAvailable Tests:\n";
    string testName;
    int testNumber = 0;
    while (getline(testsFile, testName)) {
        // Skip empty or whitespace-only test names
        if (testName.empty() || testName.find_first_not_of(' ') == string::npos) {
            continue; // Skip this test name
        }

        cout << ++testNumber << ". " << testName << endl;
    }
    testsFile.close();

    if (testNumber == 0) {
        cout << "No tests available.\n";
        return;
    }

    // Prompt the user to enter the name of the test
    string selectedTestName;
    while (true) {
        cout << "Enter the name of the test you want to take: ";
        getline(cin, selectedTestName);

        // Check if the input is not empty or just spaces
        if (selectedTestName.empty() || selectedTestName.find_first_not_of(' ') == string::npos) {
            cout << "Invalid test name. Please enter a valid name.\n";
        }
        else {
            break;
        }
    }

    // Open the selected test file
    ifstream inFile(selectedTestName + ".txt");
    if (inFile.is_open()) {
        // Load the test data
        inFile >> questionCount; // Load the number of questions
        inFile.ignore(); // Ignore the newline character

        for (int i = 0; i < questionCount; i++) {
            getline(inFile, questions[i]); // Load the question
            inFile >> answerCounts[i]; // Load the number of answers
            inFile.ignore(); // Ignore the newline character
            for (int j = 0; j < answerCounts[i]; j++) {
                getline(inFile, answers[i][j]); // Load each answer
            }
        }
        inFile.close();

        // Take the quiz
        int score = 0;
        for (int i = 0; i < questionCount; i++) {
            cout << "\nQuestion " << i + 1 << ": " << questions[i] << endl;
            string userAnswer;
            cout << "Your answer: ";
            getline(cin, userAnswer);

            bool correct = false;
            for (int j = 0; j < answerCounts[i]; j++) {
                if (userAnswer == answers[i][j]) { // Check if the answer is correct
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