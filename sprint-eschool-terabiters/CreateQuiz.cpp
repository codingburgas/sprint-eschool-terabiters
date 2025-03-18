#include "CreateQuiz.h"
#include "QuizData.h"
#include "raylib.h"
#include <fstream>
#include <string>

using namespace std;

enum CreateQuizState {
    ENTER_TEST_NAME,
    ENTER_QUESTION,
    ENTER_ANSWER,
    SAVING
};

string TextInputBox(Rectangle bounds, const char* prompt, string& input, bool active) {
    static double lastBackspace = 0.0;

    if (active) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125)) {
                input += static_cast<char>(key);
            }
            key = GetCharPressed();
        }

        if (IsKeyDown(KEY_BACKSPACE)) {
            double currentTime = GetTime();
            if (currentTime - lastBackspace > 0.08 || IsKeyPressed(KEY_BACKSPACE)) {
                if (!input.empty()) input.pop_back();
                lastBackspace = currentTime;
            }
        }
    }

    DrawRectangleRec(bounds, LIGHTGRAY);
    DrawText(prompt, bounds.x + 10, bounds.y - 30, 20, DARKGRAY);
    DrawText(input.c_str(), bounds.x + 10, bounds.y + 10, 20, DARKGRAY);

    if (active && (int)(GetTime() * 2.0) % 2) {
        int textWidth = MeasureText(input.c_str(), 20);
        DrawRectangle(bounds.x + 14 + textWidth, bounds.y + 12, 2, 20, DARKGRAY);
    }

    return input;
}

void CreateQuiz() {
    if (testCounts >= MaxTests) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Maximum tests reached!", 100, 100, 30, RED);
        EndDrawing();
        WaitTime(2);
        return;
    }

    CreateQuizState state = ENTER_TEST_NAME;
    string testName;
    string currentQuestion;
    string currentAnswer;
    int currentAnswerCount = 0;
    bool nameValid = false;
    bool hasSaved = false;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Always show test name header when in creation flow
        if (state != ENTER_TEST_NAME) {
            DrawText(TextFormat("Creating: %s", testName.c_str()), 10, 10, 20, DARKBLUE);
        }

        switch (state) {
        case ENTER_TEST_NAME: {
            Rectangle nameBox = { 100, 200, 600, 40 };
            testName = TextInputBox(nameBox, "Enter test name:", testName, true);

            if (IsKeyPressed(KEY_ENTER)) {
                nameValid = !testName.empty() &&
                    (testName.find_first_not_of(' ') != string::npos) &&
                    (!ifstream(testName + ".txt").good());

                if (nameValid) {
                    testNames[testCounts] = testName;
                    testCounts++;
                    questionCount = 0;
                    state = ENTER_QUESTION;
                }
                else {
                    DrawText("Invalid or existing name!", 100, 250, 20, RED);
                }
            }
            break;
        }

        case ENTER_QUESTION: {
            // Header shows test name + question progress
            DrawText(TextFormat("Test: %s", testName.c_str()), 100, 70, 30, DARKGRAY);
            DrawText(TextFormat("Question %d/%d", questionCount + 1, MaxQuestions), 100, 110, 20, GRAY);

            Rectangle questionBox = { 100, 200, 600, 40 };
            currentQuestion = TextInputBox(questionBox, "Enter question (or 'done'):", currentQuestion, true);

            if (IsKeyPressed(KEY_ENTER)) {
                if (currentQuestion == "done" || currentQuestion == "d") {
                    state = SAVING;
                }
                else {
                    questions[questionCount] = currentQuestion;
                    currentAnswerCount = 0;
                    state = ENTER_ANSWER;
                    currentQuestion.clear();
                }
            }
            break;
        }

        case ENTER_ANSWER: {
            // Persistent test name + question info
            DrawText(TextFormat("Test: %s", testName.c_str()), 100, 70, 30, DARKGRAY);
            DrawText(TextFormat("Question %d: %s", questionCount + 1, questions[questionCount].c_str()),
                100, 110, 20, DARKGRAY);
            DrawText(TextFormat("Answer %d/%d", currentAnswerCount + 1, MaxAnswers), 100, 140, 20, GRAY);

            Rectangle answerBox = { 100, 200, 600, 40 };
            currentAnswer = TextInputBox(answerBox, "Enter answer (or 'done'):", currentAnswer, true);

            if (IsKeyPressed(KEY_ENTER)) {
                if (currentAnswer == "done" || currentAnswer == "d") {
                    answerCounts[questionCount] = currentAnswerCount;
                    questionCount++;
                    state = ENTER_QUESTION;
                    currentAnswer.clear();
                }
                else {
                    answers[questionCount][currentAnswerCount] = currentAnswer;
                    currentAnswerCount++;
                    currentAnswer.clear();
                }
            }
            break;
        }

        case SAVING: {
            // Show test name during saving
            DrawText(TextFormat("Saving: %s", testName.c_str()), 100, 150, 30, DARKGRAY);

            if (!hasSaved) {
                ofstream outFile(testName + ".txt");
                if (outFile.is_open()) {
                    outFile << questionCount << "\n";
                    for (int i = 0; i < questionCount; i++) {
                        outFile << questions[i] << "\n";
                        outFile << answerCounts[i] << "\n";
                        for (int j = 0; j < answerCounts[i]; j++) {
                            outFile << answers[i][j] << "\n";
                        }
                    }
                    outFile.close();

                    ofstream testsFile("tests.txt", ios::app);
                    if (testsFile.is_open()) {
                        testsFile << testName << "\n";
                        testsFile.close();
                        hasSaved = true;
                        DrawText("Test saved successfully!", 100, 200, 30, GREEN);
                    }
                    else {
                        DrawText("Error saving test list!", 100, 200, 30, RED);
                    }
                }
                else {
                    DrawText("Error saving test content!", 100, 200, 30, RED);
                }
                hasSaved = true;
            }

            if (IsKeyPressed(KEY_ENTER)) return;
            break;
        }
        }

        EndDrawing();
    }
}