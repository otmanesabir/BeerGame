#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "../include/Game.h"
#include "../include/Instructor.h"
#include "../include/instrwindow.h"
#include "ui_instrwindow.h"

using namespace std;

void Instructor::setUi(Ui::InstrWindow *ui) {
    this->ui = ui;
}

void Instructor::setWindowParent(QWidget *uiParent) {
    this->uiParent = uiParent;
}

//Need to be printed on a window, not using cout
void Instructor::showGamesStatus() {
    int numberOfGames = games.size();
    for (int i = 0; i < numberOfGames; i++) {
        cout << "Game Nr. " << i + 1 << ":" << endl;
        cout << "Order Delay: " << games[i].getOrderDelay() << endl;
        cout << "Holding Cost: " << games[i].getHoldingCost() << endl;
        cout << "Backorder Cost: " << games[i].getBackorderCost() << endl;
        //Other attributes need to be printed
    }
};

Game Instructor::createGame(InstrWindow *instr_window) {
    Game game;
    game.setHoldingCost(instr_window->holdingCost);
    game.setBackorderCost(instr_window->backorderCost);
    game.setWeeksToBePlayed(instr_window->totalWeeks);
    game.setStartingInventory(instr_window->startingInventory);
    game.setShipmentDelay(instr_window->shipmentDelay);
    game.setOrderDelay(instr_window->orderDelay);

    auto *retailer = new Player(RETAILER, &game, game.getStartingInventory());
    auto *wholesaler = new Player(WHOLESALER, &game, game.getStartingInventory());
    auto *distributor = new Player(DISTRIBUTOR, &game, game.getStartingInventory());
    auto *factory = new Player(FACTORY, &game, game.getStartingInventory());

    game.addPlayer(retailer);
    game.addPlayer(wholesaler);
    game.addPlayer(distributor);
    game.addPlayer(factory);

    //    PlayerWindow* retailerW = new PlayerWindow(uiParent, *retailer);
    //    PlayerWindow* wholesalerW = new PlayerWindow(uiParent, *wholesaler);
    //    PlayerWindow* distributorW = new PlayerWindow(uiParent, *distributor);
    //    PlayerWindow* factoryW = new PlayerWindow(uiParent, *factory);

    //    ofstream file;
    //    file.open("passwords.txt");
    //    for(int i = 0; i < numberOfGames; i++){
    //        std::vector<string> pPasswords;
    //        pPasswords = game.generatePasswords();
    //        file << i+1 << endl;
    //        for(unsigned int j = 0; j < pPasswords.size(); j++){
    //            file << pPasswords[j] << endl;
    //        }
    //    }
    //    file.close();

    game.initGame();
    game.startGame();

    //    retailerW->show(); retailerW->move(0, 0);
    //    wholesalerW->show(); wholesalerW->move(0, 800);
    //    distributorW->show(); distributorW->move(800, 0);
    //    factoryW->show(); factoryW->move(800, 800);
    return game;
}

vector<Game> Instructor::createGames(int numberOfGames, InstrWindow *instr_window) {
    Game game;
    for (int i = 0; i < numberOfGames; i++) {
        game = createGame(instr_window);
        this->games.push_back(game);
    }

    return this->games;
}

/////
/// Instructor setters and getters
/////

void Instructor::setInstrEmail(string instrEmail) {
    this->instrEmail = instrEmail;
}

void Instructor::setInstrPassword(string instrPassword) {
    this->instrPassword = instrPassword;
}

void Instructor::setInstrId(int instrId) {
    this->instrId = instrId;
}

string Instructor::getInstrEmail() {
    return instrEmail;
}

string Instructor::getInstrPassword() {
    return instrPassword;
}

int Instructor::getInstrId() {
    return instrId;
}

const vector<Game> &Instructor::getGames() const {
    return games;
}

void Instructor::setGames(const vector<Game> &games) {
    Instructor::games = games;
}

