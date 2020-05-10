#include <Exceptions.h>
#include "gtest/gtest.h"
#include "Game.h"

TEST(gameTest, parametricConstructorTest) {
    UniqueID(false);
    Game a(105);
    EXPECT_EQ(a.getInfoCode(), 105);
}

TEST(gameTest, setInstructorIDTest) {
    Game g;
    UniqueID(false);
    g.setInstrId(1);
    EXPECT_EQ(1, g.getInstrId());
}

TEST(gameTest, setInstructorID_UniqueID_Test) {
    Game g;
    UniqueID(false);
    UniqueID a(1);
    g.setInstrId(a);
    EXPECT_EQ(1, g.getInstrId());
}
TEST(gameTest, setInstructorIDException) {
    Game g;
    EXPECT_ANY_THROW(g.setInstrId(1));
}

TEST(gameTest, setInstructorID_UniqueID_Exception) {
    Game g;
    EXPECT_ANY_THROW(g.setInstrId(UniqueID(1)));
}

TEST(gameTest, setInstructorIDNoException) {
    Game g;
    EXPECT_NO_THROW(g.setInstrId(1, true));
}


TEST(gameTest, setGameIDTest) {
    Game g;
    UniqueID(false);
    g.setGId(2);
    EXPECT_EQ(2, g.getGId());
}

TEST(gameTest, setGameID_UniqueID_Test) {
    Game g;
    UniqueID(false);
    UniqueID a(2);
    g.setGId(a);
    EXPECT_EQ(2, g.getGId());
}

TEST(gameTest, setGameIDNoException) {
    Game g;
    EXPECT_NO_THROW(g.setGId(1, true));
}

TEST(gameTest, setGameIDException) {
    Game g;
    EXPECT_ANY_THROW(g.setGId(1));
}

TEST(gameTest, setGameID_UniqueID_Exception) {
    Game g;
    EXPECT_ANY_THROW(g.setGId(UniqueID(1)));
}


// Factory
TEST(gameTest, setPFactIDTest) {
    Game g;
    UniqueID(false);
    g.setPFactId(3, true);
    EXPECT_EQ(3, g.getPFactId());
}

TEST(gameTest, setPFactID_UniqueID_Test) {
    Game g;
    UniqueID(false);
    UniqueID a(2);
    g.setPFactId(a, true);
    EXPECT_EQ(2, g.getPFactId());
}

TEST(gameTest, setPFactIDNoException) {
    Game g;
    EXPECT_NO_THROW(g.setPFactId(1, true));
}

TEST(gameTest, setPFactIDException) {
    Game g;
    EXPECT_ANY_THROW(g.setPFactId(1));
}

TEST(gameTest, setPFactID_UniqueID_Exception) {
    Game g;
    EXPECT_ANY_THROW(g.setPFactId(UniqueID(1)));
}

// DISTRIBUTOR
TEST(gameTest, setPDistributorIDTest) {
    Game g;
    UniqueID(false);
    g.setPDistributorId(3, true);
    EXPECT_EQ(3, g.getPDistributorId());
}

TEST(gameTest, setPDistributorID_UniqueID_Test) {
    Game g;
    UniqueID(false);
    UniqueID a(2);
    g.setPDistributorId(a, true);
    EXPECT_EQ(2, g.getPDistributorId());
}

TEST(gameTest, setPDistributorIDNoException) {
    Game g;
    EXPECT_NO_THROW(g.setPDistributorId(1, true));
}

TEST(gameTest, setPDistributorIDException) {
    Game g;
    EXPECT_ANY_THROW(g.setPDistributorId(1));
}

TEST(gameTest, setPDistrbutorID_UniqueID_Exception) {
    Game g;
    EXPECT_ANY_THROW(g.setPDistributorId(UniqueID(1)));
}


// WHOLESALER //
TEST(gameTest, setPWholesalerIDTest) {
    Game g;
    UniqueID(false);
    g.setPWholesalerId(3, true);
    EXPECT_EQ(3, g.getPWholesalerId());
}
TEST(gameTest, setPWholesalerID_UniqueID_Test) {
    Game g;
    UniqueID(false);
    UniqueID a(2);
    g.setPWholesalerId(a, true);
    EXPECT_EQ(2, g.getPWholesalerId());
}
TEST(gameTest, setPWholesalerIDNoException) {
    Game g;
    EXPECT_NO_THROW(g.setPWholesalerId(1, true));
}
TEST(gameTest, setWholesalerIDException) {
    Game g;
    EXPECT_ANY_THROW(g.setPWholesalerId(1));
}
TEST(gameTest, setPWholesalerID_UniqueID_Exception) {
    Game g;
    EXPECT_ANY_THROW(g.setPWholesalerId(UniqueID(1)));
}


// RETAILER //
TEST(gameTest, setPRetailerIDTest) {
    Game g;
    UniqueID(false);
    g.setPRetailerId(3, true);
    EXPECT_EQ(3, g.getPRetailerId());
}
TEST(gameTest, setPRetailerID_UniqueID_Test) {
    Game g;
    UniqueID(false);
    UniqueID a(2);
    g.setPRetailerId(a, true);
    EXPECT_EQ(2, g.getPRetailerId());
}
TEST(gameTest, setPRetailerIDNoException) {
    Game g;
    EXPECT_NO_THROW(g.setPRetailerId(1, true));
}
TEST(gameTest, setPRetailerIDException) {
    Game g;
    EXPECT_ANY_THROW(g.setPRetailerId(1));
}
TEST(gameTest, setPRetailerID_UniqueID_Exception) {
    Game g;
    EXPECT_ANY_THROW(g.setPRetailerId(UniqueID(1)));
}


// SET WEEKS TO BE PLAYED
TEST(gameTest, setWeeksToBePlayedTest) {
    Game g;
    g.setWeeksToBePlayed(5);
    EXPECT_EQ(g.getWeeksToBePlayed(), 5);
}
TEST(gameTest, setWeeksToBePlayedExceptionTest) {
    Game g;
    EXPECT_ANY_THROW(g.setWeeksToBePlayed(-1));
}


// SET INFO CODE TEST
TEST(gameTest, setInfoCodeTest){
    Game g;
    g.setInfoCode(4357);
    EXPECT_EQ(g.getInfoCode(), 4357);
}
TEST(gameTest, setInfoCodeExceptionTest){
    Game g;
    EXPECT_ANY_THROW(g.setInfoCode(-5872));
}


// SET STARTING INVENTORY
TEST(gameTest, setStartingInventoryTest) {
    Game g;
    g.setStartingInventory(5);
    EXPECT_EQ(5, g.getStartingInventory());
}
TEST(gameTest, setStartingInventoryExceptionTest){
    Game g;
    EXPECT_ANY_THROW(g.setStartingInventory(-5));
}


// SET BACKORDER COST
TEST(gameTest, setBackorderCostTest){
    Game g;
    g.setBackorderCost(0.5);
    EXPECT_EQ(g.getBackorderCost(), 0.5);
}
TEST(gameTest, setBackorderCostExceptionTest){
    Game g;
    EXPECT_ANY_THROW(g.setBackorderCost(-0.5));
}


// SET HOLDING COST
TEST(gameTest, setHoldingCostTest){
    Game g;
    g.setHoldingCost(0.5);
    EXPECT_EQ(0.5, g.getHoldingCost());
}
TEST(gameTest, setHoldingCostExceptionTest){
    Game g;
    EXPECT_ANY_THROW(g.setHoldingCost(-0.5));
}

// SET FACTORY DELAY
TEST(gameTest, setFactoryDelayTest){
    Game g;
    g.setFactoryDelay(5);
    EXPECT_EQ(5, g.getFactoryDelay());
}
TEST(gameTest, setFactoryDelayExceptionTest){
    Game g;
    EXPECT_ANY_THROW(g.setFactoryDelay(-5));
}


// SET ORDER DELAY
TEST(gameTest, setOrderDelayTest){
    Game g;
    g.setOrderDelay(2);
    EXPECT_EQ(2, g.getOrderDelay());
}
TEST(gameTest, setOrderDelayExceptionTest){
    Game g;
    EXPECT_ANY_THROW(g.setOrderDelay(-5));
}


// TEST SHIPMENT DELAY
TEST(gameTest, setSipmentDelayTest) {
    Game g;
    g.setShipmentDelay(5);
    EXPECT_EQ(5, g.getShipmentDelay());
}
TEST(gameTest, setShipmentDelayExceptioTest){
    Game g;
    EXPECT_ANY_THROW(g.setShipmentDelay(-2));
}

// TEST SET ORDERS TO BE EXECUTED
TEST(gameTest, setOrdersToBeExecuted) {
    UniqueID(false);
    Game g;
    std::map<int, std::vector<Order>> otbe;
    Player *a;
    Order o1(123, 5, 2, a);
    Order o2(123, 5, 2, a);
    Order o3(123, 5, 2, a);
    std::vector<Order> orders1 = {o1 , o2, o3};
    otbe.insert(std::pair<int, std::vector<Order>>(0, orders1));
    g.setOrdersToBeExecuted(otbe);
    auto smt = g.getOrdersToBeExecuted();
    EXPECT_TRUE(smt[0].size() == otbe[0].size());
}


// TEST SET SHIPMENTS TO BE EXECUTED
TEST(gameTest, setShipmentsToBeExecuted) {
    UniqueID(false);
    Game g;
    std::map<int, std::vector<Shipment>> stbe;
    Player *a;
    Shipment o1(123, 5, 2, a);
    Shipment o2(123, 5, 2, a);
    Shipment o3(123, 5, 2, a);
    std::vector<Shipment> shipments = {o1 , o2, o3};
    stbe.insert(std::pair<int, std::vector<Shipment>>(0, shipments));
    g.setShipmentsToBeExecuted(stbe);
    auto smt = g.getShipmentsToBeExecuted();
    EXPECT_TRUE(smt[0].size() == stbe[0].size());
}


//TEST GET PLAYERS
TEST(gameTest, setPlayersTest){
    UniqueID(false);
    std::vector<Player*> players;
    players.reserve(2);
    Player a;
    Player b;
    a.setPId(12);
    b.setPId(13);
    players.push_back(&a);
    players.push_back(&b);
    Game g;
    g.setPlayers(players);
    auto test = g.getPlayers();
    EXPECT_EQ(test[0]->getPId(), 12);
    EXPECT_EQ(test[1]->getPId(), 13);
}


// SET CURRENT WEEK TEST
TEST(gameTest, setCurrentWeekTest) {
    Game g;
    EXPECT_NO_THROW(g.setCurrentWeek(5));
    EXPECT_EQ(5, g.getCurrentWeek());
}
TEST(gameTest, setCurrentWeekExceptionTest) {
    Game g;
    g.setWeeksToBePlayed(4);
    EXPECT_ANY_THROW(g.setCurrentWeek(5));
}


// ADVANCE WEEK TESTS
TEST(gameTest, advanceWeekTest) {
    Game g;
    g.advanceWeek();
    EXPECT_EQ(1, g.getCurrentWeek());
}
TEST(gameTest, advanceWeekEXCEPTIONTest){
    Game g;
    g.setWeeksToBePlayed(10);
    for (int i = 0; i < 10; i++){
        g.advanceWeek();
    }
    EXPECT_ANY_THROW(g.advanceWeek());
}



TEST(gameTest, getConsumerDemandForWeekOverwriteTest){
    Game g;
    std::vector<int> cdpw = {2, 3, 5, 7, 8};
    g.setWeeksToBePlayed(3);
    g.setConsumerDemandPerWeek(cdpw, true);
    EXPECT_EQ(cdpw, g.getConsumerDemandPerWeek());
    EXPECT_EQ(cdpw.size(), g.getWeeksToBePlayed());
}
TEST(gameTest, getConsumerDemandForWeekNoOverwriteTest){
    Game g;
    std::vector<int> cdpw = {2, 3, 5, 7, 8};
    std::vector<int> cpy(g.getConsumerDemandPerWeek());
    std::copy(cdpw.cbegin(), cdpw.cend(), back_inserter(cpy));
    g.setWeeksToBePlayed(g.getWeeksToBePlayed() + cdpw.size());
    g.setConsumerDemandPerWeek(cdpw, false);
    EXPECT_EQ(cpy, g.getConsumerDemandPerWeek());
}
TEST(gameTest, getConsumerDemandForWeekException1Test){
    Game g;
    std::vector<int> cdpw = {2, 3, 5, 7, 8};
    std::vector<int> cpy(g.getConsumerDemandPerWeek());
    std::copy(cdpw.cbegin(), cdpw.cend(), back_inserter(cpy));
    g.setWeeksToBePlayed(cdpw.size());
    EXPECT_ANY_THROW(g.setConsumerDemandPerWeek(cdpw, false));
}


TEST(gameTest, setNumberOfPlayersTest){
    Game g;
    Game g2;
    EXPECT_NO_THROW(g.setNumberOfPlayers(3));
    EXPECT_NO_THROW(g2.setNumberOfPlayers(2));
    EXPECT_EQ(3, g.getNumberOfPlayers());
    EXPECT_EQ(2, g2.getNumberOfPlayers());
}
TEST(gameTest, setNumberOfPlayersExceptionTest){
    Game g;
    EXPECT_ANY_THROW(g.setNumberOfPlayers(7));
}


// GET CONSUMER ORDER FOR WEEK
TEST(gameTest, getConsumerOrderForWeek){
    Game g;
    std::vector<int> cdpw = {2, 3, 5, 7, 8};
    g.setWeeksToBePlayed(5);
    g.setConsumerDemandPerWeek(cdpw, true);
    g.advanceWeek();
    EXPECT_EQ(2, g.getConsumerOrderForWeek());
    g.advanceWeek();
    EXPECT_EQ(3, g.getConsumerOrderForWeek());
}


TEST(gameTest, AssesslogicTest){
    Game g;
    EXPECT_ANY_THROW(g.AssessLogic(true));
}
TEST(gameTest, AssessLogicTest){
    Game g;
    EXPECT_FALSE(g.AssessLogic(false));
}

TEST(gameTest, setGIdTest){
    Game game;
    game.setGId(1, true);
    EXPECT_EQ(game.getGId(), 1);
}

TEST(gameTest, getGIdTest){
    Game game;
    game.setGId(2, true);
    EXPECT_EQ(game.getGId(), 2);
}

TEST(gameTest, setInstrIdTest){
    Game game;
    game.setInstrId(1, true);
    EXPECT_EQ(game.getInstrId(), 1);
}

TEST(gameTest, getInstrIdTest){
    Game game;
    game.setInstrId(2, true);
    EXPECT_EQ(game.getInstrId(), 2);
}

TEST(gameTest, setPFactIdTest){
    Game game;
    game.setPFactId(1, true);
    EXPECT_EQ(game.getPFactId(), 1);
}

TEST(gameTest, getPFactIdTest){
    Game game;
    game.setPFactId(2, true);
    EXPECT_EQ(game.getPFactId(), 2);
}

TEST(gameTest, getPDistributorIdTest){
    Game game;
    game.setPDistributorId(1, true);
    EXPECT_EQ(game.getPDistributorId(), 1);
}

TEST(gameTest, setPDistributorIdTest){
    Game game;
    game.setPDistributorId(2, true);
    EXPECT_EQ(game.getPDistributorId(), 2);
}

TEST(gameTest, getPWholesalerIdTest){
    Game game;
    game.setPWholesalerId(1, true);
    EXPECT_EQ(game.getPWholesalerId(), 1);
}

TEST(gameTest, setPWholesalerIdTest){
    Game game;
    game.setPWholesalerId(2, true);
    EXPECT_EQ(game.getPWholesalerId(), 2);
}

TEST(gameTest, setPRetailerIdTest){
    Game game;
    game.setPRetailerId(1, true);
    EXPECT_EQ(game.getPRetailerId(), 1);
}

TEST(gameTest, getPRetailerIdTest){
    Game game;
    game.setPRetailerId(2, true);
    EXPECT_EQ(game.getPRetailerId(), 2);
}

TEST(gameTest, setOrdersToBeExecutedTest) {
    Game game;
    std::vector<Order> orders (4);
    Order order0, order1, order2, order3;
    order0.setNumberOfBeers(0);
    order1.setNumberOfBeers(1);
    order2.setNumberOfBeers(2);
    order3.setNumberOfBeers(3);
    orders[0] = order0;
    orders[1] = order1;
    orders[2] = order2;
    orders[3] = order3;
    std::map<int, std::vector<Order>> ordersToBeExecuted;
    ordersToBeExecuted[2] = orders;
    game.setOrdersToBeExecuted(ordersToBeExecuted);
    EXPECT_EQ(game.getOrdersToBeExecuted(), ordersToBeExecuted);
}

TEST(gameTest, getOrdersToBeExecutedTest) {
    Game game;
    std::vector<Order> orders (1);
    Order order0;
    order0.setNumberOfBeers(1);
    orders[0] = order0;
    std::map<int, std::vector<Order>> ordersToBeExecuted;
    ordersToBeExecuted[17] = orders;
    game.setOrdersToBeExecuted(ordersToBeExecuted);
    EXPECT_EQ(game.getOrdersToBeExecuted(), ordersToBeExecuted);
}

TEST(gameTest, setShipmentsToBeExecutedTest) {
    Game game;
    std::vector<Shipment> shipments (4);
    Shipment shipment0, shipment1, shipment2, shipment3;
    shipment0.setNumberOfBeers(0);
    shipment1.setNumberOfBeers(1);
    shipment2.setNumberOfBeers(2);
    shipment3.setNumberOfBeers(3);
    shipments[0] = shipment0;
    shipments[1] = shipment1;
    shipments[2] = shipment2;
    shipments[3] = shipment3;
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;
    shipmentsToBeExecuted[2] = shipments;
    game.setShipmentsToBeExecuted(shipmentsToBeExecuted);
    EXPECT_EQ(game.getShipmentsToBeExecuted(), shipmentsToBeExecuted);
}

TEST(gameTest, getShipmentsToBeExecutedTest) {
    Game game;
    std::vector<Shipment> shipments (1);
    Shipment shipment0;
    shipment0.setNumberOfBeers(1);
    shipments[0] = shipment0;
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;
    shipmentsToBeExecuted[17] = shipments;
    game.setShipmentsToBeExecuted(shipmentsToBeExecuted);
    EXPECT_EQ(game.getShipmentsToBeExecuted(), shipmentsToBeExecuted);
}

TEST(gameTest, getPlayersTest) {
    std::vector<Player*> players (2);
    auto* player0 = new Player;
    player0->setPId(1);
    auto* player1 = new Player;
    player1->setPId(2);
    players[0] = player0;
    players[1] = player1;
    Game game;
    game.setPlayers(players);
    EXPECT_EQ(game.getPlayers(), players);
}

TEST(gameTest, setConsumerDemandPerWeekTest) {
    std::vector<int> consumerDemandPerWeek (1);
    consumerDemandPerWeek[0] = 42;
    Game game;
    game.setConsumerDemandPerWeek(consumerDemandPerWeek);
    EXPECT_EQ(game.getConsumerDemandPerWeek(), consumerDemandPerWeek);
}

TEST(gameTest, getConsumerDemandPerWeekTest) {
    std::vector<int> consumerDemandPerWeek (2);
    consumerDemandPerWeek[0] = 42;
    consumerDemandPerWeek[1] = 17;
    Game game;
    game.setConsumerDemandPerWeek(consumerDemandPerWeek);
    EXPECT_EQ(game.getConsumerDemandPerWeek(), consumerDemandPerWeek);
}


TEST(gameTest, getOrderDelayTest) {
    Game game;
    game.setOrderDelay(2);
    EXPECT_EQ(game.getOrderDelay(), 2);
}

TEST(gameTest, setShipmentDelayTest) {
    Game game;
    game.setShipmentDelay(3);
    EXPECT_EQ(game.getShipmentDelay(), 3);
}

TEST(gameTest, getShipmentDelayTest) {
    Game game;
    game.setShipmentDelay(2);
    EXPECT_EQ(game.getShipmentDelay(), 2);
}


TEST(gameTest, getHoldingCostTest){
    Game game;
    game.setHoldingCost(0.5);
    EXPECT_EQ(game.getHoldingCost(), 0.5);
}


TEST(gameTest, getBackorderCostTest){
    Game game;
    game.setBackorderCost(1.0);
    EXPECT_EQ(game.getBackorderCost(), 1.0);
}


TEST(gameTest, getStartingInventoryTest){
    Game game;
    game.setStartingInventory(12);
    EXPECT_EQ(game.getStartingInventory(), 12);
}


TEST(gameTest, getWeeksToBePlayedTest) {
    Game game;
    game.setWeeksToBePlayed(26);
    EXPECT_EQ(game.getWeeksToBePlayed(), 26);
}

TEST(gameTest, getCurrentWeekTest) {
    Game game;
    game.setCurrentWeek(17);
    EXPECT_EQ(game.getCurrentWeek(), 17);
}

TEST(gameTest, getInfoCodeTest) {
    Game game;
    EXPECT_EQ(game.getInfoCode(), 0);
}

TEST(gameTest, getFactoryDelayTest) {
    Game game;
    game.setFactoryDelay(1);
    EXPECT_EQ(game.getFactoryDelay(), 1);
}


TEST(gameTest, getNumberOfPlayersTest) {
    Game game;
    game.setNumberOfPlayers(4);
    EXPECT_EQ(game.getNumberOfPlayers(), 4);
}

TEST(gameTest, startGameTest){
    Game game;
    game.startGame();
    EXPECT_EQ(game.getInfoCode(), 1);
}

//In executeOrdersForCurrentWeek, the Order objects in the map ordersToBeExecuted are executed (the method
// executeOrder for each object is called)
TEST(gameTest, executeOrdersForCurrentWeekTest){
    Game game;
    std::vector<Order> orders (1);
    Order order0;
    order0.setNumberOfBeers(1);
    auto* player = new Player;
    player->setInventory(10);
    game.addPlayer(player);
    order0.setReceiver(player);
    orders[0] = order0;
    std::map<int, std::vector<Order>> ordersToBeExecuted;
    ordersToBeExecuted[2] = orders;
    game.setOrdersToBeExecuted(ordersToBeExecuted);
    game.setCurrentWeek(2);
    game.executeOrdersForCurrentWeek();
    EXPECT_EQ(player->getInventory(), 9);
}

//In executeShipmentsForCurrentWeek, the Shipment objects in the map setShipmentsToBeExecuted are executed (the method
// executeShipment for each object is called)
TEST(gameTest, executeShipmentsForCurrentWeekTest){
    Game game;
    std::vector<Shipment> shipments (1);
    Shipment shipment0;
    shipment0.setNumberOfBeers(1);
    auto* player = new Player;
    player->setInventory(10);
    game.addPlayer(player);
    shipment0.setReceiver(player);
    shipments[0] = shipment0;
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;
    shipmentsToBeExecuted[2] = shipments;
    game.setShipmentsToBeExecuted(shipmentsToBeExecuted);
    game.setCurrentWeek(2);
    game.executeShipmentsForCurrentWeek();
    EXPECT_EQ(player->getInventory(), 11);
}

TEST(gameTest, updatePlayerInventoriesTest){
    Game game;
    std::vector<Order> orders (1);
    Order order0;
    order0.setNumberOfBeers(1);
    auto* player0 = new Player;
    player0->setInventory(10);
    game.addPlayer(player0);
    order0.setReceiver(player0);
    orders[0] = order0;
    std::map<int, std::vector<Order>> ordersToBeExecuted;
    ordersToBeExecuted[2] = orders;
    game.setOrdersToBeExecuted(ordersToBeExecuted);
    game.setCurrentWeek(2);

    std::vector<Shipment> shipments (1);
    Shipment shipment0;
    shipment0.setNumberOfBeers(1);
    auto* player1 = new Player;
    player1->setInventory(10);
    game.addPlayer(player1);
    shipment0.setReceiver(player1);
    shipments[0] = shipment0;
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;
    shipmentsToBeExecuted[2] = shipments;
    game.setShipmentsToBeExecuted(shipmentsToBeExecuted);

    game.updatePlayerInventories();

    EXPECT_EQ(player0->getInventory(), 9);
    EXPECT_EQ(player1->getInventory(), 11);
}

TEST(gameTest, getConsumerDemandForWeekTest){
    std::vector<int> consumerDemandPerWeek (3);
    consumerDemandPerWeek[0] = 0;
    consumerDemandPerWeek[1] = 1;
    consumerDemandPerWeek[2] = 2;
    Game game;
    game.setConsumerDemandPerWeek(consumerDemandPerWeek);
    EXPECT_EQ(game.getConsumerDemandForWeek(2), 2);
}


// In addOrder, an object of class Order is created and put into the map setOrdersToBeExecuted
TEST(gameTest, addOrderTest){
    Game game;
    game.setCurrentWeek(2);
    game.addOrder(1, 1);
    game.addOrder(0, 0);
    game.addOrder(2, 2);
    game.addOrder(3, 3);
    std::vector<Order> orders (4);
    Order order0, order1, order2, order3;
    order0.setNumberOfBeers(0);
    order1.setNumberOfBeers(1);
    order2.setNumberOfBeers(2);
    order3.setNumberOfBeers(3);
    orders[0] = order0;
    orders[1] = order1;
    orders[2] = order2;
    orders[3] = order3;
    std::map<int, std::vector<Order>> ordersToBeExecuted = game.getOrdersToBeExecuted();
    EXPECT_EQ(ordersToBeExecuted[2], orders);
}

// In addShipment, an object of class Shipment is created and put into the map setShipmentsToBeExecuted
TEST(gameTest, addShipmentTest){
    Game game;
    game.setCurrentWeek(2);
    game.addShipment(1, 1);
    game.addShipment(0, 0);
    game.addShipment(2, 2);
    game.addShipment(3, 3);
    std::vector<Shipment> shipments (4);
    Shipment shipment0, shipment1, shipment2, shipment3;
    shipment0.setNumberOfBeers(0);
    shipment1.setNumberOfBeers(1);
    shipment2.setNumberOfBeers(2);
    shipment3.setNumberOfBeers(3);
    shipments[0] = shipment0;
    shipments[1] = shipment1;
    shipments[2] = shipment2;
    shipments[3] = shipment3;
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted = game.getShipmentsToBeExecuted();
    EXPECT_EQ(shipmentsToBeExecuted[2], shipments);
}

TEST(gameTest, addPlayerTest){
    std::vector<Player*> players (2);
    auto* player0 = new Player;
    player0->setPId(1);
    auto* player1 = new Player;
    player1->setPId(2);
    players[0] = player0;
    players[1] = player1;
    Game game;
    game.setPlayers(players);
    auto* player2 = new Player;
    game.addPlayer(player2);
    players.push_back(player2);
    EXPECT_EQ(game.getPlayers(), players);
}

TEST(gameTest, getDownstreamTest){
    std::vector<Player*> players (4);
    auto* player0 = new Player;
    player0->setPId(0);
    auto* player1 = new Player;
    player1->setPId(1);
    auto* player2 = new Player;
    player2->setPId(2);
    auto* player3 = new Player;
    player3->setPId(3);
    players[0] = player0;
    players[1] = player1;
    players[2] = player2;
    players[3] = player3;
    Game game;
    game.setPlayers(players);
    EXPECT_EQ(game.getDownstream(2), player3);
}

TEST(gameTest, getUpstreamTest){
    std::vector<Player*> players (4);
    auto* player0 = new Player;
    player0->setPId(0);
    auto* player1 = new Player;
    player1->setPId(1);
    auto* player2 = new Player;
    player2->setPId(2);
    auto* player3 = new Player;
    player3->setPId(3);
    players[0] = player0;
    players[1] = player1;
    players[2] = player2;
    players[3] = player3;
    Game game;
    game.setPlayers(players);
    EXPECT_EQ(game.getUpstream(2), player1);
}

TEST(gameTest, generatePasswordsTest){
    Game game;
    EXPECT_EQ(game.generatePasswords(4).size(), 4);
}
