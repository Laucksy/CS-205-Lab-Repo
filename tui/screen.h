#ifndef SCREEN_H
#define SCREEN_H
#include "../engines/engine.h"
#include "../tools/log.h"
#include "curses.h"
#include "iostream"
#include "string"

class Screen
{
public:
    Screen();

    void draw_screen(Engine &e);
};

#endif // SCREEN_H
