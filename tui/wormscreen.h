#ifndef WORMSCREEN_H
#define WORMSCREEN_H

#include "../engines/worm.h"
#include "screen.h"
class WormScreen: public Screen
{
public:
    WormScreen();
    void draw_screen(Worm &e);
};

#endif // WORMSCREEN_H
