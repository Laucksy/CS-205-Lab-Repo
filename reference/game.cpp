#include "game.h"

//  Contains information about the game that was played.
//  References the player that played it.
//  Stores the following information:
//      Name of game.
//      Final score.

/* Default constructor
 */
Game::Game() {
    db_id = -1;
    p_id = -1;
    player = nullptr;
    name = "";
    score = 0;
}

/* Overloaded constructor
 * @param p - player to assign to game
 */
Game::Game(Player *p) {
    db_id = -1;
    p_id = -1;
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
    db_id = -1;
    p_id = -1;
    player = p;
    player->add(this);
    name = n;
    score = s;
}

/* Copy construcor
 * @param obj - object to copy (const because vectors)
 */
Game::Game(const Game &obj) {
    db_id = obj.db_id;
    p_id = obj.p_id;
    player = obj.player;
    name = obj.name;
    score = obj.score;
}

/* Default destructor
 */
Game::~Game() {
    DBTool *dbtool = new DBTool("LabDB");
    DBTableGame *ext = new DBTableGame(dbtool, "TableGame");
    if(db_id == -1)
        ext->add_row(rand() % 10000, p_id, name, score);
    else if(!ext->add_row(db_id, p_id, name, score))
        ext->update(db_id, p_id, name, score);
    delete player;
}

/* Assignment operator
 * @param obj - object to copy (const because vectors)
 */
void Game::operator=(const Game &obj) {
    db_id = obj.db_id;
    p_id = obj.p_id;
    player = obj.player;
    name = obj.name;
    score = obj.score;
}

/* Gets the id assigned to the game in the db
 * @return id on the game
 */
int Game::get_db_id() {
    return db_id;
}

/* Sets the id assigned to the game
 * @param i - new id
 */
void Game::set_db_id(int i) {
    db_id = i;
}

/* Gets the id assigned to the game's player
 * @param i - new id
 */
int Game::get_p_id() {
    return p_id;
}

/* Gets the player assigned to the game
 * @return player on the game
 */
void Game::set_p_id(int i) {
    p_id = i;
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
