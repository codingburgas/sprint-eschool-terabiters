#include "CreateQuiz.h"
#include "QuizData.h"
#include <iostream>
#include <fstream>

using namespace std;

void CreateQuiz() {
    if (testCounts < MaxTests) {
        string testName;

        while (true) {
            cout << "Enter a name for the test :";
            getline(cin, testName);

            // Check if the input is not empty or just spaces
            if (testName.empty() || testName.find_first_not_of(' ') == string::npos) {
                cout << "Invalid test name. Please enter a valid name.\n";
            }
            else {
                break;
            }
        }

        testNames[testCounts] = testName; //store the test name
        testCounts++; //increment the test count
        questionCount = 0; //reset the question count

        string input;

        while (questionCount < MaxQuestions) {
            cout << "Question number " << questionCount + 1 << " or 'done' to finish  :";
            getline(cin, input);

            if (input == "done") { break; }

            questions[questionCount] = input;

            string YESorNO;
            cout << "Do you want it to have multiple answers? Yes(y) or No(n)?\n";
            cin >> YESorNO;
            cin.ignore();

            if (YESorNO == "Yes" || YESorNO == "yes" || YESorNO == "Y" || YESorNO == "y") {
                cout << "How many correct answers do you want it to have? (Max " << MaxAnswers << ")\n";
                int count;
                cin >> count;
                cin.ignore();

                if (count > MaxAnswers) { count = MaxAnswers; }

                answerCounts[questionCount] = count;

                for (int i = 0; i < count; i++) {
                    cout << "Correct answer number " << i + 1 << " is :";
                    getline(cin, answers[questionCount][i]);
                }
            }
            else if (YESorNO == "No" || YESorNO == "no" || YESorNO == "N" || YESorNO == "n") {
                cout << "Ok, now enter your answer to the question :" << endl;
                getline(cin, answers[questionCount][0]);
                answerCounts[questionCount] = 1;
            }
            else {
                cout << "It seems you didn't type that right" << "\n";
                continue;
            }
            questionCount++;
        }

        // Save the test to a file
        ofstream outFile(testName + ".txt");
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
            cout << "Test saved to " << testName << ".txt\n";

            // Save the test name to tests.txt
            ofstream testsFile("tests.txt", ios::app);
            if (testsFile.is_open()) {
                testsFile << testName << "\n";
                testsFile.close();
            }
            else {
                cout << "Error: Unable to save the test name to tests.txt.\n";
            }
        }
        else {
            cout << "Error: Unable to save the test to a file.\n";
        }
    }
    else {
        cout << "You have reached the maximum number of tests!!" << endl;
    }
}