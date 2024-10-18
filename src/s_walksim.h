#pragma once
#include "g_state.h"

void walksim_init();
void walksim_update();
void walksim_draw();
void walksim_deinit();

#define WALK_SPEED 25

extern GameState s_walksim;
