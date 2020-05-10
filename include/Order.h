#ifndef ORDER_H
#define ORDER_H


#include "Player.h"

class Player;

/**
 * @brief This class handles an order in regards to the receiver and the number of beers ordered
*/


class Order : public PlayerEvent {
public:
    /**
     *\brief default constructor for derived class Order
    */
    Order();

    Order(int, int, int, Player *);

    /**
     *\brief method for executing Order
    */
    void executeOrder();
    bool operator==(const Order &) const;
};


#endif //ORDER_H
