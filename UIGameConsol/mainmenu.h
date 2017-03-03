#ifndef MAINMENU_H
#define MAINMENU_H

#include "screen.h"
#include "../reference/game.h";
#include "../reference/gamehistory.h";
#include "../reference/player.h";
#include "../reference/playergamehistory.h";
#include "../tui/wormscreen.h";
#include "../tui/robotsscreen.h";

class mainMenu : public Screen
{
public:
    mainMenu();

    void draw_screen();
    
private:
    Player currentPlayer;
    
};

#endif // MAINMENU_H
