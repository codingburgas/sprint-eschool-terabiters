#pragma once
#include <string>
using namespace std;

const int MaxQuestions = 100;  // Maximum number of questions allowed in a single test
const int MaxAnswers = 20;  // Maximum number of answers allowed for a single question
const int MaxTests = 20;  // Maximum number of tests that can be created


extern string questions[MaxQuestions];           //to store the questions for each test
extern string answers[MaxQuestions][MaxAnswers]; //to store the answers for each question multiple answers possible
extern int answerCounts[MaxQuestions];           //to store the number of correct answers for each question

extern string testNames[MaxTests];

extern int testCounts;
extern int questionCount;