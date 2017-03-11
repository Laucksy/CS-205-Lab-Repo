#ifndef GUINEWPLAYER_H
#define GUINEWPLAYER_H

#include <QWidget>
#include "../reference/player.h"

namespace Ui {
class GUINewPlayer;
}

class GUINewPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit GUINewPlayer(QWidget *parent = 0);
    ~GUINewPlayer();

    void setPGH(PlayerGameHistory* p);
    void setPlayer(Player* p);

private slots:
    void on_createPlayerButton_clicked();

private:
    Ui::GUINewPlayer *ui;
    PlayerGameHistory* pgh;
    Player* player;
};

#endif // GUINEWPLAYER_H
