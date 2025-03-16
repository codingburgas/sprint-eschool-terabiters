#include "CreateQuiz.h"
#include "QuizData.h"
#include <iostream>
#include <fstream> // Include the fstream library for file handling

using namespace std;

void CreateQuiz() {
    if (testCounts < MaxTests) { //if the maximum number of tests has been reached(testCounts now is 0)
        string testName;

        cout << "Enter a name for the test: ";
        getline(cin, testName);

        testNames[testCounts] = testName; //store the test name
        testCounts++; //increment the test count
        questionCount = 0; //reset the question count

        //                                                                  | |
        //loop until input "done" or reaches the max number of questions    V V
        string input;

        while (questionCount < MaxQuestions) { // questionCount that we reset and now is 0
            cout << "Question number " << questionCount + 1 << " or 'done' to finish: ";
            getline(cin, input);

            if (input == "done") { break; } // to exit when typed 'done'

            questions[questionCount] = input; //to store the question

            //if it wants multiples answers yes or no
            string YESorNO;
            cout << "Do you want it to have multiple answers? Yes(y) or No(n)?\n";
            cin >> YESorNO;
            cin.ignore();

            if (YESorNO == "Yes" || YESorNO == "yes" || YESorNO == "Y" || YESorNO == "y") {
                cout << "How many correct answers do you want it to have? (Max " << MaxAnswers << ")\n";
                int count; //to store number of correct answers we want
                cin >> count;
                cin.ignore();

                if (count > MaxAnswers) { count = MaxAnswers; } //if the count is more than the max answers

                answerCounts[questionCount] = count; //to store the number of answers for this question

                for (int i = 0; i < count; i++) {//to input all the correct answers thah we wanted
                    cout << "Correct answer number " << i + 1 << " is: ";
                    getline(cin, answers[questionCount][i]);
                }
            }
            else if (YESorNO == "No" || YESorNO == "no" || YESorNO == "N" || YESorNO == "n") {
                cout << "Ok, now enter your answer to the question:" << endl;
                getline(cin, answers[questionCount][0]); //input only one correct answer
                answerCounts[questionCount] = 1; //set the answer count to 1
            }
            else {
                cout << "It seems you didn't type that right" << "\n";
                continue; // to skip the rest of the current loop iteration and move on to the next one
            }
            questionCount++; //count 1+ to the question count
        }

        // Save the test to a file
        ofstream outFile(testName + ".txt"); // Create a file named after the test
        if (outFile.is_open()) {
            outFile << questionCount << "\n"; // Save the number of questions
            for (int i = 0; i < questionCount; i++) {
                outFile << questions[i] << "\n"; // Save the question
                outFile << answerCounts[i] << "\n"; // Save the number of answers
                for (int j = 0; j < answerCounts[i]; j++) {
                    outFile << answers[i][j] << "\n"; // Save each answer
                }
            }
            outFile.close();
            cout << "Test saved to " << testName << ".txt\n";

            // Save the test name to tests.txt
            ofstream testsFile("tests.txt", ios::app); // Open tests.txt in append mode
            if (testsFile.is_open()) {
                testsFile << testName << "\n"; // Append the test name
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
        cout << "You have reached the maximum number of tests!" << endl;
    }
}