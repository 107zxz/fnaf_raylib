#pragma once
#include "g_state.h"

void walksim_init();
void walksim_update();
void walksim_draw();
void walksim_draw_raw();
void walksim_deinit();

#define WALK_SPEED 5

extern GameState s_walksim;
