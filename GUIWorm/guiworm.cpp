#include "guiworm.h"
#include "ui_guiworm.h"

GUIWorm::GUIWorm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIWorm)
{
    ui->setupUi(this);
    Worm worm(20,77);
    worm.init();
}

GUIWorm::~GUIWorm()
{
    delete ui;
}

void GUIWorm::on_dBtn_clicked()
{
    worm.move(2,1);
}

void GUIWorm::on_rBtn_clicked()
{
    worm.move(1,1);
}

void GUIWorm::on_lBtn_clicked()
{
    worm.move(3,1);
}

void GUIWorm::on_uBtn_clicked()
{
    worm.move(0,1);
}
