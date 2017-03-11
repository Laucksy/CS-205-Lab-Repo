#include "guiselectplayer.h"
#include "ui_guiselectplayer.h"

GUISelectPlayer::GUISelectPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUISelectPlayer)
{
    ui->setupUi(this);
}

GUISelectPlayer::~GUISelectPlayer()
{
    delete ui;
}

/* Set player game history so the players can be retreived
 * and displayed to the screen, allowing the user to pick their player
 * @param pgh - player game history to read from
 */
void GUISelectPlayer::setPGH(PlayerGameHistory *pgh) {
    for(int i = 0; i < pgh->num_players(); i++) {
        QLabel* newLabel = new QLabel(); //Create label for player name
        string name = pgh->get_player(i)->get_player_firstname() +
                " " + pgh->get_player(i)->get_player_lastname();
        newLabel->setText(*(new QString(name.c_str())));
        ui->playerLayout->addWidget(newLabel); //Add label to layout

        QPushButton* button = new QPushButton(); //Create button to choose
        button->setText("Select Player");
        connect(button, &QPushButton::clicked, [this, i, pgh]{
            this->handleButton(pgh->get_player(i));
        }); //Catches click event and handles accordingly
        ui->buttonLayout->addWidget(button); //Add button to layout
    }
}

void GUISelectPlayer::setPlayer(Player* p) {
    player = p;
}

void GUISelectPlayer::setLabel(QLabel *l) {
    label = l;
}

void GUISelectPlayer::handleButton(Player* p) {
    if(player == nullptr)
        player = p;
    else //Set the dereference values equal so this
        //Changes the player in the main window
        *player = *p;
    string name = "Player: " + player->get_player_firstname() +
            " " + player->get_player_lastname();
    label->setText(*(new QString(name.c_str()))); //Update main window text
    this->close();
}
