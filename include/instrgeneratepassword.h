#ifndef INSTRGENERATEPASSWORD_H
#define INSTRGENERATEPASSWORD_H

#include <QMainWindow>

namespace Ui {
    class InstrGeneratePassword;
}

class InstrGeneratePassword : public QMainWindow {
Q_OBJECT

public:
    explicit InstrGeneratePassword(QWidget *parent = nullptr);

    ~InstrGeneratePassword();

private:
    Ui::InstrGeneratePassword *ui;
};

#endif // INSTRGENERATEPASSWORD_H
