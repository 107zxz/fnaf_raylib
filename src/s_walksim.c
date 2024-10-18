#include "s_walksim.h"
#include "d_colours.h"
#include "g_input.h"
#include "r_window.h"
#include "s_grass.h"
#include <raylib.h>

GameState s_walksim = {.window_title = "Hideo Kojima",
                        .state_init = walksim_init,
                        .state_update = walksim_update,
                        .state_draw = walksim_draw,
                        .state_draw_raw = walksim_draw_raw,
                        .state_deinit = walksim_deinit};

static float progress;

void walksim_init() {
  progress = 15;
}

void walksim_deinit() {

}

void walksim_update() {
    if (IsKeyDown(KEY_UP))
      progress += GetFrameTime() * WALK_SPEED;

    if (progress > 40 * WALK_SPEED) {
      g_state_switch(s_grass);
    }
}

void walksim_draw() {

  float rectSize3 = (progress + 80);
  DrawRectangle(GB_WIDTH / 2 - rectSize3 / 2, GB_HEIGHT / 2 - rectSize3 / 2, rectSize3, rectSize3, COL1);
  DrawRectangle(GB_WIDTH / 2 - rectSize3 / 2 + 1, GB_HEIGHT / 2 - rectSize3 / 2 + 1, rectSize3-2, rectSize3-2, COL0);

  float rectSize2 = (progress + 40);
  DrawRectangle(GB_WIDTH / 2 - rectSize2 / 2, GB_HEIGHT / 2 - rectSize2 / 2, rectSize2, rectSize2, COL1);
  DrawRectangle(GB_WIDTH / 2 - rectSize2 / 2 + 1, GB_HEIGHT / 2 - rectSize2 / 2 + 1, rectSize2-2, rectSize2-2, COL0);

  float rectSize = progress;
  DrawRectangle(GB_WIDTH / 2 - rectSize / 2, GB_HEIGHT / 2 - rectSize / 2, rectSize, rectSize, COL1);

  DrawLine(0, 0 - (GB_WIDTH - GB_HEIGHT)/2, GB_WIDTH, GB_WIDTH - (GB_WIDTH - GB_HEIGHT)/2, COL1);
  DrawLine(GB_WIDTH, 0 -(GB_WIDTH - GB_HEIGHT)/2, 0, GB_WIDTH - (GB_WIDTH - GB_HEIGHT)/2, COL1);

  DrawRectangle(GB_WIDTH / 2 - rectSize / 2 + 1, GB_HEIGHT / 2 - rectSize / 2 + 1, rectSize-2, rectSize-2, COL0);

  DrawRectangle(GB_WIDTH / 2 - rectSize / 4 + 1, GB_HEIGHT / 2 - rectSize / 3 + 1, rectSize / 2 - 2, rectSize * 5.f / 6.f - 1.f, COL2);
}

void walksim_draw_raw() {

}