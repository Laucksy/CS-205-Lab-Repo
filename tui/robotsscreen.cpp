#include "robotsscreen.h"

RobotsScreen::RobotsScreen() {
    Robots robot(20,50);
    robot.init_board(robot.get_init_bots());
    bool continue_looping = true; // initialize the interaction loop to run
    draw_screen(robot, 0); // draw the current screen

    //Log logger("screenLog.txt");
    //logger.open_append();
    do {
        refresh(); // draw the new screen
        int ch = getch(); // obtain character from keyboard

        // operate based on input character
        switch (ch) {
        case 104:
            robot.turn('h');
            break;
        case 106:
            robot.turn('j');
            break;
        case 107:
            robot.turn('k');
            break;
        case 108:
            robot.turn('l');
            break;
        case 121:
            robot.turn('y');
            break;
        case 117:
            robot.turn('u');
            break;
        case 98:
            robot.turn('b');
            break;
        case 110:
            robot.turn('n');
            break;
        case 72:
            robot.turn('H');
            break;
        case 74:
            robot.turn('J');
            break;
        case 75:
            robot.turn('K');
            break;
        case 76:
            robot.turn('L');
            break;
        case 89:
            robot.turn('Y');
            break;
        case 85:
            robot.turn('U');
            break;
        case 66:
            robot.turn('B');
            break;
        case 78:
            robot.turn('N');
            break;
        case 119:
            robot.turn('w');
            break;
        case 62:
            robot.turn('>');
            break;
        case 46:
            robot.turn('.');
            break;
        case 32:
            robot.turn(' ');
            break;
        case 116:
            robot.turn('t');
            break;
        case 113:
            robot.turn('q');
            break;
        case 12:
            draw_screen(robot, 0);
            break;
        case KEY_RIGHT:
            //continue_looping = false; //Comment out when not debugging
            break;
        default:
            //logger << ch << '\n'; //Comment out when not debugging
            break;
        }

        draw_screen(robot, 0);

        if(robot.won()) {
            robot.level();
            draw_screen(robot, 0);
            //continue_looping = false;
            //std::cout << "Congrats! You won!" << std::endl;
        }
        if(robot.lost()) {
            draw_screen(robot, 1);
            int answer = 0;
            while(answer != 121 && answer != 110) {
                answer = getch();
            }
            if(answer == 121) {
                robot = *(new Robots(robot.getRows(), robot.getCols()));
                robot.init_board(robot.get_init_bots());
                draw_screen(robot, 0);
            } else {
                continue_looping = false;
            }
        }

    } while(continue_looping);

    endwin(); // cleanup the window and return control to bash
    //std::cout << "exiting game\n";
}

void RobotsScreen::draw_screen(Robots &r, int type) {
    std::string display;
    clear();

    display = "+";
    for(int i = 0; i < r.getCols(); i++) {
        display += "-";
    }
    display += "+";
    mvprintw(0, 0, display.c_str());

    for(int i = 0; i < r.getRows(); i++) {
        display = "|";
        for(int j = 0; j < r.getCols(); j++) {
            display += r.get(i,j);
        }
        display += "|";
        mvprintw(1+i, 0, display.c_str());
    }

    display = "+";
    for(int i = 0; i < r.getCols(); i++) {
        display += "-";
    }
    display += "+";
    mvprintw(1 + r.getRows(), 0, display.c_str());

    // print the instructions for playing the game
    mvprintw(0, 3 + r.getCols(), "Directions:");
    mvprintw(2, 3 + r.getCols(), "y k u");
    mvprintw(3, 3 + r.getCols(), " \\|/");
    mvprintw(4, 3 + r.getCols(), "h- -l");
    mvprintw(5, 3 + r.getCols(), " /|\\");
    mvprintw(6, 3 + r.getCols(), "b j n");
    mvprintw(8, 3 + r.getCols(), "Commands:");
    mvprintw(10, 3 + r.getCols(), "w:  wait for end");
    mvprintw(11, 3 + r.getCols(), "t:  teleport");
    mvprintw(12, 3 + r.getCols(), "q:  quit");
    mvprintw(13, 3 + r.getCols(), "^L: redraw screen");
    mvprintw(15, 3 + r.getCols(), "Legend:");
    mvprintw(17, 3 + r.getCols(), "+:  robot");
    mvprintw(18, 3 + r.getCols(), "*:  junk heap");
    mvprintw(19, 3 + r.getCols(), "@:  you");

    if(type == 0) {
        std::string scoreMessage = "Score: " + std::to_string(r.get_score());
        mvprintw(21, 3 + r.getCols(), scoreMessage.c_str());
    } else {
        mvprintw(21, 3 + r.getCols(), "Another game? (y/n)");
    }
}
