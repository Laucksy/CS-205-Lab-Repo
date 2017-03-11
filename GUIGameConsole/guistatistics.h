#ifndef GUISTATISTICS_H
#define GUISTATISTICS_H

#include <QWidget>
#include "../reference/player.h"

namespace Ui {
class GUIStatistics;
}

class GUIStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit GUIStatistics(QWidget *parent = 0);
    ~GUIStatistics();

    void setPGH(PlayerGameHistory* p);
    void setPlayer(Player* p);

private:
    Ui::GUIStatistics *ui;
    PlayerGameHistory* pgh;
    Player* player;
};

#endif // GUISTATISTICS_H
