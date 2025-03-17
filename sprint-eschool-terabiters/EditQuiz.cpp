#include "EditQuiz.h"
#include "QuizData.h"
#include <iostream>
#include <fstream>


using namespace std;

void EditQuiz() {
    if (testCounts == 0) {
        cout << "No tests available to edit.\n";
        return;
    }

    // Display available tests
    cout << "\nAvailable Tests:\n";
    for (int i = 0; i < testCounts; i++) {
        cout << i + 1 << ". " << testNames[i] << endl;
    }

    int testChoice;
    cout << "Enter the number of the test to edit: ";
    cin >> testChoice;
    cin.ignore();

    if (testChoice < 1 || testChoice > testCounts) {
        cout << "Invalid selection.\n";
        return;
    }

    string selectedTest = testNames[testChoice - 1];

    // Load the test
    ifstream inFile(selectedTest + ".txt");
    if (!inFile) {
        cout << "Error loading test!\n";
        return;
    }

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

    // Edit questions
    for (int i = 0; i < questionCount; i++) {
        cout << "\nEditing Question " << i + 1 << ":\n";
        cout << "Current question: " << questions[i] << endl;
        cout << "Enter new question (or press Enter to keep current): ";
        string newQuestion;
        getline(cin, newQuestion);
        if (!newQuestion.empty()) {
            questions[i] = newQuestion;
        }

        // Edit answers
        cout << "Current answers:\n";
        for (int j = 0; j < answerCounts[i]; j++) {
            cout << j + 1 << ". " << answers[i][j] << endl;
        }

        cout << "Enter new answers (comma separated, press Enter to keep current): ";
        string newAnswers;
        getline(cin, newAnswers);

        if (!newAnswers.empty()) {
            int pos = 0;
            int count = 0;
            while ((pos = newAnswers.find(',')) != string::npos && count < MaxAnswers) {
                answers[i][count++] = newAnswers.substr(0, pos);
                newAnswers.erase(0, pos + 1);
            }
            if (!newAnswers.empty() && count < MaxAnswers) {
                answers[i][count++] = newAnswers;
            }
            answerCounts[i] = count;
        }
    }

    // Save changes
    ofstream outFile(selectedTest + ".txt");
    if (outFile.is_open()) {
        outFile << questionCount << "\n";
        for (int i = 0; i < questionCount; i++) {
            outFile << questions[i] << "\n";
            outFile << answerCounts[i] << "\n";
            for (int j = 0; j < answerCounts[i]; j++) {
                outFile << answers[i][j] << "\n";
            }
        }
        outFile.close();
        cout << "Test updated successfully!\n";
    }
    else {
        cout << "Error saving changes!\n";
    }
}