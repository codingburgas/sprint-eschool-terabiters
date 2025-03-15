#pragma once
#include <string>

const int MaxQuestions = 100;
const int MaxAnswers = 20;
const int MaxTests = 20;

extern std::string questions[];
extern std::string answers[][20];
extern int answerCounts[];
extern int questionCount;

extern std::string testNames[];
extern int testCounts;