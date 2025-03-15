#pragma once
#include <string>

const int MaxQuestions = 100; //max number of questions per test
const int MaxAnswers = 20;    //max number of answers per question
const int MaxTests = 20;      //max number of tests

extern std::string questions[MaxQuestions];    //to store questions
extern std::string answers[MaxQuestions][MaxAnswers]; //to store answers
extern int answerCounts[MaxQuestions];    //to store the number of answers per question
extern int questionCount;    //for the number of questions in a test

extern std::string testNames[MaxTests];
extern int testCounts; //for the number of tests
