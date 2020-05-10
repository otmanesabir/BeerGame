#include "../include/instrwindow.h"
#include "ui_instrwindow.h"
#include "Instructor.h"
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <QRegExpValidator>
#include <QRegExp>
#include <QDoubleValidator>

InstrWindow::InstrWindow(QWidget *parent) : QWidget(parent),
                                            ui(new Ui::InstrWindow) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

InstrWindow::~InstrWindow() {
    delete ui;
}

void InstrWindow::on_pushButton_login_clicked() {
    QString Email = ui->lineEdit_Email->text();
    QString Password = ui->lineEdit_Password->text();

    // handle null inputs
    if (Email == NULL || Password == NULL) {
        QMessageBox::warning(this, "Login", "You need to fill all text fields");
    } else {
        // validate email by using regular expression
        QRegularExpression re_email(
                "^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
        if (!re_email.match(Email).hasMatch()) {
            QMessageBox::warning(this, "Invalid Email", "Please type in a valid email");
        } else {
            instr = new Instructor();
            instr->setInstrId(20);
            instr->setInstrEmail(Email.toStdString());
            instr->setInstrPassword(Password.toStdString());
            QMessageBox::StandardButton modify_params = QMessageBox::question(this,
                                                                              "Modify Parameters?",
                                                                              "Do you want to modify parameters of the game?",
                                                                              QMessageBox::Yes | QMessageBox::No);

            if (modify_params == QMessageBox::Yes) {
                ui->stackedWidget->setCurrentIndex(2);
            } else if (modify_params == QMessageBox::No) {
                QMessageBox::information(this, "Continue",
                                         "Okay! We will continue the game with default parameters. Stay tuned!");
                QApplication::quit();
            }
        }
    }
}

void InstrWindow::on_pushButton_instrSignupFromLogin_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void InstrWindow::on_pushButton_instrSignup_clicked() {
    QString Institution = ui->lineEdit_Institution->text();
    QString Email = ui->lineEdit_Email_2->text();
    QString Password = ui->lineEdit_Password_2->text();
    QString RepeatPwd = ui->lineEdit_RepeatPassword->text();

    if (Institution == NULL || Email == NULL || Password == NULL || RepeatPwd == NULL) {
        QMessageBox::warning(this, "Login", "You need to fill all text fields");
    } else {
        QRegularExpression re_email(
                "^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
        if (!re_email.match(Email).hasMatch()) {
            QMessageBox::warning(this, "Invalid Email", "Please type in a valid email");
        } else {
            instr = new Instructor();
            instr->setInstrId(20);
            instr->setInstrEmail(Email.toStdString());
            instr->setInstrPassword(Password.toStdString());
            QMessageBox::information(this, "Success!",
                                     "You have successfully created an account as the instructor!");
            QMessageBox::StandardButton modify_params = QMessageBox::question(this,
                                                                              "Modify Parameters?",
                                                                              "Do you want to modify parameters of the game?",
                                                                              QMessageBox::Yes | QMessageBox::No);

            if (modify_params == QMessageBox::Yes) {
                ui->stackedWidget->setCurrentIndex(2);
            } else if (modify_params == QMessageBox::No) {
                QMessageBox::information(this, "Continue",
                                         "Okay! We will continue the game with default parameters. Stay tuned!");
                QApplication::quit();
            }
        }
    }
}

void InstrWindow::on_pushButton_modifyParams_clicked() {
    QString team_num = ui->lineEdit_noOfTeams->text();
    QString holding_cost = ui->lineEdit_holdingCost->text();
    QString backorder_cost = ui->lineEdit_backOrderCost->text();
    QString total_weeks = ui->lineEdit_totalWeeks->text();
    QString starting_inventory = ui->lineEdit_startingInventory->text();
    QString shipment_delay = ui->lineEdit_shipmentDelay->text();
    QString order_delay = ui->lineEdit_orderDelay->text();

    // handle for null inputs
    if (team_num == NULL || holding_cost == NULL || backorder_cost == NULL ||
        total_weeks == NULL || starting_inventory == NULL || shipment_delay == NULL ||
        order_delay == NULL) {
        QMessageBox::warning(this, "Modify Parameters", "You need to fill all text fields.");
    } else {
        // validate input values by using regular expressions
        QRegularExpression reg_int("^[1-9]\\d*$");
        QRegularExpression reg_double("^[0-9]\\d{0,2}(\\.\\d{1,3})?%?$");
        if (!reg_int.match(team_num).hasMatch()) {
            QMessageBox::warning(this, "Invalid Input", "Please type in a valid team number input.");
        } else if (!reg_int.match(total_weeks).hasMatch()) {
            QMessageBox::warning(this, "Invalid Input", "Please type in a valid total weeks input.");
        } else if (!reg_int.match(starting_inventory).hasMatch()) {
            QMessageBox::warning(this, "Invalid Input", "Please type in a valid starting inventory input.");
        } else if (!reg_int.match(shipment_delay).hasMatch()) {
            QMessageBox::warning(this, "Invalid Input", "Please type in a valid shipment delay input.");
        } else if (!reg_int.match(order_delay).hasMatch()) {
            QMessageBox::warning(this, "Invalid Input", "Please type in a valid order delay input.");
        } else if (!reg_double.match(holding_cost).hasMatch()) {
            QMessageBox::warning(this, "Invalid Input", "Please type in a valid holding cost input.");
        } else if (!reg_double.match(backorder_cost).hasMatch()) {
            QMessageBox::warning(this, "Invalid Input", "Please type in a valid holding cost input.");
        } else {
            // pass the values to next screen
            ui->stackedWidget->setCurrentIndex(3);
            ui->lineEdit_noOfTeams_2->setText(team_num);
            ui->lineEdit_holdingCost_2->setText(holding_cost);
            ui->lineEdit_backOrderCost_2->setText(backorder_cost);
            ui->lineEdit_totalWeeks_2->setText(total_weeks);
            ui->lineEdit_startingInventory_2->setText(starting_inventory);
            ui->lineEdit_shipmentDelay_2->setText(shipment_delay);
            ui->lineEdit_orderDelay_2->setText(order_delay);

            ui->lineEdit_noOfTeams_2->setReadOnly(true);
            ui->lineEdit_holdingCost_2->setReadOnly(true);
            ui->lineEdit_backOrderCost_2->setReadOnly(true);
            ui->lineEdit_totalWeeks_2->setReadOnly(true);
            ui->lineEdit_startingInventory_2->setReadOnly(true);
            ui->lineEdit_shipmentDelay_2->setReadOnly(true);
            ui->lineEdit_orderDelay_2->setReadOnly(true);
        }
    }
}

void InstrWindow::on_pushButton_preview_goBack_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void InstrWindow::on_pushButton_startGame_instr_clicked() {
    // prepare to pass to Instructor Create Game class
    this->noOfGames = ui->lineEdit_noOfTeams_2->text().toInt();
    this->holdingCost = ui->lineEdit_holdingCost_2->text().toDouble();
    this->backorderCost = ui->lineEdit_backOrderCost_2->text().toDouble();
    this->totalWeeks = ui->lineEdit_totalWeeks_2->text().toInt();
    this->startingInventory = ui->lineEdit_startingInventory_2->text().toInt();
    this->shipmentDelay = ui->lineEdit_shipmentDelay_2->text().toInt();
    this->orderDelay = ui->lineEdit_orderDelay_2->text().toInt();

    instr->createGames(noOfGames, this);
    QMessageBox::information(this, "Game Setup Finished!", "Setting up parameters for the game"
                                                           "has been finished!");

    QMessageBox::StandardButton playGuest_params = QMessageBox::question(this,
                                                                         "Game Status?",
                                                                         "Show Game Status?",
                                                                         QMessageBox::Yes | QMessageBox::No);

    if (playGuest_params == QMessageBox::Yes) {
        instr->showGamesStatus();
    } else {
        close();
    }
}
