#include "raylib.h"

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 850;

    InitWindow(screenWidth, screenHeight, "Doodle Jump");

    Texture2D doodle = LoadTexture("resources/doodle.png");
    
    int frameWidth = doodle.width;
    int frameHeight = doodle.height;

    Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };

    // Doodle'ı ekranın ortasına hizala
    Rectangle destRec = { screenWidth / 2.0f - frameWidth / 2.0f, screenHeight / 2.0f - frameHeight / 4.0f, (float)frameWidth, (float)frameHeight };

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT) && destRec.x + frameWidth < screenWidth)
        {
            destRec.x += 5; // Sağa hareket
        }
        if (IsKeyDown(KEY_LEFT) && destRec.x > 0)
        {
            destRec.x -= 5; // Sola hareket
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexturePro(doodle, sourceRec, destRec, (Vector2){ 0 }, 0, WHITE);

        EndDrawing();
    }

    UnloadTexture(doodle);
    CloseWindow();

    return 0;
}
