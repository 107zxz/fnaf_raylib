#pragma once
#include "g_state.h"

void dialogue_init();
void dialogue_update();
void dialogue_draw();
void dialogue_draw_raw();
void dialogue_deinit();

extern GameState s_dialogue;
