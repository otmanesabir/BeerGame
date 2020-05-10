#include "gtest/gtest.h"
#include <PlayerEvent.h>
#include <Player.h>

TEST(playerEventTest, getEventIdTest){
    PlayerEvent playerEvent;
    playerEvent.setEventId(1);
    EXPECT_EQ(playerEvent.getEventId(), 1);

}

TEST(playerEventTest, setEventIdTest){
    PlayerEvent playerEvent;
    playerEvent.setEventId(2);
    EXPECT_EQ(playerEvent.getEventId(), 2);
}

TEST(playerEventTest, getGIdTest){
    PlayerEvent playerEvent;
    playerEvent.setGId(1);
    EXPECT_EQ(playerEvent.getGId(), 1);
}

TEST(playerEventTest, setGIdTest){
    PlayerEvent playerEvent;
    playerEvent.setGId(2);
    EXPECT_EQ(playerEvent.getGId(), 2);
}

TEST(playerEventTest, setNumberOfBeersTest){
    PlayerEvent playerEvent;
    playerEvent.setNumberOfBeers(1);
    EXPECT_EQ(playerEvent.getNumberOfBeers(), 1);
}

TEST(playerEventTest, getNumberOfBeersTest){
    PlayerEvent playerEvent;
    playerEvent.setNumberOfBeers(2);
    EXPECT_EQ(playerEvent.getNumberOfBeers(), 2);
}

TEST(playerEventTest, getOrderedInWeekTest){
    PlayerEvent playerEvent;
    playerEvent.setOrderedInWeek(1);
    EXPECT_EQ(playerEvent.getOrderedInWeek(), 1);
}

TEST(playerEventTest, setOrderedInWeekTest){
    PlayerEvent playerEvent;
    playerEvent.setOrderedInWeek(2);
    EXPECT_EQ(playerEvent.getOrderedInWeek(), 2);
}

TEST(playerEventTest, getShippedInWeekTest){
    PlayerEvent playerEvent;
    playerEvent.setShippedInWeek(1);
    EXPECT_EQ(playerEvent.getShippedInWeek(), 1);
}

TEST(playerEventTest, setShippedInWeekTest){
    PlayerEvent playerEvent;
    playerEvent.setShippedInWeek(2);
    EXPECT_EQ(playerEvent.getShippedInWeek(), 2);
}

TEST(playerEventTest, getReceiverTest){
    PlayerEvent playerEvent;
    auto* player = new Player;
    player->setPId(1);
    playerEvent.setReceiver(player);
    EXPECT_EQ(playerEvent.getReceiver(), player);
}

TEST(playerEventTest, setReceiverTest){
    PlayerEvent playerEvent;
    auto* player = new Player;
    player->setPId(2);
    playerEvent.setReceiver(player);
    EXPECT_EQ(playerEvent.getReceiver(), player);
}

TEST(playerEventTest, getToPlayerIdTest){
    PlayerEvent playerEvent;
    playerEvent.setToPlayerId(1);
    EXPECT_EQ(playerEvent.getToPlayerId(), 1);
}

TEST(playerEventTest, setToPlayerIdTest){
    PlayerEvent playerEvent;
    playerEvent.setToPlayerId(2);
    EXPECT_EQ(playerEvent.getToPlayerId(), 2);
}

TEST(playerEventTest, getFromPlayerIdTest){
    PlayerEvent playerEvent;
    playerEvent.setFromPlayerId(1);
    EXPECT_EQ(playerEvent.getFromPlayerId(), 1);
}

TEST(playerEventTest, setFromPlayerIdTest){
    PlayerEvent playerEvent;
    playerEvent.setFromPlayerId(2);
    EXPECT_EQ(playerEvent.getFromPlayerId(), 2);
}