#ifndef INSTRWINDOW_H
#define INSTRWINDOW_H

/**
  * \class InstrWindow
  * \brief Window Screen for Instructor to login/signup and modify parameters for the game
  */

#include <QWidget>


class Instructor;

namespace Ui {
    class InstrWindow;
}

class InstrWindow : public QWidget {
Q_OBJECT

public:
    /**
     * \brief constructor for Instructor Window Screen
    */
    explicit InstrWindow(QWidget *parent = nullptr);

    /**
     * \brief destructor for Instructuo Window Screen
    */
    virtual ~InstrWindow();

    /**
     * \brief noOfGames to pass to backend
     */
    int noOfGames;

    /**
     * \brief holdingCost to pass to backend
     */
    double holdingCost;

    /**
     * \brief backorderCost to pass to backend
     */
    double backorderCost;

    /**
     * \brief totalWeeks to pass to backend
     */
    int totalWeeks;

    /**
     * \brief startingInventor to pass to backend
     */
    int startingInventory;

    /**
     * \brief shipmentDelay to pass to backend
     */
    int shipmentDelay;

    /**
     * \brief orderDelay to pass to backend
     */
    int orderDelay;

private slots:

    /**
     * \brief pushButton to Login as Instructor
     */
    void on_pushButton_login_clicked();

    /**
     * \brief pushButton to redirect Signup window from Login window
     */
    void on_pushButton_instrSignupFromLogin_clicked();

    /**
     * \brief pushButton to Signup as Instructor
     */
    void on_pushButton_instrSignup_clicked();

    /**
     * \brief pushButton to modify Parameters of the Game as Instructor
     */
    void on_pushButton_modifyParams_clicked();

    /**
     * \brief pushButton to preview Parameters of the Game as Instructor
     */
    void on_pushButton_preview_goBack_clicked();

    /**
     * \brief pushButton to start Game as Instructor
     */
    void on_pushButton_startGame_instr_clicked();

private:
    /**
     * \brief Ui object
     */
    Ui::InstrWindow *ui;
    /**
     * \brief Instructor object
     */
    Instructor *instr;
};

#endif // INSTRWINDOW_H
