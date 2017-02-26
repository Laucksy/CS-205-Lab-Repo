#include "gamehistory.h"

//  Stores the games played for a specific player in game played order.
//  References each game played by the specific player.

GameHistory::GameHistory() {
    player = nullptr;
}

GameHistory::GameHistory(Player *p) {
    player = p;
    //player->set_game_history(this);
}

GameHistory::GameHistory(GameHistory &obj) {
    player = obj.player;
    for(unsigned i = 0; i < obj.games.size(); i++) {
        games.push_back(obj.games.at(i));
    }
}

GameHistory::~GameHistory() {
    delete player;
    games.clear();
    vector<Game*>().swap(games);
}

void GameHistory::operator=(GameHistory &obj) {
    player = obj.player;
    for(unsigned i = 0; i < obj.games.size(); i++) {
        games.push_back(obj.games.at(i));
    }
}

void GameHistory::add(Game *g) {
    g->set_player(get_player());
    games.push_back(g);
}

Player* GameHistory::get_player() {
    return player;
}

void GameHistory::set_player(Player *p) {
    player = p;
}

Game* GameHistory::get_game(int index) {
    return games[index];
}

int GameHistory::get_num_games() {
    return (int)games.size();
}
