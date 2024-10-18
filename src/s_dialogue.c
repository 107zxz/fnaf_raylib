#include "s_dialogue.h"
#include "d_dialogue.h"
#include "d_colours.h"

GameState s_dialogue = {
    .window_title = "Hello, World!",
    .state_init = dialogue_init,
    .state_update = dialogue_update,
    .state_draw = dialogue_draw,
    .state_deinit = dialogue_deinit
};

void dialogue_init() {
    r_text_init();
    r_text_typewriter_set(DIA_INTRO_TEXT[0], 10.f, COL3);
}

void dialogue_deinit() {
    r_text_deinit();
}

void dialogue_update() {
    
}

void dialogue_draw() {
    r_text_typewriter_draw(GetFrameTime());
}