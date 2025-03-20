#include "QuizMenu.h"
#include "raylib.h"

int Quiz_Menu() {
    const int buttonWidth = 400;
    const int buttonHeight = 60;
    const int buttonSpacing = 20;
    int choice = 0;

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int startY = (screenHeight - (5 * (buttonHeight + buttonSpacing))) / 2;

    Rectangle options[5] = {
        {(screenWidth - buttonWidth) / 2.0f, startY + 0 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
        {(screenWidth - buttonWidth) / 2.0f, startY + 1 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
        {(screenWidth - buttonWidth) / 2.0f, startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
        {(screenWidth - buttonWidth) / 2.0f, startY + 3 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight},
        {(screenWidth - buttonWidth) / 2.0f, startY + 4 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight}
    };

    const char* buttonTexts[5] = {
        "Create Quiz", "Take Quiz",
        "Edit Quiz", "Delete Quiz", "Exit"
    };

    while (!WindowShouldClose() && choice == 0) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw title
        DrawText("Quiz Manager",
            screenWidth / 2 - MeasureText("Quiz Manager", 40) / 2,
            50, 40, DARKGRAY);

        // Draw buttons with hover effect
        for (int i = 0; i < 5; i++) {
            Color btnColor = CheckCollisionPointRec(GetMousePosition(), options[i]) ?
                Color{ 200, 200, 200, 255 } : LIGHTGRAY;

            DrawRectangleRec(options[i], btnColor);
            DrawText(buttonTexts[i],
                options[i].x + options[i].width / 2 - MeasureText(buttonTexts[i], 30) / 2,
                options[i].y + 15, 30, DARKGRAY);
        }

        // Check clicks
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            for (int i = 0; i < 5; i++) {
                if (CheckCollisionPointRec(mousePos, options[i])) {
                    choice = i + 1;
                    break;
                }
            }
        }

        // Handle ESC key for closing
        if (IsKeyPressed(KEY_ESCAPE)) {
            choice = 5;
        }

        EndDrawing();
    }

    return choice;
}