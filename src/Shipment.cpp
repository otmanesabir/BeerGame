#include "../include/PlayerEvent.h"
#include "../include/Shipment.h"
#include "../include/Player.h"

Shipment::Shipment() : Shipment(0, 0, 0, NULL) {}

Shipment::Shipment(int eventId, int nBeers, int execInWeek, Player *receiver) :
        PlayerEvent(eventId, nBeers, execInWeek, receiver) {}

void Shipment::executeShipment() {
    receiver->receiveShipment(numberOfBeers);
}

bool Shipment::operator==(const Shipment &shipment) const {
    return eventId == shipment.getEventId();
}
