#include "../include/welcome.h"
#include "ui_welcome.h"

#include <QMessageBox>
#include <QPixmap>

Welcome::Welcome(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Welcome) {
    pparent = parent;
    ui->setupUi(this);
    QPixmap pix("../logo.png");
    ui->label_pic->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
}


Welcome::~Welcome() {
    delete ui;
}

void Welcome::on_pushButton_Player_clicked() {
    hide();
    playerWindow = new PlayerWindow();
    playerWindow->setWindowTitle("Beer Game");
    playerWindow->show();
}

void Welcome::on_pushButton_Instructor_clicked() {
    hide();
    instrWindow = new InstrWindow();
    instrWindow->setWindowTitle("Beer Game");
    instrWindow->show();
}
