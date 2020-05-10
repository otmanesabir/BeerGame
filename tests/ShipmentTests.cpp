#include <Shipment.h>
#include <Player.h>
#include "gtest/gtest.h"

TEST(shipmentTest, executeShipmentTest){
    Shipment shipment;
    shipment.setNumberOfBeers(1);
    auto* player = new Player;
    player->setInventory(10);
    shipment.setReceiver(player);
    shipment.executeShipment();
    EXPECT_EQ(player->getInventory(), 11);
}

