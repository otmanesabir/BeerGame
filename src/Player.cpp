#include <iostream>
#include <string>

#include "Player.h"
#include "Game.h"
#include "Order.h"
#include "Shipment.h"

using namespace std;

Player::Player(int role, Game *game, int inventory) : role(role),
                                                      inventory(inventory),
                                                      game(game) {};

void Player::order(int nOrders, int nShipments) {
    placeOrder(nOrders);
    placeShipment(nShipments);
}

void Player::updateUi() {
    // enable button
//    cout << "World" << endl;
//    pUi->pushButton_placeOrder_player->setEnabled(true);
    pUi->lineEdit_currWeek_player->setText((QString) game->getCurrentWeek());

    pUi->lineEdit_incomeOrder_player->setText((QString) demand);

    totalCost += (double) game->getHoldingCost() * (double) inventory +
                 (double) game->getBackorderCost() * (double) backOrder;
    QString cost = QString::number(totalCost);
    pUi->lineEdit_cumulativeCost_player->setText(cost);

    // current
    pUi->lineEdit_inventory_player->setText((QString) inventory);
    pUi->lineEdit_backlogs_player->setText((QString) backOrder);

    // set outgoing and incoming  shipments
    increaseInventory(incomingShipment);
    if (role != CONSUMER)
        outgoingShipment = getAvailableShipment(demand);
    pUi->lineEdit_incomeDelivery_player->setText((QString) incomingShipment);
}

void Player::processOrder(int nOrders) {
    pUi->pushButton_placeOrder_player->setEnabled(false);
    order(nOrders, outgoingShipment);
}

void Player::receiveOrder(int orderedBeers) {
    if (backOrder != 0) {
        backOrder += orderedBeers;
    }
    else {
        if (inventory < orderedBeers) {
            backOrder = orderedBeers - inventory;
            inventory = 0;
        }
        else {
            inventory -= orderedBeers;
        }
    }
    orderReceived = true;

//    if (orderReceived && shipmentReceived) {
//        updateUi();
//    }
}

void Player::receiveShipment(int receivedBeers) {
    if (backOrder != 0) {
        if (receivedBeers < backOrder) {
            backOrder -= receivedBeers;
        }
        else {
            inventory = receivedBeers - backOrder;
            backOrder = 0;
        }
    }
    else {
        inventory += receivedBeers;
    }
    shipmentReceived = true;
//    if ((orderReceived && shipmentReceived) || role == CONSUMER) {
//        updateUi();
//    }
}

int Player::getAvailableShipment(int demand) {
    if (demand < 0) {
        throw std::range_error("Value of demand out of range [0..inf]");
    }
    if (demand < inventory) {
        return demand;
    }
    else {
        return inventory;
    }
};

int Player::decreaseInventory(int numberOfBeers) {
    inventory -= numberOfBeers;
    if (inventory < 0) {
        backOrder = abs(inventory);
        inventory = 0;
    }

    return inventory;
};

int Player::increaseInventory(int numberOfBeers) {
    inventory += numberOfBeers;
    return inventory;
};

void Player::setUi(Ui::PlayerWindow *pUi) {
    this->pUi = pUi;
}

int Player::genOrderId() {
    // id eg: 41. Means the ordered is made on 4th week by player 1 (Retailer)
    return (game->getCurrentWeek() + game->getOrderDelay()) * 10 + role;
};

void Player::placeOrder(int numberOfBeers) {
    if (numberOfBeers < 0) {
        throw std::range_error("Value of numberOfBeers out of range [0..inf]");
    }
    game->addOrder(role, numberOfBeers);
    orderPlaced = true;
}

void Player::placeShipment(int numberOfBeers) {
    if (numberOfBeers < 0) {
        throw std::range_error("Value of numberOfBeers out of range [0..inf]");
    }
    game->addShipment(role, numberOfBeers);
    shipmentPlaced = true;}

/////
/// For the sake of test cases
/////

void Player::setPId(int id) {
    this->pId = id;
}

void Player::setDemand(int demand) {
    this->demand = demand;
}

void Player::setCost(double cost) {
    this->cost = cost;
}

void Player::setInventory(int in) {
    this->inventory = in;
}

void Player::setBackorder(int o) {
    this->backOrder = o;
}

void Player::setOrderPlaced(bool o) {
    this->orderPlaced = o;
}

void Player::setRole(int role) {
    this->role = role;
}

void Player::setIncomingOrder(int incomingOrder) {
    this->incomingOrder = incomingOrder;
}

void Player::setIncomingShipment(int incomingShipment) {
    this->incomingShipment = incomingShipment;
}

void Player::setOutgoingShipment(int outgoingShipment) {
    this->outgoingShipment = outgoingShipment;
}

void Player::setTotalCost(double totalCost) {
    this->totalCost = totalCost;
}

void Player::setOrderReceived(bool orderReceived) {
    this->orderReceived = orderReceived;
}

void Player::setShimpentReceived(bool shipmentReceived) {
    this->shipmentReceived = shipmentReceived;
}

void Player::setShipmentPlaced(bool shipmentPlaced) {
    this->shipmentPlaced = shipmentPlaced;
}

void Player::setGame(Game *game) {
    this->game = game;
}

int Player::getPId() {
    return pId;
}

bool Player::isOrderPlaced() {
    return orderPlaced;
}

int Player::getDemand() {
    return demand;
}

int Player::getBackorder() {
    if (backOrder < 0) {
        // invalid backorder. Print to error window
    }
    return backOrder;
};

int Player::getCost() {
    return cost;
};

int Player::getInventory() {
    if (inventory < 0) {
        // assert or print log to error window.
    }
    return inventory;
};

int Player::getIncomingOrder() {
    return incomingOrder;
}

int Player::getIncomingShipment() {
    return incomingShipment;
}

int Player::getOutgoingShipment() {
    return outgoingShipment;
}

double Player::getTotalCost() {
    return totalCost;
}

bool Player::getOrderReceived() {
    return orderReceived;
}

bool Player::getShipmentReceived() {
    return shipmentReceived;
}

bool Player::getShipmentPlaced() {
    return shipmentPlaced;
}

Game *Player::getGame() {
    return game;
}

int Player::getBackOrder() const {
    return backOrder;
}

void Player::setBackOrder(int backOrder) {
    Player::backOrder = backOrder;
}

bool Player::isOrderReceived() const {
    return orderReceived;
}

bool Player::isShipmentReceived() const {
    return shipmentReceived;
}

void Player::setShipmentReceived(bool shipmentReceived) {
    Player::shipmentReceived = shipmentReceived;
}

Ui::PlayerWindow *Player::getPUi() const {
    return pUi;
}

void Player::setPUi(Ui::PlayerWindow *pUi) {
    Player::pUi = pUi;
}

bool Player::isShipmentPlaced() const {
    return shipmentPlaced;
}

