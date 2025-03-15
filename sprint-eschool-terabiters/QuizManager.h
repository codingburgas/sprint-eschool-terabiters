#pragma once
#include <string>
#include <array>

class QuizManager {
public:
    static const int MaxQuestions = 100;
    static const int MaxAnswers = 20;
    static const int MaxTests = 20;

    void CreateQuiz();
    void TakeQuiz();

    std::string testNames[MaxTests];
    int testCounts = 0;

private:
    std::string questions[MaxQuestions];
    std::string answers[MaxQuestions][MaxAnswers];
    int answerCounts[MaxQuestions];
    int questionCount = 0;
};