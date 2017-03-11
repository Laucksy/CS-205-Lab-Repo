#include "guitopthree.h"
#include "ui_guitopthree.h"

GUITopThree::GUITopThree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUITopThree)
{
    ui->setupUi(this);
}

GUITopThree::~GUITopThree()
{
    delete ui;
}

void GUITopThree::setPGH(PlayerGameHistory *p) {
    //cout << pgh->num_players() << endl;
    pgh = p;
    if(type)
        setup_players();
    else
        setup_games();
}

void GUITopThree::setType(bool t) {
    type = t;
}

void GUITopThree::setup_players() {
    Player* firstp = nullptr;
    Player* secondp = nullptr;
    Player* thirdp = nullptr;
    int index1 = -1;
    int index2 = -1;

    int max = -1;
    int index = -1;
    for(int i = 0; i < pgh->num_players(); i++) {
        if(pgh->avg_score_for_player(pgh->get_player(i)) > max) {
            max = pgh->avg_score_for_player(pgh->get_player(i));
            index = i;
            index1 = i;
        }
    }
    if(index != -1) {
        firstp = pgh->get_player(index);

        max = -1;
        index = -1;
        for(int i = 0; i < pgh->num_players(); i++) {
            if(i != index1 && pgh->avg_score_for_player(pgh->get_player(i)) > max) {
                max = pgh->avg_score_for_player(pgh->get_player(i));
                index = i;
                index2 = i;
            }
        }
        if(index != -1) {
            secondp = pgh->get_player(index);

            max = -1;
            index = -1;
            for(int i = 0; i < pgh->num_players(); i++) {
                if(i != index1 && i != index2 && pgh->avg_score_for_player(pgh->get_player(i)) > max) {
                    max = pgh->avg_score_for_player(pgh->get_player(i));
                    index = i;
                }
            }
            if(index != -1)
                thirdp = pgh->get_player(index);
        }
    }

    ui->titleLabel->setText(*(new QString(string("Top 3 Players").c_str())));
    if(firstp != nullptr) {
        string name = firstp->get_player_firstname() + " " + firstp->get_player_lastname();
        ui->oneLabel->setText(*(new QString(name.c_str())));
    } else
        ui->oneLabel->setText(*(new QString(string("N/A").c_str())));
    if(secondp != nullptr) {
        string name = secondp->get_player_firstname() + " " + secondp->get_player_lastname();
        ui->twoLabel->setText(*(new QString(name.c_str())));
    } else
        ui->twoLabel->setText(*(new QString(string("N/A").c_str())));
    if(thirdp != nullptr) {
        string name = thirdp->get_player_firstname() + " " + thirdp->get_player_lastname();
        ui->threeLabel->setText(*(new QString(name.c_str())));
    } else
        ui->threeLabel->setText(*(new QString(string("N/A").c_str())));
}

void GUITopThree::setup_games() {
    Game* firstg = nullptr;
    Game* secondg = nullptr;
    Game* thirdg = nullptr;
    int index1 = -1;
    int index2 = -1;

    int max = -1;
    int index = -1;
    for(int i = 0; i < pgh->games_played(); i++) {
        if(pgh->get_game(i)->get_score() > max) {
            max = pgh->get_game(i)->get_score();
            index = i;
            index1 = i;
        }
    }
    if(index != -1) {
        firstg = pgh->get_game(index);

        max = -1;
        index = -1;
        for(int i = 0; i < pgh->games_played(); i++) {
            if(i != index1 && pgh->get_game(i)->get_score() > max) {
                max = pgh->get_game(i)->get_score();
                index = i;
                index2 = i;
            }
        }
        if(index != -1) {
            secondg = pgh->get_game(index);

            max = -1;
            index = -1;
            for(int i = 0; i < pgh->games_played(); i++) {
                if(i != index1 && i != index2 && pgh->get_game(i)->get_score() > max) {
                    max = pgh->get_game(i)->get_score();
                    index = i;
                }
            }
            if(index != -1)
                thirdg = pgh->get_game(index);
        }
    }

    ui->titleLabel->setText(*(new QString(string("Top 3 Games").c_str())));
    if(firstg != nullptr) {
        string name = firstg->get_game_name() + " : " + to_string(firstg->get_score());
        ui->oneLabel->setText(*(new QString(name.c_str())));
    } else
        ui->oneLabel->setText(*(new QString(string("N/A").c_str())));
    if(secondg != nullptr) {
        string name = secondg->get_game_name() + " : " + to_string(secondg->get_score());
        ui->twoLabel->setText(*(new QString(name.c_str())));
    } else
        ui->twoLabel->setText(*(new QString(string("N/A").c_str())));
    if(thirdg != nullptr) {
        string name = thirdg->get_game_name() + " : " + to_string(thirdg->get_score());
        ui->threeLabel->setText(*(new QString(name.c_str())));
    } else
        ui->threeLabel->setText(*(new QString(string("N/A").c_str())));
}
