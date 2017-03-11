#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../reference/playergamehistory.h"
#include "../GUIRobot/guirobot.h"
#include "../GUIWorm/guiworm.h"
#include "../engines/robots.h"
#include "../engines/worm.h"
#include "guiselectplayer.h"
#include "guistatistics.h"
#include "guinewplayer.h"
#include "guitopthree.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    PlayerGameHistory* pgh;
    Player* curPlayer;
    //Robots* robot;
private slots:
    void on_actionExit_Program_triggered();

    void on_actionTop_3_Players_triggered();

    void on_actionTop_3_Games_triggered();

    void on_actionCalculated_Statistics_triggered();

    void on_actionNew_Player_triggered();

    void on_actionSelect_Existing_Player_triggered();

    void on_wormButton_clicked();

    void on_robotButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
