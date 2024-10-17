#include "r_text.h"
#include <raylib.h>
#include <string.h>

static float _charsvisible = 0;
static float _maxlen = 0;
static float _speed = 0;
static char _text[256];
static Color _colour;

void r_text_typewriter_set(char* text, float speed, Color colour) {
    _maxlen = strnlen(text, 256);
    _charsvisible = 0;
    _speed = speed;
    _colour = colour;
    strncpy(_text, text, 255);
}

void r_text_typewriter_draw(float delta) {
    _charsvisible += delta;
    int n_chars = (int)_charsvisible;

    char current_visible[256];
    strncpy(current_visible, _text, n_chars);
    current_visible[n_chars] = 00;

    DrawText(current_visible, 15, 15, 32, _colour);
}