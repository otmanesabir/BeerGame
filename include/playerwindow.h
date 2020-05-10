#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

/**
 * \class PlayerWindow
 * \brief Window screen for the player to play the game with params set by Instructor
 *
 */

#include <QWidget>


class Player;

namespace Ui {
    class PlayerWindow;
}

class PlayerWindow : public QWidget {
Q_OBJECT

public:
    /**
     * \brief constructor for Player Window Screen
     */

    PlayerWindow(QWidget *parent, Player &player);

    PlayerWindow(QWidget *parent = nullptr);

    /**
     * \brief destructor for Player Window Screen
     */
    virtual ~PlayerWindow();

private slots:

    /**
     * \brief pushButton for choosing player role as Retailer
     */
    void on_pushButton_retailer_clicked();

    /**
     * \brief pushButton for choosing player role as Wholesaler
     */
    void on_pushButton_wholesaler_clicked();

    /**
     * \brief pushButton for choosing player role as Distrubutor
     */
    void on_pushButton_distributor_clicked();

    /**
     * \brief pushButton for choosing player role as Factory
     */
    void on_pushButton_factory_clicked();

    /**
     * \brief pushButton to start playing the game
     */
    void on_pushButton_playNow_player_clicked();

    /**
     * \brief pushButton to place order to the upstream supplier
     */
    void on_pushButton_placeOrder_player_clicked();

private:
    /**
     * \brief Ui object
     */
    Ui::PlayerWindow *ui;
};

#endif // PLAYERWINDOW_H
