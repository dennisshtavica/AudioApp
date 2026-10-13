#include "raylib.h"

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 950;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Audio App");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground((Color){3, 12, 26, 1});

        Rectangle uploadButton = {50, 100, 200, 50};

        DrawRectangleRounded(
            uploadButton,
            0.2f,
            8,
            (Color){80, 100, 220, 255});

        DrawText("Upload Audio", 80, 116, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}