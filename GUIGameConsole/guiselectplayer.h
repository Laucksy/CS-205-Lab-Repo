#ifndef GUISELECTPLAYER_H
#define GUISELECTPLAYER_H

#include <QWidget>
#include "../reference/player.h"
#include "qpushbutton.h"
#include "qlabel.h"

namespace Ui {
class GUISelectPlayer;
}

class GUISelectPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit GUISelectPlayer(QWidget *parent = 0);
    ~GUISelectPlayer();

    void setPGH(PlayerGameHistory* p);
    void setPlayer(Player* p);
    void setLabel(QLabel* l);

private slots:
    void handleButton(Player* p);

private:
    Ui::GUISelectPlayer *ui;
    Player* player;
    QLabel* label;
};

#endif // GUISELECTPLAYER_H
