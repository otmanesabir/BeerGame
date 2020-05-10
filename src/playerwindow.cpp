#include "../include/playerwindow.h"
#include "ui_playerwindow.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QIntValidator>
#include <QRegExpValidator>

#include <string>

using namespace std;

#include "../include/Player.h"


PlayerWindow::PlayerWindow(QWidget *parent) : QWidget(parent),
                                              ui(new Ui::PlayerWindow) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->textEdit_showRole_player->setReadOnly(true);
    ui->lineEdit_numWeeks_player->setReadOnly(true);
    ui->lineEdit_startInventory_player->setReadOnly(true);
    ui->lineEdit_backorderCost_player->setReadOnly(true);
    ui->lineEdit_holdingCost_player->setReadOnly(true);
    ui->lineEdit_shipmentDelay_player->setReadOnly(true);
    ui->lineEdit_orderDelay_player->setReadOnly(true);

    ui->lineEdit_currWeek_player->setReadOnly(true);
    ui->lineEdit_inventory_player->setReadOnly(true);
    ui->lineEdit_backlogs_player->setReadOnly(true);
    ui->lineEdit_cumulativeCost_player->setReadOnly(true);
    ui->lineEdit_incomeOrder_player->setReadOnly(true);
    ui->lineEdit_incomeDelivery_player->setReadOnly(true);

}

PlayerWindow::~PlayerWindow() {
    delete ui;
}

void PlayerWindow::on_pushButton_retailer_clicked() {
    QString password = ui->lineEdit_password_player->text();
    if (password == NULL) {
        QMessageBox::warning(this, "Need Password", "You need to type in the password which "
                                                    "you received from your instructor"
                                                    "to continue the game.");
    } else {
        ui->stackedWidget->setCurrentIndex(1);
        ui->textEdit_showRole_player->setText("Retailer");
    }
}

void PlayerWindow::on_pushButton_wholesaler_clicked() {
    QString password = ui->lineEdit_password_player->text();
    if (password == NULL) {
        QMessageBox::warning(this, "Need Password", "You need to type in the password which "
                                                    "you received from your instructor"
                                                    "to continue the game.");
    } else {
        ui->stackedWidget->setCurrentIndex(1);
        ui->textEdit_showRole_player->setText("Wholesaler");
    }
}

void PlayerWindow::on_pushButton_distributor_clicked() {
    QString password = ui->lineEdit_password_player->text();
    if (password == NULL) {
        QMessageBox::warning(this, "Need Password", "You need to type in the password which "
                                                    "you received from your instructor"
                                                    "to continue the game.");
    } else {
        ui->stackedWidget->setCurrentIndex(1);
        ui->textEdit_showRole_player->setText("Distributor");
    }
}

void PlayerWindow::on_pushButton_factory_clicked() {
    QString password = ui->lineEdit_password_player->text();
    if (password == NULL) {
        QMessageBox::warning(this, "Need Password", "You need to type in the password which "
                                                    "you received from your instructor"
                                                    "to continue the game.");
    } else {
        ui->stackedWidget->setCurrentIndex(1);
        ui->textEdit_showRole_player->setText("Factory");
    }
}

void PlayerWindow::on_pushButton_playNow_player_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void PlayerWindow::on_pushButton_placeOrder_player_clicked() {
    QString placeOrder_player = ui->lineEdit_placeOrder_player->text();
    QRegularExpression reg_int("^[1-9]\\d*$");
    if (!reg_int.match(placeOrder_player).hasMatch()) {
        QMessageBox::warning(this, "Invalid Order Input", "Please type in a valid order input.");
    } else {
        QMessageBox::information(this, "Playing as Player", "Order placed!");
        close();
    }
}
