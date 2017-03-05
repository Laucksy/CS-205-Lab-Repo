#include <iostream>
#include "dbtool.h"
#include "dbtablegame.h"
using namespace std;

int main(int argc, char *argv[])
{
    /*
    // generate database object
    DBTool *dbtool = new DBTool("LabDB");

    // print its state
    dbtool->print(std::cout);

    // generate a new table
    DBTableGame *ext = new DBTableGame(dbtool, "TableGame");
    DBTablePlayer *pdb = new DBTablePlayer(dbtool, "TablePlayer");

    //cout << "About to add info" << endl;

    pdb->add_row(0, "erik", "test", "laf");
    pdb->add_row(1, "test", "laucks", "laf");

    // add information to the new table
    ext->add_row(0, 0, "bye", 3);
    ext->add_row(1, 1, "hi", 4);
    ext->add_row(2, 1, "test", 5);
    ext->add_row(3, 1, "erik", 6);

    cout << "Select all";
    pdb->select_all();

    delete pdb;
    delete ext;*/

    PlayerGameHistory *pgh = new PlayerGameHistory();
    for(int i = 0; i < pgh->games_played(); i++) {
        //cout << pgh->get_game(i)->get_player() << endl;
    }

    return 0;
}
