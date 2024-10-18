#pragma once

#include <raylib.h>

#define DBOX_LEFTPAD 8
#define DBOX_TOPPAD 8
#define DBOX_WIDTH 16
#define DBOX_LINES 9
#define DBOX_CAPACITY (DBOX_WIDTH * DBOX_LINES)

void r_text_typewriter_set(char* text, float speed, Color colour);
void r_text_typewriter_draw(float delta);
int r_text_typewriter_complete();
void r_text_typewriter_skip();
void r_text_typewriter_reset();
void r_text_init();
void r_text_deinit();