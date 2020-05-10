#include <Order.h>
#include <Shipment.h>
#include <Game.h>
#include "gtest/gtest.h"
#include "Player.h"

TEST(playerTest, setPIdTest) {
    Player p;
    p.setPId(2);
    EXPECT_EQ(2, p.getPId());
}

TEST(playerTest, getPIdTest) {
    Player p;
    p.setPId(25);
    EXPECT_EQ(25, p.getPId());
}

TEST(playerTest, setRoleTest) {
    Player p;
    p.setRole(1);
    EXPECT_EQ(1, p.getRole());
}

TEST(playerTest, getRoleTest) {
    Player p;
    p.setRole(2);
    EXPECT_EQ(2, p.getRole());
}

TEST(playerTest, getInventoryTest) {
    Player p;
    p.setInventory(10000);
    EXPECT_EQ(10000, p.getInventory());
}

TEST(playerTest, setInventoryTest) {
    Player p;
    p.setInventory(10);
    EXPECT_EQ(10, p.getInventory());
}

TEST(playerTest, getBackorderTest) {
    Player p;
    p.setBackorder(20);
    EXPECT_EQ(20, p.getBackorder());
}

TEST(playerTest, setBackorderTest) {
    Player p;
    p.setBackorder(2);
    EXPECT_EQ(2, p.getBackorder());
}

TEST(playerTest, setIncomingOrderTest) {
    Player p;
    p.setIncomingOrder(2);
    EXPECT_EQ(2, p.getIncomingOrder());
}

TEST(playerTest, getIncomingOrderTest) {
    Player p;
    p.setIncomingOrder(1);
    EXPECT_EQ(1, p.getIncomingOrder());
}

TEST(playerTest, setIncomingShipmentTest) {
    Player p;
    p.setIncomingShipment(2);
    EXPECT_EQ(2, p.getIncomingShipment());
}

TEST(playerTest, getIncomingShipmentTest) {
    Player p;
    p.setIncomingShipment(20);
    EXPECT_EQ(20, p.getIncomingShipment());
}

TEST(playerTest, setOutgoingShipmentTest) {
    Player p;
    p.setOutgoingShipment(20);
    EXPECT_EQ(20, p.getOutgoingShipment());
}

TEST(playerTest, getOutgoingShipmentTest) {
    Player p;
    p.setOutgoingShipment(3);
    EXPECT_EQ(3, p.getOutgoingShipment());
}

TEST(playerTest, getCostTest) {
    Player p;
    p.setCost(30);
    EXPECT_EQ(30, p.getCost());
}

TEST(playerTest, setCostTest) {
    Player p;
    p.setCost(2);
    EXPECT_EQ(2, p.getCost());
}

TEST(playerTest, getTotalCostTest) {
    Player p;
    p.setTotalCost(3.34);
    EXPECT_EQ(3.34, p.getTotalCost());
}

TEST(playerTest, setTotalCostTest) {
    Player p;
    p.setTotalCost(3);
    EXPECT_EQ(3, p.getTotalCost());
}

TEST(playerTest, setDemandTest) {
    Player p;
    p.setDemand(3);
    EXPECT_EQ(3, p.getDemand());
}

TEST(playerTest, getDemandTest) {
    Player p;
    p.setDemand(1);
    EXPECT_EQ(1, p.getDemand());
}

TEST(playerTest, isOrderReceivedTest){
    Player player;
    player.setOrderReceived(true);
    EXPECT_EQ(player.isOrderReceived(), true);
}

TEST(playerTest, setOrderReceivedTest){
    Player player;
    player.setOrderReceived(false);
    EXPECT_EQ(player.isOrderReceived(), false);
}

TEST(playerTest, getShipmentReceivedTest){
    Player player;
    player.setShipmentReceived(true);
    EXPECT_EQ(player.isShipmentReceived(), true);
}

TEST(playerTest, isShipmentReceivedTest){
    Player player;
    player.setShipmentReceived(false);
    EXPECT_EQ(player.isShipmentReceived(), false);
}

TEST(playerTest, setOrderPlacedTest) {
    Player player;
    player.setOrderPlaced(true);
    EXPECT_EQ(player.isOrderPlaced(), true);
}

TEST(playerTest, getOrderPlacedTest) {
    Player player;
    player.setOrderPlaced(false);
    EXPECT_EQ(player.isOrderPlaced(), false);
}

TEST(playerTest, setShipmentPlacedTest) {
    Player player;
    player.setShipmentPlaced(true);
    EXPECT_EQ(player.isShipmentPlaced(), true);
}

TEST(playerTest, isShipmentPlacedTest) {
    Player player;
    player.setShipmentPlaced(false);
    EXPECT_EQ(player.isShipmentPlaced(), false);
}

TEST(playerTest, getGameTest) {
    Player player;
    Game* game = new Game;
    player.setGame(game);
    EXPECT_EQ(player.getGame(), game);
}

TEST(playerTest, setGameTest) {
    Player player;
    Game* game = nullptr;
    player.setGame(game);
    EXPECT_EQ(player.getGame(), game);
}

//placeOrder should call Game's addOrder method
TEST(playerTest, placeOrderTest ) {
    Player player;
    player.setRole(1);
    Game* game = new Game;
    player.setGame(game);
    player.getGame()->setCurrentWeek(1);
    player.placeOrder(42);
    std::map<int, std::vector<Order>> ordersToBeExecuted = player.getGame()->getOrdersToBeExecuted();
    Order order;
    order.setNumberOfBeers(42);
    EXPECT_EQ(ordersToBeExecuted[1][1], order);
}

//placeOrder should call Game's addShipment method
TEST(playerTest, placeShipmentTest) {
    Player player;
    player.setRole(1);
    Game* game = new Game;
    player.setGame(game);
    player.getGame()->setCurrentWeek(1);
    player.placeShipment(42);
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted = player.getGame()->getShipmentsToBeExecuted();
    Shipment shipment;
    shipment.setNumberOfBeers(42);
    EXPECT_EQ(shipmentsToBeExecuted[1][1], shipment);
}

//getAvailableShipment returns the number of beers that are available for shipment to the next Player
TEST(playerTest, getAvailableShipmentTest) {
    Player player;
    player.setInventory(1);
    EXPECT_EQ(player.getAvailableShipment(2), 1);
    player.setInventory(3);
    EXPECT_EQ(player.getAvailableShipment(2), 2);
}

TEST(playerTest, receiveShipmentTest){
    Player player;
    player.setInventory(4);
    player.receiveShipment(6);
    EXPECT_EQ(player.getInventory(), 10);
    player.setInventory(0);
    player.setBackorder(2);
    player.receiveShipment(1);
    EXPECT_EQ(player.getBackorder(), 1);
    player.receiveShipment(2);
    EXPECT_EQ(player.getInventory(), 1);
}

TEST(playerTest, receiveOrderTest){
    Player player;
    player.setInventory(4);
    player.receiveOrder(1);
    EXPECT_EQ(player.getInventory(), 3);
    player.receiveOrder(4);
    EXPECT_EQ(player.getBackorder(), 1);
    player.receiveOrder(1);
    EXPECT_EQ(player.getBackorder(), 2);
}

TEST(playerTest, decreaseInventoryTest ) {
    Player player;
    player.setInventory(10);
    EXPECT_EQ(player.decreaseInventory(1), 9);
}

TEST(playerTest, increaseInventoryTest) {
    Player player;
    player.setInventory(0);
    EXPECT_EQ(player.increaseInventory(2), 2);
}
