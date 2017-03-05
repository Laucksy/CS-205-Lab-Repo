#include "screen.h"

Screen::Screen()
{
    initscr();
    curs_set(0); //hides cursor from view
    cbreak(); //makes chars typed immediately available to program
    noecho(); //chars aren't echoed by getch when typed
    keypad(stdscr, TRUE); //getch returns a value representing the key typed
}
