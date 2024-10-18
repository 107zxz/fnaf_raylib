#include <raylib.h>
#include "r_text.h"
#include "r_window.h"
#include "g_input.h"
#include "s_dialogue.h"
#include "d_colours.h"

void load_plugins() {
    r_window_init();

    s_dialogue.state_init();
}

int main() {

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    load_plugins();

    // Pixellate
    RenderTexture2D target = LoadRenderTexture(GB_WIDTH, GB_HEIGHT);

    while (!WindowShouldClose()) {

        BeginTextureMode(target);
            ClearBackground(COL0);

            s_dialogue.state_draw();
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(
                target.texture,
                (Rectangle){0.0, 0.0, GB_WIDTH, -GB_HEIGHT},
                (Rectangle){R_WIN_GAME_OFFSET_X, R_WIN_GAME_OFFSET_Y, R_WIN_GAME_WIDTH, R_WIN_GAME_HEIGHT},
                (Vector2){0.0, 0.0},
                0.0f,
                WHITE
            );
        EndDrawing();
    }

    UnloadRenderTexture(target);

    s_dialogue.state_deinit();

    CloseWindow();
}
