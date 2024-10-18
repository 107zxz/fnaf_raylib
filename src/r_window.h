#pragma once
#include "h_math.h"

#define GB_WIDTH 160
#define GB_HEIGHT 144
#define GB_ASPECT (GB_WIDTH / GB_HEIGHT)

#define R_WIN_SCALEFACTOR 4
#define R_WIN_DEFAULT_WIDTH (R_WIN_DEFAULT_HEIGHT * GB_ASPECT)
#define R_WIN_DEFAULT_HEIGHT (GB_HEIGHT * R_WIN_SCALEFACTOR)

#define R_WIN_GAME_WIDTH (min(GB_ASPECT * GetScreenHeight(), GetScreenWidth()))
#define R_WIN_GAME_HEIGHT (min(GetScreenHeight(), GB_ASPECT * GetScreenWidth()))
#define R_WIN_GAME_OFFSET_X ((GetScreenWidth() - R_WIN_GAME_WIDTH) / 2)
#define R_WIN_GAME_OFFSET_Y ((GetScreenHeight() - R_WIN_GAME_HEIGHT) / 2)

void r_window_init();
void r_window_draw();