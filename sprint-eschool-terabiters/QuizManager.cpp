#include "QuizManager.h"
#include <iostream>

void QuizManager::CreateQuiz() {
    if (testCounts < MaxTests) {
        std::string testName;
        std::cout << "Enter a name for the test: ";
        std::getline(std::cin, testName);

        testNames[testCounts] = testName;
        testCounts++;
        questionCount = 0;

        std::string input;
        while (questionCount < MaxQuestions) {
            std::cout << "Enter a question or 'done' to finish: ";
            std::getline(std::cin, input);
            if (input == "done") {
                break;
            }
            questions[questionCount] = input;
            std::string YESorNO;
            std::cout << "Do you want it to have multiple answers? Yes(y) or No(n)?\n";
            std::cin >> YESorNO;
            std::cin.ignore();

            if (YESorNO == "Yes" || YESorNO == "yes" || YESorNO == "Y" || YESorNO == "y") {
                std::cout << "How many correct answers do you want it to have? (Max " << MaxAnswers << ")\n";
                int count;
                std::cin >> count;
                std::cin.ignore();
                if (count > MaxAnswers) {
                    count = MaxAnswers;
                }
                answerCounts[questionCount] = count;
                for (int i = 0; i < count; i++) {
                    std::cout << "Correct answer number " << i + 1 << " is :";
                    std::getline(std::cin, answers[questionCount][i]);
                }
            }
            else if (YESorNO == "No" || YESorNO == "no" || YESorNO == "N" || YESorNO == "n") {
                std::cout << "Ok, now enter your answer to the question:" << std::endl;
                std::getline(std::cin, answers[questionCount][0]);
                answerCounts[questionCount] = 1;
            }
            else {
                std::cout << "It seems you didn't typed that right" << "\n";
                continue;
            }
            questionCount++;
        }
    }
    else {
        std::cout << "You have reached the maximum number of tests!" << std::endl;
    }
}

void QuizManager::TakeQuiz() {
    if (testCounts > 0) {
        std::cout << "\nSelect a Test:\n";
        for (int i = 0; i < testCounts; i++) {
            std::cout << i + 1 << ". " << testNames[i] << std::endl;
        }
        int testChoice;
        std::cout << "Enter the test number: ";
        std::cin >> testChoice;
        std::cin.ignore();

        if (testChoice >= 1 && testChoice <= testCounts) {
            int selectedTestIndex = testChoice - 1;
            int score = 0;
            for (int i = 0; i < questionCount; i++) {
                std::cout << "\nQuestion " << i + 1 << ": " << questions[i] << std::endl;
                std::string userAnswer;
                std::cout << "Your answer: ";
                std::getline(std::cin, userAnswer);

                bool correct = false;
                for (int j = 0; j < answerCounts[i]; j++) {
                    if (userAnswer == answers[i][j]) {
                        correct = true;
                        break;
                    }
                }
                if (correct) {
                    std::cout << "Correct!\n";
                    score++;
                }
                else {
                    std::cout << "Incorrect.\n";
                }
            }
            std::cout << "\nYour score: " << score << " out of " << questionCount << std::endl;
        }
        else {
            std::cout << "Invalid test number.\n";
        }
    }
    else {
        std::cout << "No tests available.\n";
    }
}