#include "wormscreen.h"

WormScreen::WormScreen() : Screen::Screen()
{
    Worm worm(20,77);
    worm.init();
    start:
    while(worm.alive){
        draw_screen(worm);
        refresh();

        int ch = getch(); // obtain character from keyboard

        // operate based on input character
        switch (ch) {
        case 119:
            worm.move(0,1);
            break;
        case 259:
            worm.move(0,1);
            break;
        case 87:
            worm.move(0,5);
            break;
        case 337:
            worm.move(0,5);
            break;
        case 68:
            worm.move(1,5);
            break;
        case 402:
            worm.move(1,5);
            break;
        case 100:
            worm.move(1,1);
            break;
        case 261:
            worm.move(1,1);
            break;
        case 115:
            worm.move(2,1);
            break;
        case 258:
            worm.move(2,1);
            //goto stop;
            break;
        case 83:
            worm.move(2,5);
            break;
        case 336:
            worm.move(2,5);
            break;
        case 97:
            worm.move(3,1);
            break;
        case 260:
            worm.move(3,1);
            break;
        case 65:
            worm.move(3,5);
            break;
        case 393:
            worm.move(3,5);
            break;

        default:
            ;
        }
    }
    stop:
    clear();
    mvprintw(0,0, "You have died");
    mvprintw(1,0,"Your score was: ");
    std::string s = std::to_string(worm.length-4);
    mvprintw(1,16, s.c_str());
    mvprintw(10,20, "Do you want to replay (y/n)");
    int response = getch();
    if(response == 121)
    {
       worm = *(new Worm(20,77));
       worm.alive = true;
       worm.init();
       draw_screen(worm);
       refresh();
       clear();
       //refresh();
       goto start;
    }else{

        endwin(); // cleanup the window and return control to bash

    }

}

void WormScreen::draw_screen(Worm &w)
{
    std::string display;
    clear();


    //Display title and score
    mvprintw(0, 0, "Worms");
    mvprintw(0,70, "Score: ");
    std::string s = std::to_string(w.length - 4);
    mvprintw(0,77, s.c_str());

    for(int x = 0; x<= w.getCols(); x++)
    {
        mvprintw(1, x, "*");
        mvprintw(w.getRows()+2, x, "*");
    }
    for(int y = 0; y <= w.getRows(); y++)
    {
        mvprintw(y + 1, 0, "*");
        mvprintw(y + 1, w.getCols() + 1, "*");
    }

    for(int r = 0; r <w.getRows(); r++)
    {
        for(int c = 0; c < w.getCols(); c++)
        {
            display += w.get(r,c);
        }
        mvprintw(2+r, 1, display.c_str());
        display = "";
    }
/*
    int ch = getch();
    std::string i = std::to_string(ch);
    mvprintw(10,10,i.c_str());*/
}
