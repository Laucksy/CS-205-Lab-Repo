#include "newplayer.h"

newPlayer::newPlayer()
{

    FIELD *field[4];
        FORM  *my_form;
    // initialize displayed fields

        // The parameters below are as follows:
        //  1. int height    -- The number of rows in the field.
        //  2. int width     -- The row width of the field.
        //  3. int toprow    -- The screen row where the field top is placed.
        //  4. int leftcol   -- The screen col where the field left-side is placed.
        //  5. int offscreen -- Zero shows entire field.
        //  6. int nbuffers  -- Number of additional buffers, use zero.

        field[0] = new_field(1, 20, 4, 27, 0, 0);
        field[1] = new_field(1, 20, 6, 27, 0, 0);
        field[2] = new_field(1, 20, 8, 27, 0, 0);

        // Tag end of array so ncurses knows when there are no
        // more fields.
        field[3] = NULL;

        // Initialize the interaction loop to run.
        bool continue_looping = true;

        /******** Set field options ********/

        // Print a line for the option.
        set_field_back(field[0], A_UNDERLINE);
        set_field_back(field[1], A_UNDERLINE);
        set_field_back(field[2], A_UNDERLINE);

        //  Don't go to next field when this field is filled up.
        field_opts_off(field[0], O_AUTOSKIP);
        field_opts_off(field[1], O_AUTOSKIP);
        field_opts_off(field[2], O_AUTOSKIP);

        //Make it so fields will expand to fit more characters
        //field_opts_off(field[0], O_STATIC);

        /******** Create form. ********/

        // Create the form and post it.
        my_form = new_form(field);
        post_form(my_form);

        // build the form
        refresh();

        // display labels
        mvprintw(4, 10, "Enter First Name:");
        mvprintw(6, 10, "Enter Last Name:");
        mvprintw(8, 10, "Enter Address:");

        // perform last refresh
        refresh();
        /******* Loop through to get user requests *******/

        do {
            // obtain character from keyboard
            int ch = getch();

            switch(ch) {
            case KEY_DOWN:

                // go to next field
                form_driver(my_form, REQ_NEXT_FIELD);

                // Go to the end of the present buffer
                // and leave nicely at the last character
                form_driver(my_form, REQ_END_LINE);

                break;

            case KEY_UP:

                // go to previous field
                form_driver(my_form, REQ_PREV_FIELD);

                // Go to the end of the present buffer
                // and leave nicely at the last character
                form_driver(my_form, REQ_END_LINE);

                break;

            case KEY_BACKSPACE:
                //delete last character from the space
                form_driver(my_form, REQ_PREV_CHAR);
                form_driver(my_form, REQ_DEL_CHAR);
                break;
            case 9:
                form_driver(my_form, REQ_NEXT_FIELD);

                form_driver(my_form, REQ_END_LINE);
                break;
            case KEY_LEFT:
                // exit from loop
                continue_looping = false;
                // stores the buffer on the field it is located
                form_driver(my_form, REQ_END_LINE);
                break;
            default:
                // If this is a normal character, print it.
                form_driver(my_form, ch);
                break;
            }

        } while (continue_looping);



//        /******* Close down the window and print fields. *******/
//        // Un post form and free the memory
       unpost_form(my_form);
        free_form(my_form);

//        // store contents of fields before they are freed
//        player.set_player_firstname(field_buffer(field[0], 0));
//        player.set_player_lastname(field_buffer(field[1], 0));
//        player.set_player_address(field_buffer(field[2], 0));

        // free the fields
        free_field(field[0]);
        free_field(field[1]);

//        // exit ncurses environment
          //endwin();

}
