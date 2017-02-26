#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H
#include "iostream"
#include "vector"
#include "player.h"
class Player;
#include "game.h"
class Game;
using namespace std;


class PlayerGameHistory
{
public:
    //Constructors/Destructor
    PlayerGameHistory();
    PlayerGameHistory(PlayerGameHistory &obj);
    ~PlayerGameHistory();
    void operator=(PlayerGameHistory &obj);

    //Modify vectors
    void add_player(Player *p);
    void add_game(Game *g);
    Player* get_player(int index);
    Game* get_game(int index);

    //Statistics
    int games_played(); //Number of games played.
    int num_players(); //Number of players that have played games.
    float avg_games_per_player(); //Average games played per player.
    int top_score(); //Top game score.
    float avg_game_score(); //Average game score for all games.
    float avg_score_for_player(Player *p); //What was the average score for a specific player.

private:
    vector<Player*> players;
    vector<Game*> games;
};

#endif // PLAYERGAMEHISTORY_H
