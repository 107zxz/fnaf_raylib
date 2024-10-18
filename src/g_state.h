#pragma once

typedef struct GameState {
    char* window_title;
    void (*state_init)();
    void (*state_deinit)();
    void (*state_update)();
    void (*state_draw)();
    void (*state_draw_raw)();
} GameState;

extern GameState g_state;

void g_state_switch(GameState new_state);