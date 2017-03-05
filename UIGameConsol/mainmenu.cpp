#include "mainmenu.h"
#include <string>
#include <iostream>
#include <form.h>

mainMenu::mainMenu()
{
    refresh();
    draw_screen();
    bool selected = false;
    while(!selected){
        draw_screen();
        int ch = getch();
        switch(ch){
        case(97):{
            //create new player
            newPlayer();

            mvprintw(0,0,"CAtr");
            refresh();
            for(int x = 0; x<300000000; x++)
            {
            }
            //currentPlayer = createPlayer.player;
        }break;
        case(98):
            //select a player
            break;
        case(99):
            //display top three players
            break;
        case(100):
            //display top three games played
            break;
        case(101):
            //display calculated stats
            break;
        case(102):
            //play robots
            break;
        case(103):
            //play worm
            break;
        case(113):
            //exit
            break;
            
        }

    }

}

void mainMenu::draw_screen()
{
    clear();

    std::string playerName = "Current Player: ";
    if(currentPlayer.get_player_firstname() != "")
    {
        playerName += currentPlayer.get_player_firstname() + " " + currentPlayer.get_player_lastname();
    }else{ playerName += "No Current Player";}
    mvprintw(1,1, playerName.c_str());
    mvprintw(3, 1, "a. Create a New Player \n "
                   "b. Select an Existing Player \n \n "
                   "c. Display Top Three Players \n "
                   "d. Display Top Three Games Played \n "
                   "e. Display Calculated Statistics \n \n"
                   "f. Play Robots \n "
                   "g. Play Worm \n \n "
                   "q. Exit Program ");
/*
    int ch = getch();
    std::string i = std::to_string(ch);
    mvprintw(10,10,i.c_str());
*/
    refresh();
}
