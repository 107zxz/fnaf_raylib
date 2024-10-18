#include "r_text.h"
#include <raylib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

static float _charsvisible = 0;
static float _maxlen = 0;
static float _speed = 0;
static char _text[DBOX_CAPACITY + 2];
static Color _colour;
static Font _font;

void r_text_init() {
    _font = LoadFontEx("resc/fonts/kongtext.ttf", 8, 0, 256);
}

void r_text_deinit() {
    UnloadFont(_font);
}

void _word_wrap(char* input, int max_length) {
    int lastspace = 0, i = 0, linelen = 0;

    while (input[i] != 00) {
        if (linelen >= max_length) {
            input[lastspace] = '\n';
            linelen = i - lastspace;
        }
        if (input[i] == ' ' || input[i] == '\n') {
            lastspace = i;
        }
        i++;
        linelen++;
    }
}

void r_text_typewriter_set(char* text, float speed, Color colour) {
    _maxlen = strnlen(text, DBOX_CAPACITY);
    _charsvisible = 0;
    _speed = speed;
    _colour = colour;
    strncpy(_text, text, DBOX_CAPACITY);
    _word_wrap(_text, DBOX_WIDTH);
}

void r_text_typewriter_draw(float delta) {
    _charsvisible = fminf(_charsvisible + delta * _speed, (float)_maxlen);
    int nchars = (int)_charsvisible;

    char current_visible[DBOX_CAPACITY+1];

    strncpy(current_visible, _text, DBOX_CAPACITY);
    current_visible[nchars] = 00;

    DrawTextEx(_font, current_visible, (Vector2){DBOX_LEFTPAD, DBOX_TOPPAD}, (float)_font.baseSize, 1, _colour);
}

int r_text_typewriter_complete() {
    return (int)_charsvisible >= _maxlen;
}

void r_text_typewriter_reset() {
    _charsvisible = 0.f;
}

void r_text_typewriter_skip() {
    _charsvisible = _maxlen;
}
