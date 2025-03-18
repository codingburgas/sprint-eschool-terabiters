#include "QuizMenu.h"
#include "raylib.h"

// Configuration
const int screenWidth = 800;
const int screenHeight = 600;
const int buttonWidth = 200;
const int buttonHeight = 40;
const int buttonSpacing = 20;

bool CheckButton(Rectangle bounds, const char* text) {
    // Draw button
    DrawRectangleRec(bounds, LIGHTGRAY);
    DrawText(text,
        bounds.x + bounds.width / 2 - MeasureText(text, 20) / 2,
        bounds.y + 10,
        20, DARKGRAY);

    // Check click
    return IsMouseButtonReleased(MOUSE_LEFT_BUTTON) &&
        CheckCollisionPointRec(GetMousePosition(), bounds);
}

int Quiz_Menu() {
    InitWindow(screenWidth, screenHeight, "Quiz Manager");
    SetTargetFPS(60);

    int choice = 0;
    const int startY = (screenHeight - (5 * (buttonHeight + buttonSpacing))) / 2;

    while (!WindowShouldClose() && choice == 0) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw title
        DrawText("Quiz Manager", screenWidth / 2 - MeasureText("Quiz Manager", 40) / 2, 50, 40, DARKGRAY);

        // Create buttons
        Rectangle options[5] = {
            {(screenWidth - buttonWidth) / 2.0f, startY + 0 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
            {(screenWidth - buttonWidth) / 2.0f, startY + 1 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
            {(screenWidth - buttonWidth) / 2.0f, startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
            {(screenWidth - buttonWidth) / 2.0f, startY + 3 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
            {(screenWidth - buttonWidth) / 2.0f, startY + 4 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight}
        };

        // Check buttons
        if (CheckButton(options[0], "Create Quiz")) choice = 1;
        if (CheckButton(options[1], "Take Quiz")) choice = 2;
        if (CheckButton(options[2], "Edit Quiz")) choice = 3;
        if (CheckButton(options[3], "Delete Quiz")) choice = 4;
        if (CheckButton(options[4], "Exit")) choice = 5;

        EndDrawing();
    }

    CloseWindow();
    return choice;
}