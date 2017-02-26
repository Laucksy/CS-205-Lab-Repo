#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H
#include "iostream"
#include "vector"
#include "player.h"
class Player;
#include "game.h"
class Game;
using namespace std;


class GameHistory
{
public:
    //Constructors/Destructor
    GameHistory();
    GameHistory(Player *p);
    GameHistory(GameHistory &obj);
    ~GameHistory();
    void operator=(GameHistory &obj);

    //Modify vector
    void add(Game *g);

    //Gets/Sets
    Player* get_player();
    void set_player(Player *p);
    Game* get_game(int index);
    int get_num_games();
private:
    Player *player;
    vector<Game*> games;
};

#endif // GAMEHISTORY_H
