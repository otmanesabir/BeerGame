#include "../include/PlayerEvent.h"
#include "../include/Order.h"
#include "../include/Player.h"

Order::Order() : Order(0, 0, 0, NULL) {}

Order::Order(int eventId, int nBeers, int execInWeek, Player *receiver) :
        PlayerEvent(eventId, nBeers, execInWeek, receiver) {}

void Order::executeOrder() {
    receiver->receiveOrder(numberOfBeers);
}

bool Order::operator==(const Order &a) const {
    return eventId == a.getEventId();
}
