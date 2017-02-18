#ifndef ROBOTSSCREEN_H
#define ROBOTSSCREEN_H
#include "../engines/robots.h"
#include "screen.h"

class RobotsScreen : public Screen
{
    public:
        RobotsScreen();

        void draw_screen(Robots &r);
};

#endif // ROBOTSSCREEN_H
