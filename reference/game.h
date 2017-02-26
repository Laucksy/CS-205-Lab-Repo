#ifndef GAME_H
#define GAME_H
#include "iostream"
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
    ~Game();
    void operator=(const Game &obj);

    //Gets/Sets
    Player* get_player();
    void set_player(Player *p);
    string get_game_name();
    void set_game_name(string n);
    int get_score();
    void set_score(int s);
private:
    Player *player;
    string name;
    int score;
};

#endif // GAME_H
