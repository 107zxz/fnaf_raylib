#pragma once

#include <raylib.h>

#define g_input_confirm() (IsKeyPressed(KEY_Z) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
#define g_input_skip() IsKeyPressed(KEY_X)
#define g_input_fullscreen() IsKeyPressed(KEY_F)
#define g_input_forward() (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))