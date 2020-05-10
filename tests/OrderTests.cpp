#include <Order.h>
#include <Player.h>
#include "gtest/gtest.h"

TEST(orderTest, executeOrderTest){
    Order order;
    order.setNumberOfBeers(1);
    auto* player = new Player;
    player->setInventory(10);
    order.setReceiver(player);
    order.executeOrder();
    EXPECT_EQ(player->getInventory(), 9);
}
