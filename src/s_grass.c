#include "s_grass.h"
#include <raylib.h>

GameState s_grass = {.window_title = "Now go take a shower!",
                    .state_init = grass_init,
                    .state_update = grass_update,
                    .state_draw = grass_draw,
                    .state_deinit = grass_deinit,
                    .state_draw_raw = grass_draw_raw};

static Texture2D grass;

void grass_init() {
    grass = LoadTexture("resc/gfx/grass.png");
}

void grass_update() {

}

void grass_draw() {
}

void grass_deinit() {
    UnloadTexture(grass);
}

void grass_draw_raw() {
    DrawTexturePro(
        grass,
        (Rectangle){0, 0, grass.width, grass.height},
        (Rectangle){0, 0, GetScreenWidth(), GetScreenHeight()},
        (Vector2){0., 0.},
        0.f,
        WHITE);
}