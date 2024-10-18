#include "r_window.h"
#include <raylib.h>
#include "g_state.h"

void r_window_init()
{
    InitWindow(R_WIN_DEFAULT_WIDTH, R_WIN_DEFAULT_HEIGHT, g_state.window_title);
    SetTargetFPS(60);
}
