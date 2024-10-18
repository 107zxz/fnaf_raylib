#include "s_dialogue.h"
#include "s_walksim.h"
#include "d_dialogue.h"
#include "d_colours.h"
#include "g_input.h"
#include "r_text.h"
#include <raylib.h>

GameState s_dialogue = {.window_title = "Hello, World!",
                        .state_init = dialogue_init,
                        .state_update = dialogue_update,
                        .state_draw = dialogue_draw,
                        .state_deinit = dialogue_deinit};

static int current_line = 0;

void dialogue_init()
{
  current_line = 0;
  r_text_init();
  r_text_typewriter_set(DIA_INTRO_TEXT[0], 25.f, COL2);
}

void dialogue_deinit()
{
  r_text_deinit();
}

void dialogue_update()
{
  if (g_input_skip())
    r_text_typewriter_skip();

  if (g_input_confirm() && r_text_typewriter_complete())
    r_text_typewriter_set(DIA_INTRO_TEXT[++current_line], 25.f, COL2);

  if (current_line >= DIA_INTRO_N)
    g_state_switch(s_walksim);
}

void dialogue_draw()
{
  r_text_typewriter_draw(GetFrameTime());
}
