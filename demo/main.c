#include <raylib.h>
#include "r_text.h"

int main() {
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Hello, Raylib!"); 
    SetTargetFPS(60); 

    r_text_typewriter_set("Hello, Amogus!", 0.5f, BLACK);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE); 
            r_text_typewriter_draw(GetFrameTime());
        EndDrawing();
    }

    CloseWindow();
}
