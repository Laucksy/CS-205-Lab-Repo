#include "game.h"

//  Contains information about the game that was played.
//  References the player that played it.
//  Stores the following information:
//      Name of game.
//      Final score.

/* Default constructor
 */
Game::Game() {
    player = nullptr;
    name = "";
    score = 0;
}

/* Overloaded constructor
 * @param p - player to assign to game
 */
Game::Game(Player *p) {
    player = p;
    name = "";
    score = 0;
    player->add(this);
}

/* Overloaded constructor
 * @param p - player to assign to game
 * @param n - name of the game
 * @param s - score of the game
 */
Game::Game(Player *p, string n, int s) {
    player = p;
    player->add(this);
    name = n;
    score = s;
}

/* Copy construcor
 * @param obj - object to copy (const because vectors)
 */
Game::Game(const Game &obj) {
    player = obj.player;
    name = obj.name;
    score = obj.score;
}

/* Default destructor
 */
Game::~Game() {
    delete player;
}

/* Assignment operator
 * @param obj - object to copy (const because vectors)
 */
void Game::operator=(const Game &obj) {
    player = obj.player;
    name = obj.name;
    score = obj.score;
}

/* Gets the player assigned to the game
 * @return player on the game
 */
Player* Game::get_player() {
    return player;
}

/* Sets the player assigned to the game
 * @param p - the player to assign
 */
void Game::set_player(Player *p) {
    player = p;
    //player->set_game_history(new GameHistory(player));
}

/* Gets the name of the game
 * @return name of the game
 */
string Game::get_game_name() {
    return name;
}

/* Sets the name of the game
 * @param n - name to assign
 */
void Game::set_game_name(string n) {
    name = n;
}

/* Gets the score of the game
 * @return score of the game
 */
int Game::get_score() {
    return score;
}

/* Sets the score of the game
 * @param s - score to assign
 */
void Game::set_score(int s) {
    score = s;
}
