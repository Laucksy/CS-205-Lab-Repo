#include "player.h"

//  Contains information about the player.
//  Object references the most recent game played.
//  Object references a GameHistory class that tracks all games played.
//  When Player Object plays a new game, the reference to current game is stored in GameHistory
//      and a reference is stored to the new game.
//  Stores the following information:
//      Player First Name.
//      Player Last Name.
//      Player Address.


Player::Player() {
    game = nullptr;
    history = new GameHistory(this);
    firstName = "";
    lastName = "";
    address = "";
}

Player::Player(Game *g, GameHistory *h) {
    game = g;
    game->set_player(this);
    history = h;
    history->set_player(this);
}

Player::Player(Game *g, GameHistory *h, string fn, string ln, string a) {
    game = g;
    game->set_player(this);
    history = h;
    history->set_player(this);
    firstName = fn;
    lastName = ln;
    address = a;
}

Player::Player(const Player &obj) {
    game = obj.game;
    history = obj.history;
    firstName = obj.firstName;
    lastName = obj.lastName;
    address = obj.address;
}

Player::~Player() {
    delete game;
    delete history;
}

void Player::operator=(const Player &obj) {
    game = obj.game;
    history = obj.history;
    firstName = obj.firstName;
    lastName = obj.lastName;
    address = obj.address;
}

void Player::add(Game *g) {
    if(game != nullptr)
        history->add(game);
    game = g;
}

Game* Player::get_game() {
    return game;
}

void Player::set_game(Game *g) {
    game = g;
}

GameHistory* Player::get_game_history() {
    return history;
}

void Player::set_game_history(GameHistory *h) {
    history = h;
}

string Player::get_player_firstname() {
    return firstName;
}

void Player::set_player_firstname(string fn) {
    firstName = fn;
}

string Player::get_player_lastname() {
    return lastName;
}

void Player::set_player_lastname(string ln) {
    lastName = ln;
}

string Player::get_player_address() {
    return address;
}

void Player::set_player_address(string a) {
    address = a;
}
