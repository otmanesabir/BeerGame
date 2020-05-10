#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include <vector>

#include "Game.h"
#include "instrwindow.h"
#include "ui_instrwindow.h"

/**
 * @brief This class handles the functionalities of the instructor in the game.
*/

class InstrWindow;

class Instructor {
private:
    int instrId;
    std::string instrEmail;
    std::string instrPassword;

    std::vector<Game> games;
    Ui::InstrWindow *ui;
    QWidget *uiParent;

public: // every function here has been made void just for making template, change it accordingly

    ////
    // TEST
    ////

    /**
     * @brief Set the Instructor Email
     *
     */
    void setInstrEmail(std::string instrEmail);

    /**
     * @brief Set the Instructor Password
     *
     */
    void setInstrPassword(std::string instrPassword);

    /**
     * @brief Set the Instructor Id
     *
     */
    void setInstrId(int instrID);


    /**
     * @brief Get the Instructor Email
     *
     * @return string
     */
    std::string getInstrEmail();

    /**
     * @brief Get the Instructor Password
     *
     * @return string
     */
    std::string getInstrPassword();

    /**
     * @brief Get the Instructor Id
     *
     * @return int
     */
    int getInstrId();

    /**
 * @brief Shows the status of all games
 *
 * The current values of different attributes such as: holding cost, backorder cost, order delay etc. for each game are showed.
 */
    void showGamesStatus();

    /**
     * @brief Create a game for players
     *
     * @return int
     */
    Game createGame(InstrWindow *window);

    /**
     * @brief Creates games
     *
     * @param numberOfGames number of games to be created
     * @param instr_window
     */

    std::vector<Game> createGames(int numberOfGames, InstrWindow *instr_window);


    /**
     * @brief Set the Ui
     *
     * @param  ui pointer to ui Instruction
     */
    void setUi(Ui::InstrWindow *ui);

    void setWindowParent(QWidget *parent);

    const std::vector<Game> &getGames() const;

    void setGames(const std::vector<Game> &games);
};

#endif //INSTRUCTOR_H
