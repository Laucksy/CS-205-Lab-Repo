#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pgh = new PlayerGameHistory();
    //robot = *(new Robots(25,58));
    //robot.init_board(robot.get_init_bots());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_Program_triggered()
{
    exit(0);
}

void MainWindow::on_actionTop_3_Players_triggered()
{

}

void MainWindow::on_actionTop_3_Games_triggered()
{

}

void MainWindow::on_actionCalculated_Statistics_triggered()
{

}

void MainWindow::on_actionNew_Player_triggered()
{

}

void MainWindow::on_actionSelect_Existing_Player_triggered()
{
    //ui->playerLabel->setText();
}

void MainWindow::on_wormButton_clicked()
{
    GUIWorm* guiworm = new GUIWorm();
    guiworm->show();
}

void MainWindow::on_robotButton_clicked()
{
    GUIRobot* guirobot = new GUIRobot();
    guirobot->show();
}
