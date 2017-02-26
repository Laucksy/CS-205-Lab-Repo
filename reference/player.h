#ifndef PLAYER_H
#define PLAYER_H
#include "iostream"
#include "game.h"
class Game;
#include "gamehistory.h"
class GameHistory;
using namespace std;

class Player
{
public:
    //Constructors/Destructor
    Player();
    Player(Game *g, GameHistory *h);
    Player(Game *g, GameHistory *h, string fn, string ln, string a);
    Player(const Player &obj);
    ~Player();
    void operator=(const Player &obj);

    //Modify history
    void add(Game *g);

    //Gets/Sets
    Game* get_game();
    void set_game(Game *g);
    GameHistory* get_game_history();
    void set_game_history(GameHistory *h);
    string get_player_firstname();
    void set_player_firstname(string n);
    string get_player_lastname();
    void set_player_lastname(string n);
    string get_player_address();
    void set_player_address(string n);
private:
    Game *game;
    GameHistory *history;
    string firstName;
    string lastName;
    string address;
};

#endif // PLAYER_H
