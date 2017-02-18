#include "screen.h"

Screen::Screen() {
    //Engine e;

    initscr();
    curs_set(0); //hides cursor from view
    cbreak(); //makes chars typed immediately available to program
    noecho(); //chars aren't echoed by getch when typed
    keypad(stdscr, TRUE); //getch returns a value representing the key typed
}

void Screen::draw_screen(Engine &e) {
    std::string display;
    clear();

    //mvprintw(2, 4, "Current Value : "); // print the state of the engine object
    //display = std::to_string(e.getRow(0));
    //mvprintw(2, 21, display.c_str());

    // print the instructions for manipulating the Value object
    mvprintw(5, 4, "Up Arrow    : increments value");
    mvprintw(6, 4, "Down Arrow  : decrements value");
    mvprintw(7, 4, "Left Arrow  : resets value to zero");
    mvprintw(8, 4, "Right Arrow : exits program");
}
