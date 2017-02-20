#include "guirobot.h"
#include "ui_guirobot.h"

GUIRobot::GUIRobot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIRobot)
{
    ui->setupUi(this);
}

GUIRobot::~GUIRobot()
{
    delete ui;
}
