#include "g_state.h"
#include <raylib.h>

GameState g_state;

void g_state_switch(GameState new_state) {
    g_state.state_deinit();
    g_state = new_state;
    g_state.state_init();

    SetWindowTitle(g_state.window_title);
}