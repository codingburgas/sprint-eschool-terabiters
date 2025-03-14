#include <iostream>
#include <string>

using namespace std;

int main() {

    //for array sizes and limits

    const int MaxQuestions = 100; //max number of questions per test
    const int MaxAnswers = 10;   //max number of answers per question
    const int MaxTests = 10;     //max number of tests

    //to store quiz data
    string questions[MaxQuestions];   //to store questions
    string answers[MaxQuestions][MaxAnswers]; //to store answers
    int answerCounts[MaxQuestions];   //to store the number of answers per question

    int questionCount = 0;   //for the number of questions in a test

    
    string testNames[MaxTests]; 
    int testCounts = 0;  //for the number of tests


    //                        | |
    // Main menu loop         V V

    int choice;
    while (true) {
       
        cout << "Quiz Menu:\n\n";
        cout << "1. Create Quiz\n";
        cout << "2. Take Quiz\n";
        cout << "3. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); //delete newline character

       
        switch (choice) {
        case 1: { //Create Quiz option


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

            break;
        }

        case 2: { //Take Quiz option


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

            break;
        }


        case 3: { //Exit option
            return 0; //exit the program
        }

        default: {
            cout << "Invalid choice. Try again.\n";
            break;
        }


        }






    }





}