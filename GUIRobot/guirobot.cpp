#include "guirobot.h"
#include "ui_guirobot.h"

GUIRobot::GUIRobot(QWidget *parent) : QWidget(parent), ui(new Ui::GUIRobot)
{
    ui->setupUi(this);
    robot = *(new Robots(25,58));

    robot.init_board(robot.get_init_bots());

    redraw();
}

GUIRobot::~GUIRobot()
{
    delete ui;
}

void GUIRobot::redraw()
{
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

void GUIRobot::gameflow() {
    if(robot.won()) {
        robot.level();
        redraw();
    }
    if(robot.lost()) {
        redraw();
        /*int answer = 0;
        while(answer != 121 && answer != 110) {
            answer = getch();
        }
        if(answer == 121) {
            robot = *(new Robots(robot.getRows(), robot.getCols()));
            robot.init_board(robot.get_init_bots());
            draw_screen(robot, 0);
        } else {
            continue_looping = false;
        }*/
    }
}

void GUIRobot::on_waitToEndBtn_clicked()
{
    robot.turn('w');
    redraw();
    gameflow();
}

void GUIRobot::on_QuitBTN_clicked()
{
    robot.turn('q');
    redraw();
    gameflow();
}

void GUIRobot::on_teleportBTn_clicked()
{
    robot.turn('t');
    redraw();
    gameflow();
}

void GUIRobot::on_leftDownBtn_clicked()
{
    robot.turn('b');
    redraw();
    gameflow();
}

void GUIRobot::on_downBtn_clicked()
{
    robot.turn('j');
    redraw();
    gameflow();
}

void GUIRobot::on_rightDownBtn_clicked()
{
    robot.turn('n');
    redraw();
    gameflow();
}

void GUIRobot::on_rightBTn_clicked()
{
    robot.turn('l');
    redraw();
    gameflow();
}

void GUIRobot::on_LeftBtn_clicked()
{
    robot.turn('h');
    redraw();
    gameflow();
}

void GUIRobot::on_leftUpBtn_clicked()
{
    robot.turn('y');
    redraw();
    gameflow();
}

void GUIRobot::on_pushButton_3_clicked() {

}

void GUIRobot::on_rightUpBtn_clicked()
{
    robot.turn('u');
    redraw();
    gameflow();
}

void GUIRobot::on_upBtn_clicked()
{
    robot.turn('k');
    redraw();
    gameflow();
}
