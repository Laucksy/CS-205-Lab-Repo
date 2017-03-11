#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pgh = new PlayerGameHistory();
    curPlayer = new Player();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pgh;
}

void MainWindow::on_actionExit_Program_triggered()
{
    this->~MainWindow();
    exit(0);
}

void MainWindow::on_actionTop_3_Players_triggered()
{
    //Create gui, pass in player game history and type, then display
    GUITopThree* guitt = new GUITopThree();
    guitt->setType(true);
    guitt->setPGH(pgh);
    guitt->show();
}

void MainWindow::on_actionTop_3_Games_triggered()
{
    //Create gui, pass in player game history and type, then display
    GUITopThree* guitt = new GUITopThree();
    guitt->setType(false);
    guitt->setPGH(pgh);
    guitt->show();
}

void MainWindow::on_actionCalculated_Statistics_triggered()
{
    //Create gui, pass in player game history and player, then display
    GUIStatistics* guist = new GUIStatistics();
    guist->setPlayer(curPlayer);
    guist->setPGH(pgh);
    guist->show();
}

void MainWindow::on_actionNew_Player_triggered()
{
    //Create gui, pass in player game history and player, then display
    GUINewPlayer* guinp = new GUINewPlayer();
    guinp->setPGH(pgh);
    guinp->setPlayer(curPlayer);
    guinp->show();
}

void MainWindow::on_actionSelect_Existing_Player_triggered()
{
    //Create gui, pass in player game history, player, and label, then display
    GUISelectPlayer* guisp = new GUISelectPlayer();
    guisp->setPGH(pgh);
    guisp->setPlayer(curPlayer);
    guisp->setLabel(ui->playerLabel);
    guisp->show();
}

void MainWindow::on_wormButton_clicked()
{
    //Create gui for worm game and display
    GUIWorm* guiworm = new GUIWorm();
    guiworm->show();
}

void MainWindow::on_robotButton_clicked()
{
    //Create gui for robots, set player game history and player, then display
    GUIRobot* guirobot = new GUIRobot();
    guirobot->setPGH(pgh);
    guirobot->setPlayer(curPlayer);
    guirobot->show();
}
