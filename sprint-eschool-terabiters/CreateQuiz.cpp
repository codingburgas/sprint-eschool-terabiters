#include "CreateQuiz.h"
#include "QuizData.h"
#include <iostream>

void CreateQuiz() {
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