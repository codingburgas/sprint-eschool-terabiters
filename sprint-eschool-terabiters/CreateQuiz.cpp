#include "CreateQuiz.h"
#include "QuizData.h"
#include "raylib.h"
#include <fstream>
#include <string>

using namespace std;

enum CreateQuizState { ENTER_TEST_NAME, ENTER_QUESTION, ENTER_ANSWER, SAVING };

string TextInputBox(Rectangle bounds, const char* prompt, string& input, bool active) {
    static double lastBackspace = 0.0;
    const int fontSize = 20;
    const int padding = 10;

    if (active) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125)) input += (char)key;
            key = GetCharPressed();
        }

        if (IsKeyDown(KEY_BACKSPACE)) {
            double currentTime = GetTime();
            if (currentTime - lastBackspace > 0.10) {
                if (!input.empty()) input.pop_back();
                lastBackspace = currentTime;
            }
        }
    }

    // Text truncation
    string displayText = input;
    float maxWidth = bounds.width - 2 * padding;
    if (MeasureText(displayText.c_str(), fontSize) > maxWidth) {
        for (int i = input.length(); i > 0; i--) {
            string temp = "..." + input.substr(input.length() - i);
            if (MeasureText(temp.c_str(), fontSize) <= maxWidth) {
                displayText = temp;
                break;
            }
        }
    }

    DrawRectangleRec(bounds,  LIGHTGRAY);
    DrawText(prompt, bounds.x + padding, bounds.y - 30, fontSize, DARKGRAY);
    DrawText(displayText.c_str(), bounds.x + padding, bounds.y + padding, fontSize, DARKGRAY);

    if (active && (int)(GetTime() * 2) % 2) {
        int textWidth = MeasureText(displayText.c_str(), fontSize);
        DrawRectangle(bounds.x + padding + textWidth, bounds.y + padding + 2, 2, fontSize - 4, DARKGRAY);
    }

    return input;
}

void CreateQuiz() {
    if (testCounts >= MaxTests) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Maximum tests reached!",
            GetScreenWidth() / 2 - MeasureText("Maximum tests reached!", 30) / 2,
            GetScreenHeight() / 2 - 15, 30, RED);
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
    double saveCompleteTime = 0;
    double invalidNameTime = -1;

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (state != ENTER_TEST_NAME) {
            DrawText(TextFormat("Creating: %s", testName.c_str()), 20, 20, 20, DARKBLUE);
        }

        switch (state) {
        case ENTER_TEST_NAME: {
            Rectangle nameBox = { screenWidth / 2 - 300, screenHeight / 2 - 20, 600, 40 };
            testName = TextInputBox(nameBox, "Enter test name:", testName, true);

            if (IsKeyPressed(KEY_ENTER)) {
                nameValid = !testName.empty() &&
                    (testName.find_first_not_of(' ') != string::npos) &&
                    (!ifstream(testName + ".txt").good());

                if (nameValid) {
                    testNames[testCounts++] = testName;
                    questionCount = 0;
                    state = ENTER_QUESTION;
                    invalidNameTime = -1;
                }
                else invalidNameTime = GetTime();
            }

            if (invalidNameTime > 0 && GetTime() - invalidNameTime < 3) {
                DrawText("Invalid or existing name!", nameBox.x, nameBox.y + 50, 20, RED);
            }
            break;
        }

        case ENTER_QUESTION: {
            char header[50];
            snprintf(header, 50, "Question %d/%d", questionCount + 1, MaxQuestions);
            int textWidth = MeasureText(header, 20);
            DrawText(header, (screenWidth - textWidth) / 2, 100, 20, DARKGRAY);

            Rectangle questionBox = { screenWidth / 2 - 300, screenHeight / 2 - 20, 600, 40 };
            currentQuestion = TextInputBox(questionBox, "Enter question or 'done(d)':", currentQuestion, true);

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
            char questionInfo[100];
            snprintf(questionInfo, 100, "Question %d: %s", questionCount + 1, questions[questionCount].c_str());
            int qWidth = MeasureText(questionInfo, 20);
            DrawText(questionInfo, (screenWidth - qWidth) / 2, 100, 20, DARKGRAY);

            char answerInfo[50];
            snprintf(answerInfo, 50, "Answer %d/%d", currentAnswerCount + 1, MaxAnswers);
            int aWidth = MeasureText(answerInfo, 20);
            DrawText(answerInfo, (screenWidth - aWidth) / 2, 140, 20, DARKGRAY);

            Rectangle answerBox = { screenWidth / 2 - 300, screenHeight / 2 - 20, 600, 40 };
            currentAnswer = TextInputBox(answerBox, "Enter answeror or 'done(d)':", currentAnswer, true);

            if (IsKeyPressed(KEY_ENTER)) {
                if (currentAnswer == "done" || currentAnswer == "d") {
                    answerCounts[questionCount] = currentAnswerCount;
                    questionCount++;
                    state = ENTER_QUESTION;
                    currentAnswer.clear();
                }
                else {
                    answers[questionCount][currentAnswerCount++] = currentAnswer;
                    currentAnswer.clear();
                }
            }
            break;
        }

        case SAVING: {
            char saveText[100];
            snprintf(saveText, 100, "Saving %s (%d questions)", testName.c_str(), questionCount);
            int saveWidth = MeasureText(saveText, 30);
            DrawText(saveText, (screenWidth - saveWidth) / 2, screenHeight / 2 - 30, 30, DARKGRAY);

            if (!hasSaved) {
                ofstream outFile(testName + ".txt");
                if (outFile) {
                    outFile << questionCount << "\n";
                    for (int i = 0; i < questionCount; i++) {
                        outFile << questions[i] << "\n" << answerCounts[i] << "\n";
                        for (int j = 0; j < answerCounts[i]; j++)
                            outFile << answers[i][j] << "\n";
                    }
                    outFile.close();

                    ofstream testsFile("tests.txt", ios::app);
                    if (testsFile) {
                        testsFile << testName << "\n";
                        testsFile.close();
                        hasSaved = true;
                        saveCompleteTime = GetTime();
                    }
                }
            }

            if (hasSaved) {
                DrawText("Test saved successfully!",
                    (screenWidth - MeasureText("Test saved successfully!", 30)) / 2,
                    screenHeight / 2 + 20, 30, GREEN);
                if (GetTime() - saveCompleteTime > 1) return;
            }
            break;
        }
        }
        EndDrawing();
    }
}