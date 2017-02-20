#ifndef GUIWORM_H
#define GUIWORM_H

#include <QWidget>

namespace Ui {
class GUIWorm;
}

class GUIWorm : public QWidget
{
    Q_OBJECT

public:
    explicit GUIWorm(QWidget *parent = 0);
    ~GUIWorm();

private:
    Ui::GUIWorm *ui;
};

#endif // GUIWORM_H
