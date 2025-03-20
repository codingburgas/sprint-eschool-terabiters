#include <iostream>
#include <fstream>
#include "QuizMenu.h"
#include "CreateQuiz.h"
#include "TakeQuiz.h"
#include "EditQuiz.h"   
#include "DeleteQuiz.h" 
#include "QuizData.h"
#include "raylib.h"

using namespace std;

// Global quiz data
string questions[MaxQuestions];
string answers[MaxQuestions][MaxAnswers];
int answerCounts[MaxQuestions];
int questionCount = 0;

string testNames[MaxTests];
int testCounts = 0;

int main() {
    // Initialize window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Quiz Manager");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(60);

    // Load existing tests
    ifstream testsFile("tests.txt");
    if (testsFile.is_open()) {
        while (getline(testsFile, testNames[testCounts]) && testCounts < MaxTests) {
            testCounts++;
        }
        testsFile.close();
    }

    // Main loop
    bool shouldClose = false;
    while (!shouldClose && !WindowShouldClose()) {
        int choice = Quiz_Menu();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (choice) {
        case 1: CreateQuiz(); break;
        case 2: TakeQuiz(); break;
        case 3: EditQuiz(); break;
        case 4: DeleteQuiz(); break;
        case 5: shouldClose = true; break;  // Changed here
        default: break;
        }

        EndDrawing();
    }

    CloseWindow();  // Unified window close
    return 0;
}