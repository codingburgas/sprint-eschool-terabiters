#include "DeleteQuiz.h"
#include "QuizData.h"
#include <iostream>
#include <fstream>
#include <cstdio> // For remove()

using namespace std;

void DeleteQuiz() {
    if (testCounts == 0) {
        cout << "No tests available to delete.\n";
        return;
    }

    // Display available tests
    cout << "\nAvailable Tests:\n";
    for (int i = 0; i < testCounts; i++) {
        cout << i + 1 << ". " << testNames[i] << endl;
    }

    int testChoice;
    cout << "Enter the number of the test to delete: ";
    cin >> testChoice;
    cin.ignore();

    if (testChoice < 1 || testChoice > testCounts) {
        cout << "Invalid selection.\n";
        return;
    }

    string deletedTest = testNames[testChoice - 1];

    // Remove from array
    for (int i = testChoice - 1; i < testCounts - 1; i++) {
        testNames[i] = testNames[i + 1];
    }
    testCounts--;

    // Update tests.txt
    ofstream outFile("tests.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < testCounts; i++) {
            outFile << testNames[i] << "\n";
        }
        outFile.close();
    }

    // Delete file
    if (remove((deletedTest + ".txt").c_str()) != 0) {
        cout << "Error deleting test file!\n";
    }
    else {
        cout << "Test deleted successfully!\n";
    }
}