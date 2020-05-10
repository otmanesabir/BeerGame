#ifndef WELCOME_H
#define WELCOME_H

/**
 * \class Welcome
 * \brief Window screen of the very beginning of the game (Choose Player or Instructor role to continue)
 *
 */

#include <QMainWindow>
#include "instrwindow.h"
#include "playerwindow.h"


namespace Ui {
    class Welcome;
}

class Welcome : public QMainWindow {
Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);        /*!< Constructor */
    virtual ~Welcome();                                 /*!< Destructor */

private slots:

    void on_pushButton_Player_clicked();                /*!< Change screen for the player */
    void on_pushButton_Instructor_clicked();            /*!< Change screen for the instructor */

private:
    Ui::Welcome *ui;
    InstrWindow *instrWindow;                           /*!< Object for instructor window */
    PlayerWindow *playerWindow;                         /*!< Object for choose player role window */
    QWidget *pparent;
};

#endif // WELCOME_H
