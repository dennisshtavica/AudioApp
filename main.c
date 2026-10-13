// #include <windows.h>
// #include <commdlg.h>
#include "raylib.h"
#include "UploadFile/file_picker.h"

int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 950;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Audio App");
    SetTargetFPS(60);
    Font appFont = LoadFont("fonts/NotoSans-Medium.ttf");


    char filePath[1024] = "";

    while (!WindowShouldClose())
    {

        Rectangle uploadButton = {50, 25, 200, 50};

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mouse = GetMousePosition();

            if (CheckCollisionPointRec(mouse, uploadButton))
            {
                if (OpenAudioFile(filePath, sizeof(filePath)))
                {
                    TraceLog(LOG_INFO, "Selected file: %s", filePath);
                }
            }
        }

        BeginDrawing();
        ClearBackground((Color){3, 12, 26, 1});

        DrawRectangleRounded(
            uploadButton,
            0.2f,
            8,
            (Color){80, 100, 220, 255});

        DrawTextEx(appFont, "Upload Audio", (Vector2){95, 40}, 20, 1, WHITE);
        DrawTextEx(appFont, filePath, (Vector2){50, 100}, 16, 1, WHITE);

        EndDrawing();
    }

    UnloadFont(appFont);
    CloseWindow();
    return 0;
}