#include "CreateQuiz.h"
#include "QuizData.h"
#include <iostream>
#include <fstream>


using namespace std;

void CreateQuiz() {


    if (testCounts < MaxTests) {


        string testName;

        while (true) {

            cout << "Enter a name for the test: ";
            getline(cin, testName);


            //this is to check if the input is not empty or just spaces
            if (testName.empty() || testName.find_first_not_of(' ') == string::npos) {
//testName.empty() checks if the testName string is empty
//testName.find_first_not_of(' ') == string::npos check the test name if has no characters other than spaces (find_first_not_of returns npos if no non-space character is found)
                cout << "Invalid test name. Please enter a valid name.\n";
            }
            else {
                // Check if a test with this name already exists
                ifstream testFile(testName + ".txt");
                if (testFile.good()) {
                    cout << "A test with this name already exists. Please choose a different name.\n";
                    testFile.close();
                }
                else {
                    break; // Name is valid and unique
                }
            }
        }

        testNames[testCounts] = testName; // Store the test name
        testCounts++; // Increment the test count
        questionCount = 0; // Reset the question count

        string input;

        while (questionCount < MaxQuestions) {
            cout << "Question number " << questionCount + 1 << " or 'done'(d) to finish: ";
            getline(cin, input);

            if (input == "done" || input == "d") { break; } // Stop if the user types 'done'

            questions[questionCount] = input; // Store the question

            // Add answers
            int count = 0; // Counter for the number of answers
            while (count < MaxAnswers) {
                cout << "Enter correct answer " << count + 1 << " or 'done'(d) to finish: ";
                string answer;
                getline(cin, answer);

                if (answer == "done" || answer == "d") { break; } // Stop if the user types 'done'

                answers[questionCount][count] = answer; // Store the answer
                count++; // Increment the answer count
            }
            answerCounts[questionCount] = count; // Store the number of answers
            questionCount++; // Move to the next question
        }

        //to save the test to new a file
        ofstream outFile(testName + ".txt");

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


            //saves the test name to tests.txt
            ofstream testsFile("tests.txt", ios::app);//ios::app so it dosen't delete every time it is closed

            if (testsFile.is_open()) {//checks if the file was opened

                testsFile << testName << "\n"; //saves the test name

                testsFile.close();//closes file
            
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
        cout << "You have reached the maximum number of tests!!\n"; 
    }



}