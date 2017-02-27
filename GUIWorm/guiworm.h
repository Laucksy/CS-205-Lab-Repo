#ifndef GUIWORM_H
#define GUIWORM_H

#include <QWidget>
#include "../engines/worm.h"

namespace Ui {
class GUIWorm;
}

class GUIWorm : public QWidget
{
    Q_OBJECT

public:
    explicit GUIWorm(QWidget *parent = 0);
    ~GUIWorm();
    Worm worm;

private slots:
    void on_dBtn_clicked();

    void on_rBtn_clicked();

    void on_lBtn_clicked();

    void on_uBtn_clicked();

    void reDraw();


    void on_restart_clicked();

private:
    Ui::GUIWorm *ui;
};

#endif // GUIWORM_H
