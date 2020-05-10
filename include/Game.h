/**
 * \class Game
 * \brief Set and Get IDs of players accordingly for shipment and order proccesses
 *
 */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>

#include "PlayerEvent.h"
#include "Order.h"
#include "Shipment.h"


/**
 * \brief Handles a game
 */

class Game {
private:
    UniqueID gId;
    UniqueID instrId;
    UniqueID pFactId;
    UniqueID pDistributorId;
    UniqueID pWholesalerId;
    UniqueID pRetailerId;

    int startingInventory = 12;
    int weeksToBePlayed = 26;
    int currentWeek = 0;
    int infoCode = 0;
    int factoryDelay = 1;
    int nOrdersReceived = 0;
    int nShipmentsReceived = 0;
    int shipmentDelay = 2;
    int numberOfPlayers = 5;
    int orderDelay = 2;

    double holdingCost = 0.5;
    double backorderCost = 1;

    std::vector<Player *> players;
    std::vector<int> consumerDemandPerWeek =
            {6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

    std::map<int, std::vector<Order>> ordersToBeExecuted;
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;

    void clearConsumerDemandPerWeek();
    void clearPlayers();
    void clearOrdersToBeExecuted();
    void clearShipmentsToBeExecuted();
public:
    /**
    * \brief Constructor for game class, sets the default values for game class
    */
    Game();

    explicit Game(int,
                  int = (int) UniqueID(),
                  int = (int) UniqueID(),
                  int = (int) UniqueID(-1, true),
                  int = (int) UniqueID(-1, true),
                  int = (int) UniqueID(-1, true),
                  int = (int) UniqueID(-1, true),
                  int = 2,
                  int = 12,
                  int = 8,
                  int = 2,
                  int = 1,
                  double = 0.5,
                  double = 1.0);

    ~Game();


    // GETTERS

    int getConsumerOrderForWeek();

    /**
    * \brief Getter method for instructor Id
    * \return Instructor Id
    */
    int getInstrId();

    /**
     * \brief Getter method for Factory Id
     * \return Factory Id
    */
    int getPFactId();

    /**
     * \brief Getter method for distributor Id
     * \return distributor Id
    */
    int getPDistributorId();

    /**
     * \brief Getter method for wholeseller Id
     * \return wholeseller Id
    */
    int getPWholesalerId();

    /**
     * \brief Getter method for retailer Id
     * \return retailer Id
    */
    int getPRetailerId();

    /**
         * \brief Getter method for Game Id
         * \return Game Id
    */
    int getGId();

    /**
     * \brief Getter method for weeks to be played
     * \return weeks to be played
    */

    int getWeeksToBePlayed();

    /**
     * \brief Getter method for Info Code
     * \return Info code
    */
    int getInfoCode();

    /**
     * \brief Getter method for Backorder Cost
     * \return Backorder Cost
    */
    double getBackorderCost();

    /**
     * \brief Getter method for Holding cost
     * \return Holding cost
    */
    double getHoldingCost();

    int getFactoryDelay();

    /**
     * \brief Getter method for Order delay
     * \return order Delay
    */
    int getOrderDelay();

    /**
     * \brief Getter method for Starting Inventory
     * \return Starting inventory
    */
    int getStartingInventory();

    /**
     * \brief Getter method for current cost
     * \return current cost
    */
    int getCurrentWeek();

    /**
    * @brief Returns the pointer to the downstream player for the player whose role is 'role'
    */
    Player *getDownstream(int role);

    /**
     * @brief Returns the pointer to the upstream player for the player whose role is 'role'
     */
    Player *getUpstream(int role);

    /**
     * \brief Getter method for Shipment delay
     * \return Shipment Delay
    */
    int getShipmentDelay();


    std::map<int, std::vector<Order>> getOrdersToBeExecuted();

    std::map<int, std::vector<Shipment>> getShipmentsToBeExecuted();

    /**
     * \brief Getter for Player vector
     */
    std::vector<Player *> getPlayers();

    /**
     * \brief Method for getConsumerDemandPerWeek
     */
    std::vector<int> getConsumerDemandPerWeek();

    int getNumberOfPlayers();

    //////
    /// Setters
    //////

    /**
        * \brief Setter method for the Instructor Id
        * \param iId setting value for Instructor Id
        * \param overwrite
       */
    void setInstrId(int, bool = false);

    void setInstrId(UniqueID &, bool = false);

    /**
         * \brief Setter method for the Factory Id
         * \param nId seeting value for Factory Id
         * \param overwrite
        */
    void setPFactId(int, bool = false);

    void setPFactId(UniqueID &, bool = false);

    /**
         * \brief Setter method for the Distributor Id
         * \param nId seeting value for Distributor Id
         * \param overwrite
        */
    void setPDistributorId(int, bool = false);

    void setPDistributorId(UniqueID &, bool = false);

    /**
     * \brief Setter method for the Wholesaler Id
     * \param nId seeting value for Wholesaler Id
     * \param overwrite
    */
    void setPWholesalerId(int, bool = false);

    void setPWholesalerId(UniqueID &, bool = false);

    /**
     * \brief Setter method for the Retailer Id
     * \param nId seeting value for Retailer Id
     * \param overwrite
    */
    void setPRetailerId(int, bool = false);

    void setPRetailerId(UniqueID &, bool = false);

    /**
         * \brief Setter method for the Game Id
         * \param nId seeting value Game Id
         * \param overwrite
        */
    void setGId(int, bool = false);

    void setGId(UniqueID &, bool = false);

    /**
      * \brief Setter method for Weeks to be played
      * \param w seeting value for Weeks to be played
     */

    void setWeeksToBePlayed(int);

    /**
     * \brief Setter method for the Info code
     * \param code seeting value for Info code
    */

    void setInfoCode(int);

    /**
     * \brief Setter method for Backorder cost
     * \param cost seeting value for Backorder cost
    */

    void setBackorderCost(double);

    /**
     * \brief Setter method for the Holding cost
     * \param hc seeting value for Holding cost
    */

    void setHoldingCost(double);


    void setFactoryDelay(int);

    /**
     * \brief Setter method for the Order delay
     * \param od seeting value for the order delay
    */
    void setOrderDelay(int);

    /**
     * \brief Setter method for the Starting inventory
     * \param si seeting value for starting inventory
    */

    void setStartingInventory(int si);

    /**
     * \brief Setter method for the Current Week
     * \param week seeting value for current week
    */

    void setCurrentWeek(int week);

    /**
     * \brief Setter method for the Shipment delay
     * \param sd setting value for shipment delay
    */

    void setShipmentDelay(int);

    void setOrdersToBeExecuted(std::map<int, std::vector<Order>>);

    void setShipmentsToBeExecuted(std::map<int, std::vector<Shipment>>);

    /**
     * \brief Setter for Player vector
     */
    void setPlayers(std::vector<Player *> players);

    void setConsumerDemandPerWeek(std::vector<int>, bool = true);

    void setNumberOfPlayers(int numberOfPlayers);



    ///
    // For test cases
    ///

    // METHODS

    /**
    * @brief Call executeOrderForCurrentWeek() and executeShipmentForCurrentWeek()
    */
    int advanceWeek();

    /**
     * @brief Adds an order with the number of beers specified
     *
     * Creates an object of the class Order which is put in the map, ordersToBeExecuted, according to the role
     *
     * @param role Role of the player
     * @param numberOfBeers The number of beers ordered
     */
    void addOrder(const int &role, int numberOfBeers);

    /**
     * @brief Adds a shipment with the number of beers specified
     *
     * The shipment contains a property that says in which week it is going to be executed. Using this property, the shipment is placed in
     * shipmentsToBeExecuted vector's correct location
     *
     * @param role Role of the player
     * @param numberOfBeers The number of beers to ship
     */
    void addShipment(int role, int numberOfBeers);

    /**
     * @brief Adds a player pointer to the list of player
     *
     * Note that the order of addition matters. The order should be from downstream to upstream.
     */
    void addPlayer(Player *player);

    std::vector<std::string> generatePasswords(int = 1);

    /**
    * @brief Initializes a game based on supplied setters.
    *
    * One main responsibility of this method is to create orders and shipments based on the order delay. For example, if the orderDelay is 2 weeks, orders and shipments for
    * two weeks should be created. These values are either set by default or accessed using instructor. However, as of Sprint2, the functionality
    * for instructor to enter these values does not exist
    */
    void initGame();

    /**
     * @brief This method is called by the instructor to start the game
     *
     * Basically when this function is called, it starts executing orders and shipments for the 1st week
     */
    void startGame();

    /**
     * @brief Takes the order vector for the current week based on currentWeek proerty. Then loops through the vector and
     * executes the orders by calling order.executeEvent()
     */
    void executeOrdersForCurrentWeek();

    /**
     * @brief Takes the shipment vector for the current week based on currentWeek proerty. Then loops through the vector and
     * executes the shipments by calling shipment.executeEvent()
     */
    void executeShipmentsForCurrentWeek();

    /**
     * @brief This method was listed in the initial documentation, but has been deprecated
     *
     * @deprecated
     */
    void updatePlayerInventories();

    /**
     * @brief For the current week return the consumer order.
     *
     * The values for consumer order are set by default. These values can be overriden by values provided by the instructor. However, as of Sprint2
     * this functionality in instructor does not exist
     *
     * @return Consumer order for the current week.
     */

    bool flushMemory();

    bool AssessLogic(bool = false);

    int getConsumerDemandForWeek(int week);

    bool operator==(const Game &rhs) const;
};

#endif //GAME_H