#include "guiworm.h"
#include "ui_guiworm.h"

GUIWorm::GUIWorm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIWorm)
{
    ui->setupUi(this);
}

GUIWorm::~GUIWorm()
{
    delete ui;
}
