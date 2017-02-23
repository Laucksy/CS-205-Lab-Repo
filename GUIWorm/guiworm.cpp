#include "guiworm.h"
#include "ui_guiworm.h"

GUIWorm::GUIWorm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIWorm)
{
    ui->setupUi(this);
    worm = *(new Worm(20,77));
    worm.init();
    // create an empty string
    QString temp_board = "";

    // create a single string from the array that stores the gameboard
    for(int row = 0; row < worm.rows; row++) {
        for(int col = 0; col < worm.cols; col++) {
            temp_board += worm.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

GUIWorm::~GUIWorm()
{
    delete ui;
}

void GUIWorm::on_dBtn_clicked()
{
    worm.move(2,1);

    // create an empty string
    QString temp_board = "";

    // create a single string from the array that stores the gameboard
    for(int row = 0; row < worm.rows; row++) {
        for(int col = 0; col < worm.cols; col++) {
            temp_board += worm.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIWorm::on_rBtn_clicked()
{
    worm.move(1,1);

    // create an empty string
    QString temp_board = "";

    // create a single string from the array that stores the gameboard
    for(int row = 0; row < worm.rows; row++) {
        for(int col = 0; col < worm.cols; col++) {
            temp_board += worm.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIWorm::on_lBtn_clicked()
{
    worm.move(3,1);

    // create an empty string
    QString temp_board = "";

    // create a single string from the array that stores the gameboard
    for(int row = 0; row < worm.rows; row++) {
        for(int col = 0; col < worm.cols; col++) {
            temp_board += worm.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIWorm::on_uBtn_clicked()
{
    worm.move(0,1);

    // create an empty string
    QString temp_board = "";

    // create a single string from the array that stores the gameboard
    for(int row = 0; row < worm.rows; row++) {
        for(int col = 0; col < worm.cols; col++) {
            temp_board += worm.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}
