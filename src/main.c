#include <raylib.h>
#include "g_state.h"
#include "r_text.h"
#include "r_window.h"
#include "g_input.h"
#include "s_dialogue.h"
#include "d_colours.h"
#include "s_walksim.h"
#include "s_grass.h"

void load_plugins() {
  r_window_init();
  g_state.state_init();
}

int main() {
  g_state = s_dialogue;

  load_plugins();

  // Pixellate
  RenderTexture2D target = LoadRenderTexture(GB_WIDTH, GB_HEIGHT);

  while (!WindowShouldClose()) {

    g_state.state_update();

    BeginTextureMode(target);
      ClearBackground(COL0);

      g_state.state_draw();
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

    g_state.state_draw_raw();

    EndDrawing();
  }

  UnloadRenderTexture(target);

  g_state.state_deinit();

  CloseWindow();
}
