#include "guistatistics.h"
#include "ui_guistatistics.h"

GUIStatistics::GUIStatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIStatistics)
{
    ui->setupUi(this);
}

GUIStatistics::~GUIStatistics()
{
    delete ui;
}

/* Set player game history so the game and player info
 * can be calculated and displayed
 * @param pgh - player game history to read from
 */
void GUIStatistics::setPGH(PlayerGameHistory *p) {
    pgh = p; //Following code updates the labels for all the stats
    string text = to_string(pgh->games_played());
    ui->gamesPlayedLabel->setText(*(new QString(text.c_str())));
    text = to_string(pgh->num_players());
    ui->playersLabel->setText(*(new QString(text.c_str())));
    text = to_string(pgh->avg_games_per_player());
    ui->avgGamesLabel->setText(*(new QString(text.c_str())));
    text = to_string(pgh->top_score());
    ui->topScoreLabel->setText(*(new QString(text.c_str())));
    text = to_string(pgh->avg_game_score());
    ui->avgScoreLabel->setText(*(new QString(text.c_str())));
    text = to_string(pgh->avg_score_for_player(player));
    ui->playerScoreLabel->setText(*(new QString(text.c_str())));
}

void GUIStatistics::setPlayer(Player *p) {
    player = p;
    if(player != nullptr) { //Updates last label specific to palyer
        string name = "Average score for " + player->get_player_firstname() +
                " " + player->get_player_lastname() + ":";
        ui->changeTextLabel->setText(*(new QString(name.c_str())));
    }
}
