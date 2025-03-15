#include "CreateQuiz.h"
#include "QuizData.h"
#include <iostream>

using namespace std;

void CreateQuiz() {


    //Create Quiz option


    if (testCounts < MaxTests) {//if the maximum number of tests has been reached(testCounts now is 0)

        string testName;

        cout << "Enter a name for the test: ";
        getline(cin, testName); //input the test name

        testNames[testCounts] = testName; //store the test name
        testCounts++; //increment the test count

        questionCount = 0;//reset the question count


        //                                                                 | |
        //loop until input "done" or reaches the max number of questions   v v

        string input; //to store the question input

        while (questionCount < MaxQuestions) {// questionCount that we reset and now is 0

            cout << "Enter a question or 'done' to finish: ";
            getline(cin, input);

            if (input == "done") { break; } // to exit when typed 'done'
            questions[questionCount] = input; //to store the question


            //                                        | |
            //if it wants multiples answers or no     v v

            string YESorNO;

            cout << "Do you want it to have multiple answers? Yes(y) or No(n)?\n";
            cin >> YESorNO;
            cin.ignore();


            if (YESorNO == "Yes" || YESorNO == "yes" || YESorNO == "Y" || YESorNO == "y") {

                cout << "How many correct answers do you want it to have? (Max " << MaxAnswers << ")\n";

                int count; //to store number of correct answers we want
                cin >> count;
                cin.ignore();

                if (count > MaxAnswers) { count = MaxAnswers; }//if is more than the max answers

                answerCounts[questionCount] = count; //to store the number of answers for this question


                for (int i = 0; i < count; i++) {

                    cout << "Correct answer number " << i + 1 << " is :";

                    getline(cin, answers[questionCount][i]); //input all the correct answers thah we wanted
                }


            }
            else if (YESorNO == "No" || YESorNO == "no" || YESorNO == "N" || YESorNO == "n") {


                cout << "Ok, now enter your answer to the question:" << endl;
                getline(cin, answers[questionCount][0]); //input only one correct answer
                answerCounts[questionCount] = 1; //set the answer count to 1

            }
            else {

                cout << "It seems you didn't typed that right" << "\n";
                continue; // to skip the rest of the current loop iteration and move on to the next one
            }

            questionCount++; //count 1+ to the question count
        }

    }
    else { cout << "You have reached the maximum number of tests!" << endl; }
