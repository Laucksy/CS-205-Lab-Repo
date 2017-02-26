#include <iostream>
#include "gtest/gtest.h"
#include "../reference/game.h"
#include "../reference/gamehistory.h"
#include "../reference/player.h"
#include "../reference/playergamehistory.h"
using namespace std;

class GameTest : public ::testing::Test {
    protected:
        GameTest() {}
        virtual ~GameTest() {}
};

class PlayerTest : public ::testing::Test {
    protected:
        Player *player;
        Game *game;
        Game *game2;

        PlayerTest() {
            player = new Player();
            player->set_player_firstname("Erik");
            player->set_player_lastname("Laucks");
            game = new Game(player);
            game->set_score(12345);
            game->set_game_name("Test");
            game2 = new Game(player);
            game2->set_score(54321);
            game2->set_game_name("Test2");
        }
        virtual ~PlayerTest() {}
};

class GameHistoryTest : public ::testing::Test {
    protected:
        Player *player;
        Game *game;
        Game *game2;

        GameHistoryTest() {
            player = new Player();
            player->set_player_firstname("Erik");
            player->set_player_lastname("Laucks");
            game = new Game(player);
            game->set_score(12345);
            game->set_game_name("Test");
            game2 = new Game(player);
            game2->set_score(54321);
            game2->set_game_name("Test2");
        }
        virtual ~GameHistoryTest() {}
};

class PlayerHistoryTest : public ::testing::Test {
    protected:
        Player *player;
        Game *game;
        Game *game2;

        PlayerHistoryTest() {
            player = new Player();
            player->set_player_firstname("Erik");
            player->set_player_lastname("Laucks");
            game = new Game(player);
            game->set_score(12345);
            game->set_game_name("Test");
            game2 = new Game(player);
            game2->set_score(54321);
            game2->set_game_name("Test2");
        }
        virtual ~PlayerHistoryTest() {}
};

TEST_F(GameTest, TESTGAME) {
    Player *player = new Player();\
    player->set_player_firstname("Erik");
    player->set_player_lastname("Laucks");
    Game *game = new Game(player);
    ASSERT_TRUE(game->get_player()->get_player_firstname() == "Erik");
    ASSERT_TRUE(game->get_player()->get_player_lastname() == "Laucks");
}

TEST_F(PlayerTest, TESTPLAYERADD) {
    player->add(game);
    player->add(game2);
    ASSERT_TRUE(player->get_game_history()->get_game(0)->get_score()
                    == 12345);
    ASSERT_TRUE(player->get_game_history()->get_game(0)->get_game_name()
                    == "Test");
}

TEST_F(GameHistoryTest, TESTGAMEHISTORY) {
    Player *player = new Player();
    player->set_player_firstname("Erik");
    player->set_player_lastname("Laucks");
    GameHistory *history = new GameHistory(player);
    ASSERT_TRUE(history->get_player()->get_player_firstname() == "Erik");
    ASSERT_TRUE(history->get_player()->get_player_lastname() == "Laucks");
}

TEST_F(GameHistoryTest, TESTGAMEHISTORYADD) {
    GameHistory *history = new GameHistory(player);
    history->add(game);
    ASSERT_TRUE(history->get_game(0)->get_player()->get_player_firstname()
                    == "Erik");
    ASSERT_TRUE(history->get_game(0)->get_player()->get_player_lastname()
                    == "Laucks");
    ASSERT_TRUE(history->get_game(0)->get_score() == 12345);
    ASSERT_TRUE(history->get_game(0)->get_game_name() == "Test");
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYADDGAME) {
    PlayerGameHistory *history = new PlayerGameHistory();
    history->add_game(game);
    ASSERT_TRUE(history->get_game(0)->get_player()->get_player_firstname()
                    == "Erik");
    ASSERT_TRUE(history->get_game(0)->get_player()->get_player_lastname()
                    == "Laucks");
    ASSERT_TRUE(history->get_game(0)->get_score() == 12345);
    ASSERT_TRUE(history->get_game(0)->get_game_name() == "Test");
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYADDPLAYER) {
    PlayerGameHistory *history = new PlayerGameHistory();
    history->add_player(player);
    ASSERT_TRUE(history->get_player(0)->get_player_firstname() == "Erik");
    ASSERT_TRUE(history->get_player(0)->get_player_lastname() == "Laucks");
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYGAMESPLAYED) {
    PlayerGameHistory *history = new PlayerGameHistory();
    ASSERT_TRUE(history->games_played() == 0);
    history->add_game(game);
    ASSERT_TRUE(history->games_played() == 1);
    history->add_game(game2);
    ASSERT_TRUE(history->games_played() == 2);
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYNUMPLAYERS) {
    PlayerGameHistory *history = new PlayerGameHistory();
    ASSERT_TRUE(history->num_players() == 0);
    history->add_player(player);
    ASSERT_TRUE(history->num_players() == 1);
    history->add_player(player);
    ASSERT_TRUE(history->num_players() == 2);
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYAVGGAMESPERPLAYER) {
    PlayerGameHistory *history = new PlayerGameHistory();
    ASSERT_TRUE(history->avg_games_per_player() == 0);
    history->add_game(game);
    ASSERT_TRUE(history->avg_games_per_player() == 0);
    history->add_player(player);
    ASSERT_TRUE(history->avg_games_per_player() == 1);
    history->add_game(game);
    ASSERT_TRUE(history->avg_games_per_player() == 2);
    history->add_player(player);
    ASSERT_TRUE(history->avg_games_per_player() == 1);
    history->add_game(game);
    ASSERT_TRUE(history->avg_games_per_player() == 1.5);
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYTOPSCORE) {
    PlayerGameHistory *history = new PlayerGameHistory();
    ASSERT_TRUE(history->top_score() == 0);
    history->add_game(game);
    ASSERT_TRUE(history->top_score() == 12345);
    history->add_game(game);
    ASSERT_TRUE(history->top_score() == 12345);
    history->add_game(game2);
    ASSERT_TRUE(history->top_score() == 54321);
    history->add_game(game);
    ASSERT_TRUE(history->top_score() == 54321);
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYAVGGAMESCORE) {
    PlayerGameHistory *history = new PlayerGameHistory();
    game->set_score(10);
    game2->set_score(20);
    ASSERT_TRUE(history->avg_game_score() == 0);
    history->add_game(game);
    ASSERT_TRUE(history->avg_game_score() == 10);
    history->add_game(game);
    ASSERT_TRUE(history->avg_game_score() == 10);
    history->add_game(game);
    history->add_game(game2);
    ASSERT_TRUE(history->avg_game_score() == 12.5);
}

TEST_F(PlayerHistoryTest, TESTPLAYERHISTORYAVGSCOREFORPLAYER) {
    PlayerGameHistory *history = new PlayerGameHistory();
    history->add_player(player);
    game->set_score(10);
    game2->set_score(20);
    ASSERT_TRUE(history->avg_score_for_player(player) == 0);
    history->add_game(game);
    ASSERT_TRUE(history->avg_score_for_player(player) == 10);
    history->add_game(game2);
    ASSERT_TRUE(history->avg_score_for_player(player) == 15);
    history->add_game(game);
    history->add_game(game);
    ASSERT_TRUE(history->avg_score_for_player(player) == 12.5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
