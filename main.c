#include <raylib.h>

int main() {
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Hello, Raylib!"); 
    SetTargetFPS(60); 

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE); 
            DrawText("Congat!", 20, 20, 24, BLACK);
        EndDrawing();
    }

    CloseWindow();
}
