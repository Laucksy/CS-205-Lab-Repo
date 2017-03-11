#include "player.h"

/*
//  Contains information about the player.
//  Object references the most recent game played.
//  Object references a GameHistory class that tracks all games played.
//  When Player Object plays a new game, the reference to current game
//      is stored in GameHistory and a reference is stored to the new game.
//  Stores the following information:
//      Player First Name.
//      Player Last Name.
//      Player Address.
*/

/* Default constructor
 */
Player::Player() {
    db_id = -1;
    game = nullptr;
    history = new GameHistory(this);
    firstName = "";
    lastName = "";
    address = "";
}

/* Overloaded constructor
 * @param g - game to add to player
 * @param h - game history to assign to player
 */
Player::Player(Game *g, GameHistory *h) {
    db_id = -1;
    game = g;
    game->set_player(this);
    history = h;
    history->set_player(this);
}

/* Overloaded constructor
 * @param g - game to add to player
 * @param h - game history to assign to player
 * @param fn - first name of the player
 * @param ln - last name of the player
 * @param a - address of the player
 */
Player::Player(Game *g, GameHistory *h, string fn, string ln, string a) {
    db_id = -1;
    game = g;
    game->set_player(this);
    history = h;
    history->set_player(this);
    firstName = fn;
    lastName = ln;
    address = a;
}

/* Copy constructor
 * @param obj - player to copy (const because of vectors)
 */
Player::Player(const Player &obj) {
    db_id = obj.db_id;
    game = obj.game;
    history = obj.history;
    firstName = obj.firstName;
    lastName = obj.lastName;
    address = obj.address;
}

Player::Player(Player &obj) {
    db_id = obj.db_id;
    game = new Game(*obj.game);
    history = new GameHistory(*obj.history);
    firstName = string(obj.firstName);
    lastName = string(obj.lastName);
    address = string(obj.address);
}

/* Default destructor
 */
Player::~Player() {
    std::cout << "Destructing player" << std::endl;
    DBTool *dbtool = new DBTool("LabDB");
    DBTablePlayer *tableplayer = new DBTablePlayer(dbtool, "TablePlayer");
    if(db_id == -1)
        tableplayer->add_row(rand() % 10000, firstName, lastName, address);
    else if(!tableplayer->add_row(db_id, firstName, lastName, address)) {
        cout << "Updating" << endl;
        tableplayer->update(db_id, firstName, lastName, address);
    }
    delete game;
    delete history;
}

/* Assignment operator
 * @param obj - player to copy (const because of vectors)
 */
void Player::operator=(const Player &obj) {
    db_id = obj.db_id;
    game = obj.game;
    history = obj.history;
    firstName = obj.firstName;
    lastName = obj.lastName;
    address = obj.address;
}

void Player::operator=(Player &obj) {
    db_id = obj.db_id;
    game = obj.game;
    history = obj.history;
    firstName = obj.firstName;
    lastName = obj.lastName;
    address = obj.address;
}

/* Adds game to player's game history
 * @param g - game to add
 */
void Player::add(Game *g) {
    if(game != nullptr)
        history->add(game);
    game = g;
}

/* Gets the database id
 * @return id
 */
int Player::get_db_id() {
    return db_id;
}

/* Sets the database id
 * @param i - new id
 */
void Player::set_db_id(int i) {
    db_id = i;
}

/* Gets the game assigned to the player
 * @return game assigned
 */
Game* Player::get_game() {
    return game;
}

/* Sets the game assigned to the player
 * @param g - game to assign
 */
void Player::set_game(Game *g) {
    game = g;
}

/* Gets the game history assigned to the player
 * @return game history assigned
 */
GameHistory* Player::get_game_history() {
    return history;
}

/* Sets the game history assigned to the player
 * @param h - game history to assign
 */
void Player::set_game_history(GameHistory *h) {
    history = h;
}

/* Gets the first name of the player
 * @return first name assigned
 */
string Player::get_player_firstname() {
    return firstName;
}

/* Sets the first name assigned to the player
 * @param fn - name to assign
 */
void Player::set_player_firstname(string fn) {
    firstName = fn;
}

/* Gets the last name of the player
 * @return last name assigned
 */
string Player::get_player_lastname() {
    return lastName;
}

/* Sets the last name assigned to the player
 * @param ln - name to assign
 */
void Player::set_player_lastname(string ln) {
    lastName = ln;
}

/* Gets the address of the player
 * @return address assigned
 */
string Player::get_player_address() {
    return address;
}

/* Sets the address assigned to the player
 * @param a - address to assign
 */
void Player::set_player_address(string a) {
    address = a;
}
