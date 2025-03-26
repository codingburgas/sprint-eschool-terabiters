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
                //check if a test with this name already exists
                ifstream testFile(testName + ".txt");
                if (testFile.good()) {
                    cout << "A test with this name already exists! Please choose a different name.\n";
                    testFile.close();
                }
                else {
                    break; 
                }
            }
        }

        testNames[testCounts] = testName; 
        testCounts++; 
        questionCount = 0; //reset question count





        string input;

        while (questionCount < MaxQuestions) {
            cout << "\nQuestion number " << questionCount + 1 << " or 'done'(d) to finish: ";
            getline(cin, input);

            if (input == "done" || input == "d") { break; } 

            questions[questionCount] = input; //store the question


            //                                                                                |  | |   
            //Add answers                                                                     V  V V
            int count = 0; //for the number of answers

            while (count < MaxAnswers) {

                cout << "Enter correct answer " << count + 1 << " or 'done'(d) to finish: ";
                string answer;
                getline(cin, answer);

                if (answer == "done" || answer == "d") { break; } 

                answers[questionCount][count] = answer; //store the answer
                count++; 
            }
            answerCounts[questionCount] = count; //store number of answers
            questionCount++; //move to next question
        }

        //save the test to new a file
        ofstream outFile(testName + ".txt");

        if (outFile.is_open()) {
            outFile << questionCount << "\n"; //save the number of questions
            for (int i = 0; i < questionCount; i++) {
                outFile << questions[i] << "\n";
                outFile << answerCounts[i] << "\n"; 
                for (int j = 0; j < answerCounts[i]; j++) {
                    outFile << answers[i][j] << "\n"; //save answers
                }
            }
            outFile.close();
            cout << "\nTest saved to " << testName << ".txt\n";


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