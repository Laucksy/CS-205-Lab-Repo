#ifndef GUIROBOT_H
#define GUIROBOT_H

#include <QWidget>
#include "../engines/robots.h"

namespace Ui {
class GUIRobot;
}

class GUIRobot : public QWidget
{
    Q_OBJECT

public:
    explicit GUIRobot(QWidget *parent = 0);
    ~GUIRobot();

    Robots robot;
protected:
    void redraw();
    void gameflow();
private slots:
    void on_waitToEndBtn_clicked();

    void on_QuitBTN_clicked();

    void on_teleportBTn_clicked();

    void on_leftDownBtn_clicked();

    void on_downBtn_clicked();

    void on_rightDownBtn_clicked();

    void on_rightBTn_clicked();

    void on_LeftBtn_clicked();

    void on_leftUpBtn_clicked();

    void on_pushButton_3_clicked();

    void on_rightUpBtn_clicked();

    void on_upBtn_clicked();

    void on_restart_clicked();

private:
    Ui::GUIRobot *ui;
};

#endif // GUIROBOT_H
