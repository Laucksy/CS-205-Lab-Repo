#ifndef GAME_H
#define GAME_H
#include "iostream"
#include "dbtool.h"
#include "dbtablegame.h"
#include "player.h"
class Player;
using namespace std;

class Game
{
public:
    //Constructors/Destructor
    Game();
    Game(Player *p);
    Game(Player *p, string n, int s);
    Game(const Game &obj);
    Game(Game &obj);
    ~Game();
    void operator=(const Game &obj);

    //Gets/Sets
    int get_db_id();
    void set_db_id(int i);
    int get_p_id();
    void set_p_id(int i);
    Player* get_player();
    void set_player(Player *p);
    string get_game_name();
    void set_game_name(string n);
    int get_score();
    void set_score(int s);
private:
    int db_id;
    int p_id;
    Player *player;
    string name;
    int score;
};

#endif // GAME_H
