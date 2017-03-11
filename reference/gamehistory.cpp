#include "gamehistory.h"

//  Stores the games played for a specific player in game played order.
//  References each game played by the specific player.

/* Default constructor
 */
GameHistory::GameHistory() {
    player = nullptr;
}

/* Overloaded constructor
 * @param p - player to assign to game history
 */
GameHistory::GameHistory(Player *p) {
    player = p;
    //player->set_game_history(this);
}

/* Copy constructor
 * @param obj - game history to copy
 */
GameHistory::GameHistory(GameHistory &obj) {
    player = new Player(*obj.player);
    for(unsigned i = 0; i < obj.games.size(); i++) {
        games.push_back(new Game(*obj.games.at(i)));
    }
}

/* Default destructor
 */
GameHistory::~GameHistory() {
    //delete player;
    //for(unsigned i = 0; i < games.size(); i++) {
        //delete games.at(i);
    //}
    games.clear();
    vector<Game*>().swap(games);
}

/* Assignment operator
 * @param obj - game history to copy
 */
void GameHistory::operator=(GameHistory &obj) {
    player = obj.player;
    for(unsigned i = 0; i < obj.games.size(); i++) {
        games.push_back(obj.games.at(i));
    }
}

/* Adds a game to the history
 * @param g - game to add
 */
void GameHistory::add(Game *g) {
    g->set_player(get_player());
    games.push_back(g);
}

/* Gets the player assigned to the history
 * @return player assign to history
 */
Player* GameHistory::get_player() {
    return player;
}

/* Sets the player assigned to the history
 * @param p - player to assign
 */
void GameHistory::set_player(Player *p) {
    player = p;
}

/* Gets the game at a given index in the history
 * @param index - index to retrieve from
 * @return game at the specified index
 */
Game* GameHistory::get_game(int index) {
    return games[index];
}

/* Gets the number of games in the history
 * @return the number of games
 */
int GameHistory::get_num_games() {
    return (int)games.size();
}
