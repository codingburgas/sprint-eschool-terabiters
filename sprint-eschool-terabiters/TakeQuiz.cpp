#include "TakeQuiz.h"
#include "QuizData.h"
#include <iostream>

void TakeQuiz() {
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