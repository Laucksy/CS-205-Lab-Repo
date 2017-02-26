#include "game.h"

//  Contains information about the game that was played.
//  References the player that played it.
//  Stores the following information:
//      Name of game.
//      Final score.

Game::Game() {
    player = nullptr;
    name = "";
    score = 0;
}

Game::Game(Player *p) {
    player = p;
    name = "";
    score = 0;
    player->add(this);
}

Game::Game(Player *p, string n, int s) {
    player = p;
    player->add(this);
    name = n;
    score = s;
}

Game::Game(const Game &obj) {
    player = obj.player;
    name = obj.name;
    score = obj.score;
}

Game::~Game() {
    delete player;
}

void Game::operator=(const Game &obj) {
    player = obj.player;
    name = obj.name;
    score = obj.score;
}

Player* Game::get_player() {
    return player;
}

void Game::set_player(Player *p) {
    player = p;
    //player->set_game_history(new GameHistory(player));
}

string Game::get_game_name() {
    return name;
}

void Game::set_game_name(string n) {
    name = n;
}

int Game::get_score() {
    return score;
}

void Game::set_score(int s) {
    score = s;
}
