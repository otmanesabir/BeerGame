/**
 * \class Player
 * \brief Set and get properties from the Game Class accordingly
 *
 */
#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include "playerwindow.h"
#include "ui_playerwindow.h"


#include "PlayerEvent.h"


class Game;

#define CONSUMER 0
#define RETAILER 1
#define WHOLESALER 2
#define DISTRIBUTOR 3
#define FACTORY 4

const std::string PLAYER_NAMES[] = {
        "Consumer",
        "Retailer",
        "Wholesaler",
        "Distributor",
        "Factory"
};

/**
 * @brief The player class keeps track of a player's status in the game and contains methods for the player's functionalities
*/

class Player {
private:
    int pId{};
    int role{};

    int inventory = 12;
    int backOrder = 0;
    int incomingOrder = 0;
    int incomingShipment = 0;
    int outgoingShipment = 0;
    int demand{};

    double cost = 0;
    double totalCost = 0;

    bool orderReceived = false;
    bool shipmentReceived = false;

    int genOrderId();

    Game *game{};
    Ui::PlayerWindow *pUi{};

    bool orderPlaced = false;
    bool shipmentPlaced = false;


public: // every function here has been made void just for making template, change it accordingly
    Player() = default;

    Player(int role, Game *game, int inventory);

    /**
     * @brief Update the content of a player in PlayerWindow at the start of every round.
     *
     * After the shipments and orders for the week has been received, this method is called. It is responsible
     * for making necessary calcultions like: shipmentToBeDelivered, the new inventory and so on..
     */
    void updateUi();

    /**
     * @brief Process the value entered by the player: the order to send to the upstream
     *
     * This method is called by passing the value that a player has entered in the input field. While testing, this function can
     * be called manually, without having to press the button.
     */
    void processOrder(int order);

    /**
     * @brief Place number of orders and number of shipments for the current week
     *
     * After a player precess Place Order button, this method is called. It parameters dentoe how much the user wants to demand and how
     * much it can ship. Using these parameters, an Order and Shipment object is created. Then these objects are registered in the Game
     * object.
     */
    void order(int nOrders, int nShipments);

    /**
     * \brief place shipment received from the upstream supplier
     *
     * \param numberOfBeers
     */
    void placeShipment(int numberOfBeers);


    /**
     * @brief Based on the demand from the downstrea, it make changes to the inventory, and returns the number of beers that are available for
     * shipments
     */
    int getAvailableShipment(int numberOfBeers);

    /**
     * @brief places an order with the requested number of beers
     */
    void placeOrder(int numberOfBeers);

    /**
     * \brief receive shipment from the upstream supplier
     *
     * \param receivedBeers
     */
    void receiveShipment(int);

    /**
     * \brief receive order from the downstream supplier
     *
     * \param orderedBeers
     */
    void receiveOrder(int);

    /**
     * \brief decrease the Inventory of the player
     *
     * \return int
     */
    int decreaseInventory(int numberOfBeers);

    /**
     * \brief inrease the Inventory of the player
     *
     * \return int
     */
    int increaseInventory(int numberOfBeers);

    void setUi(Ui::PlayerWindow *ui);

    /**
      * \brief Set the player id
      *
      */
    void setPId(int);

    /**
     * \brief Set the Demand
     *
     */
    void setDemand(int);

    /**
     * \brief Set the Role
     *
     */
    void setRole(int);

    /**
     * \brief Set the Inventory
     *
     */
    void setInventory(int);


    /**
     * \brief Set the Backorder
     *
     */
    void setBackorder(int);

    void setOrderPlaced(bool);

    /**
     * \brief Set the Cost
     *
     */
    void setCost(double);

    /**
     * \brief Set the incoming order
     *
     *
     */
    void setIncomingOrder(int incomingOrder);

    /**
      * \brief set the incoming shipment
      *
      * \param incomingShipment
      */
    void setIncomingShipment(int incomingShipment);

    void setOutgoingShipment(int outgoingShipment);

    /**
     * \brief set total cost for the players
     * \param totalCost
     */
    void setTotalCost(double totalCost);

    /**
     * \brief set the incoming shipment
     *
     * \param orderReceived
     */
    void setOrderReceived(bool orderReceived);

    void setShimpentReceived(bool shipmentReceived);

    void setShipmentPlaced(bool shipmentPlaced);

    /**
     * \brief setter for game
     *
     */
    void setGame(Game *);

    /**
     * \brief Get the player id
     *
     * \return int
     */
    int getPId();

    bool isOrderPlaced();

    /**
     * \brief Get the Role
     *
     * \return int
     */
    int getRole() const { return role; };

    /**
     * \brief Get the Backorder
     *
     * \return int
     */
    int getBackorder();

    /**
     * \brief Get the Demand
     *
     * \return int
     */
    int getDemand();

    /**
     * \brief Get the Cost
     *
     * \return int
     */
    int getCost();

    /**
      * \brief Get the Inventory
      *
      * \return int
      */
    int getInventory();

    /**
      * \brief Get the incoming order
      *
      * \return int
      */
    int getIncomingOrder();

    /**
     * \brief get the incoming shipment
     *
     * \return int
     */
    int getIncomingShipment();

    /**
     * \brief get the incoming shipment
     *
     * \return int
     */
    int getOutgoingShipment();

    /**
     * \brief get total cost of the player
     * \return double
     */
    double getTotalCost();

    bool getOrderReceived();

    bool getShipmentReceived();

    bool getShipmentPlaced();

    /**
     * \brief getter for the game
     *
     * \return Game
     *
     */
    Game *getGame();

    int getBackOrder() const;

    void setBackOrder(int backOrder);

    bool isOrderReceived() const;

    bool isShipmentReceived() const;

    void setShipmentReceived(bool shipmentReceived);

    Ui::PlayerWindow *getPUi() const;

    void setPUi(Ui::PlayerWindow *pUi);

    bool isShipmentPlaced() const;
};

#endif //PLAYER_H
