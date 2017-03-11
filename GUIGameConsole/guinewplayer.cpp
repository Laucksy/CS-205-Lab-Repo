#include "guinewplayer.h"
#include "ui_guinewplayer.h"

GUINewPlayer::GUINewPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUINewPlayer)
{
    ui->setupUi(this);
}

GUINewPlayer::~GUINewPlayer()
{
    delete ui;
}

void GUINewPlayer::setPGH(PlayerGameHistory* p) {
    pgh = p;
}

void GUINewPlayer::setPlayer(Player *p) {
    player = p;
}

void GUINewPlayer::on_createPlayerButton_clicked()
{
    player = new Player(); //Creates new player and assigns it values
    string firstname = ui->firstNameInput->text().toStdString();
    string lastname = ui->lastNameInput->text().toStdString();
    string address = ui->addressInput->text().toStdString();
    player->set_player_firstname(firstname);
    player->set_player_lastname(lastname);
    player->set_player_address(address);
    pgh->add_player(player); //Adds to history
    //delete player;
    this->close();
}
