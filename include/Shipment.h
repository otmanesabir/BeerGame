#include "PlayerEvent.h"
#include "Player.h"

#ifndef _SHIPMENT_H
#define _SHIPMENT_H

class Shipment : public PlayerEvent {
public:
    /**
     *\brief default constructor for derived class Shipment
    */
    Shipment();

    Shipment(int, int, int, Player *);

    /**
     *\brief method for executing shipment
    */
    void executeShipment();

    bool operator==(const Shipment& shipment) const;
};

#endif
