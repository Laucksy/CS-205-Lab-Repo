#ifndef GUITOPTHREE_H
#define GUITOPTHREE_H

#include <QWidget>
#include "../reference/playergamehistory.h"
#include "vector"

namespace Ui {
class GUITopThree;
}

class GUITopThree : public QWidget
{
    Q_OBJECT

public:
    explicit GUITopThree(QWidget *parent = 0);
    ~GUITopThree();

    void setPGH(PlayerGameHistory* p);
    void setType(bool t);
    void setup_players();
    void setup_games();

private:
    Ui::GUITopThree *ui;
    PlayerGameHistory* pgh;
    bool type;
};

#endif // GUITOPTHREE_H
