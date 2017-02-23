#include "guirobot.h"
#include "ui_guirobot.h"

GUIRobot::GUIRobot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUIRobot)
{
    ui->setupUi(this);
    robot = *(new Robots(12,70));

    robot.init_board(robot.get_init_bots());

    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

GUIRobot::~GUIRobot()
{
    delete ui;
}

void GUIRobot::on_waitToEndBtn_clicked()
{

    robot.turn('w');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_QuitBTN_clicked()
{
    robot.turn('q');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_teleportBTn_clicked()
{
    robot.turn('t');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_leftDownBtn_clicked()
{
    robot.turn('b');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_downBtn_clicked()
{
    robot.turn('j');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_rightDownBtn_clicked()
{
    robot.turn('n');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_rightBTn_clicked()
{
    robot.turn('l');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_LeftBtn_clicked()
{
    robot.turn('h');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_leftUpBtn_clicked()
{
    robot.turn('y');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_rightUpBtn_clicked()
{
    robot.turn('u');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}

void GUIRobot::on_upBtn_clicked()
{
    robot.turn('k');
    // create an empty string
    QString temp_board = "";
    // create a single string from the array that stores the gameboard
    for(int row = 0; row < robot.rows; row++) {
        for(int col = 0; col < robot.cols; col++) {
            temp_board += robot.get(row,col);
        }
        temp_board += '\n';
    }
    // clear the board
    ui->board_display->clear();
    // load the QString into the label
    ui->board_display->setText(temp_board);
}
