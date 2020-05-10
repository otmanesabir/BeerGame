#include "../include/instrgeneratepassword.h"
#include "ui_instrgeneratepassword.h"

InstrGeneratePassword::InstrGeneratePassword(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::InstrGeneratePassword) {
    ui->setupUi(this);
}

InstrGeneratePassword::~InstrGeneratePassword() {
    delete ui;
}
