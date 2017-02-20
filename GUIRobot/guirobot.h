#ifndef GUIROBOT_H
#define GUIROBOT_H

#include <QWidget>

namespace Ui {
class GUIRobot;
}

class GUIRobot : public QWidget
{
    Q_OBJECT

public:
    explicit GUIRobot(QWidget *parent = 0);
    ~GUIRobot();

private:
    Ui::GUIRobot *ui;
};

#endif // GUIROBOT_H
