#include <raylib.h>
#include "dumblib.h"

int main() {
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Hello, Raylib!"); 
    SetTargetFPS(60); 

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE); 
            DrawText(text, 20, 20, 24, BLACK);
        EndDrawing();
    }

    CloseWindow();
}
