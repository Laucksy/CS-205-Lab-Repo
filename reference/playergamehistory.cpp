#include "playergamehistory.h"

/*
//    Object tracks each player that has played a game in the system.
//    Each stored pointer references a unique player.
//    Object tracks each game that has been played in the system.
//    Games are stored in order that they are played.
//    Methods will be provided for calculating the following statistics
//          dynamically, this is to say, these statistics are not
//          stored but calculated as needed.
//        Number of games played.
//        Number of players that have played games.
//        Average games played per player.
//        Top game score.
//        Average game score for all games.
//        What was the average score for a specific player.
//    Methods will be provided for adding players playing a specific game
//          and a final score as an integer value.
*/

/* Default constructor
 */
PlayerGameHistory::PlayerGameHistory() {
    dbtool = new DBTool("LabDB");
    tablegame = new DBTableGame(dbtool, "TableGame");
    tablegame->set_pgh(this);
    tablegame->select_all();
    tableplayer = new DBTablePlayer(dbtool, "TablePlayer");
    tableplayer->set_pgh(this);
    tableplayer->select_all();
    for(unsigned i = 0; i < games.size(); i++) {
        for(unsigned j = 0; j < players.size(); j++) {
            if(games.at(i)->get_p_id() == players.at(j)->get_db_id()) {
                games.at(i)->set_player(players.at(j));
                players.at(j)->add(games.at(i));
            }
        }
    }
}

/* Copy constructor
 * @param obj - object to copy
 */
PlayerGameHistory::PlayerGameHistory(PlayerGameHistory &obj) {
    for(unsigned i = 0; i < obj.players.size(); i++) {
        players.push_back(obj.players.at(i));
    }
    for(unsigned i = 0; i < obj.games.size(); i++) {
        games.push_back(obj.games.at(i));
    }
}

/* Default destructor
 */
PlayerGameHistory::~PlayerGameHistory() {
    for(unsigned i = 0; i < players.size(); i++) {
        delete players.at(i);
    }
    players.clear();
    vector<Player*>().swap(players);
    for(unsigned i = 0; i < games.size(); i++) {
        delete games.at(i);
    }
    games.clear();
    vector<Game*>().swap(games);
}

/* Assignment operator
 * @param obj - object to copy
 */
void PlayerGameHistory::operator=(PlayerGameHistory &obj) {
    for(unsigned i = 0; i < obj.players.size(); i++) {
        players.push_back(obj.players.at(i));
    }
    for(unsigned i = 0; i < obj.games.size(); i++) {
        games.push_back(obj.games.at(i));
    }
}

/* Takes the data from the game select all callback and
 * constructs all of the game objects
 * @param size - number of columns
 * @param data - data from table
 * @param colNames - columns from table
 */
void PlayerGameHistory::construct_game(int size, char **data,
                                       char **colNames) {
    for(int i = 0; i < size; i++) {
        //cout << colNames[i] << " = " << (data[i] ? std::string(data[i])
            //: "NULL") << endl;
    }
    int id = atoi(data[0]);
    int player = atoi(data[1]);
    string name = string(data[2]);
    int score = atoi(data[3]);
    Game *g = new Game();
    g->set_db_id(id);
    g->set_p_id(player);
    g->set_game_name(name);
    g->set_score(score);
    games.push_back(g);
}

/* Takes the data from the player select all callback and
 * constructs all of the player objects
 * @param size - number of columns
 * @param data - data from table
 * @param colNames - columns from table
 */
void PlayerGameHistory::construct_player(int size, char **data,
                                         char **colNames) {
    for(int i = 0; i < size; i++) {
        //cout << colNames[i] << " = " << (data[i] ? std::string(data[i]
            //: "NULL") << endl;
    }
    int id = atoi(data[0]);
    string fName = string(data[1]);
    string lName = string(data[2]);
    string address = string(data[3]);
    Player *p = new Player();
    p->set_db_id(id);
    p->set_player_firstname(fName);
    p->set_player_lastname(lName);
    p->set_player_address(address);
    players.push_back(p);
}

/* Adds player to the player history
 * @param p - player to add
 */
void PlayerGameHistory::add_player(Player *p) {
    players.push_back(p);
}

/* Adds game to the game history
 * @param g - game to add
 */
void PlayerGameHistory::add_game(Game *g) {
    games.push_back(g);
}

/* Gets the player from the history
 * @param index - index to get from
 * @return player at the given index
 */
Player* PlayerGameHistory::get_player(int index) {
    return players[index];
}

/* Gets the game from the history
 * @param index - index to get from
 * @return game at the given index
 */
Game* PlayerGameHistory::get_game(int index) {
    return games[index];
}

/* Gets the number of games player
 * @return number of games
 */
int PlayerGameHistory::games_played() {
    return (int)games.size();
}

/* Gets the number of players in the history
 * @return number of players
 */
int PlayerGameHistory::num_players() {
    return (int)players.size();
}

/* Calculates the averages number of games per player
 * @return average games
 */
float PlayerGameHistory::avg_games_per_player() {
    if(num_players() != 0)
        return 1.0 * games_played() / num_players();
    else
        return 0;
}

/* Finds the top score of all the games
 * @return highest score
 */
int PlayerGameHistory::top_score() {
    int max = 0;
    for(unsigned i = 0; i < games.size(); i++) {
        if(games.at(i)->get_score() > max)
            max = games.at(i)->get_score();
    }
    return max;
}

/* Calculates the average score of all games
 * @return average score
 */
float PlayerGameHistory::avg_game_score() {
    int total = 0;
    for(unsigned i = 0; i < games.size(); i++) {
            total += games.at(i)->get_score();
    }
    if(games_played() != 0)
        return 1.0 * total / games_played();
    else
        return 0;
}

/* Calculates the average score for a given player
 * @return player's average score
 */
float PlayerGameHistory::avg_score_for_player(Player *p) {
    /*GameHistory *history = p->get_game_history();
    int total = 0;
    for(int i = 0; i < history->get_num_games(); i++) {
        total += history->get_game(i)->get_score();
    }
    if(history->get_num_games() != 0)
        return 1.0 * total / history->get_num_games();
    else
        return 0;*/

    int total = 0;
    for(int i = 0; i < games_played(); i++) {
        if(get_game(i)->get_player()->get_db_id() == p->get_db_id())
            total += get_game(i)->get_score();
    }

    if(games_played() != 0)
        return 1.0 * total / games_played();
    else
        return 0;
}
