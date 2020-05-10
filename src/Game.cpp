#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#include "Exceptions.h"
#include "Game.h"
#include "Order.h"
#include "Player.h"

using namespace std;

Game::Game() {
    this->gId = UniqueID(-1, true);
    this->instrId = UniqueID(-1, true);
    this->pFactId = UniqueID(-1, true);
    this->pDistributorId = UniqueID(-1, true);
    this->pWholesalerId = UniqueID(-1, true);
    this->pRetailerId = UniqueID(-1, true);
    this->startingInventory = 12;
    this->weeksToBePlayed = 26;
    this->currentWeek = 0;
    this->infoCode = 0;
    this->factoryDelay = 1;
    this->nOrdersReceived = 0;
    this->nShipmentsReceived = 0;
    this->shipmentDelay = 2;
    this->numberOfPlayers = 5;
    this->orderDelay = 2;
    this->holdingCost = 0.5;
    this->backorderCost = 1;
    this->players.reserve(4);
    this->consumerDemandPerWeek.reserve(this->weeksToBePlayed);
}

Game::Game(int ic,
           int gId,
           int instId,
           int pFid,
           int pDid,
           int pWid,
           int pRid,
           int od,
           int si,
           int wtbp,
           int sd,
           int fd,
           double hc,
           double boc) {
    this->gId = UniqueID(gId, true);
    this->instrId = UniqueID(instId, true);
    this->pFactId = UniqueID(pFid, true);
    this->pDistributorId = UniqueID(pDid, true);
    this->pWholesalerId = UniqueID(pWid, true);
    this->pRetailerId = UniqueID(pRid, true);
    this->backorderCost = boc;
    this->startingInventory = si;
    this->weeksToBePlayed = wtbp;
    this->infoCode = ic;
    this->shipmentDelay = sd;
    this->factoryDelay = fd;
    this->orderDelay = od;
    this->holdingCost = hc;
    this->players.reserve(4);
    this->consumerDemandPerWeek.reserve(this->weeksToBePlayed);
}

Game::~Game() {
    this->flushMemory();
}


void Game::setGId(int nId, bool overwrite) {
    this->gId = UniqueID(nId, overwrite);
}

void Game::setGId(UniqueID &id, bool overwrite) {
    this->gId = UniqueID(id, overwrite);
}

void Game::setInstrId(int iId, bool overwrite) {
    this->instrId = UniqueID(iId, overwrite);
}

void Game::setInstrId(UniqueID &id, bool overwrite) {
    this->instrId = UniqueID(id, overwrite);
}

void Game::setPFactId(int nId, bool overwrite) {
    this->pFactId = UniqueID(nId, overwrite);
}

void Game::setPFactId(UniqueID &id, bool overwrite) {
    this->pFactId = UniqueID(id, overwrite);
}

void Game::setPDistributorId(int nId, bool overwrite) {
    this->pDistributorId = UniqueID(nId, overwrite);
}

void Game::setPDistributorId(UniqueID &id, bool overwrite) {
    this->pDistributorId = UniqueID(id, overwrite);
}

void Game::setPWholesalerId(int nId, bool overwrite) {
    this->pWholesalerId = UniqueID(nId, overwrite);
}

void Game::setPWholesalerId(UniqueID &id, bool overwrite) {
    this->pWholesalerId = UniqueID(id, overwrite);
}

void Game::setPRetailerId(int nId, bool overwrite) {
    this->pRetailerId = UniqueID(nId, overwrite);
}

void Game::setPRetailerId(UniqueID &id, bool overwrite) {
    this->pRetailerId = UniqueID(id, overwrite);
}


void Game::setWeeksToBePlayed(int w) {
    try {
        if (w < 0)
            throw cExceptions();
        this->weeksToBePlayed = w;
    } catch (cExceptions &e) {
        throw e.game_class_errors(2);
    }
}

void Game::setInfoCode(int code) {
    try {
        if (code < 0 || floor(log10(code) + 1) < 4)
            throw cExceptions();
        this->infoCode = code;
    } catch (cExceptions &e) {
        if (code < 0)
            throw e.game_class_errors(2);
        else
            throw e.game_class_errors(4);
    }
}

void Game::setStartingInventory(int si) {
    try {
        if (si < 0)
            throw cExceptions();
        this->startingInventory = si;
    } catch (cExceptions &e) {
        throw e.game_class_errors(2);
    }
}

void Game::setBackorderCost(double cost) {
    try {
        if (cost < 0)
            throw cExceptions();
        this->backorderCost = cost;
    } catch (cExceptions &e) {
        throw e.game_class_errors(2);
    }
}

void Game::setHoldingCost(double hc) {
    try {
        if (hc < 0)
            throw cExceptions();
        this->holdingCost = hc;
    } catch (cExceptions &e) {
        throw e.game_class_errors(2);
    }
}

void Game::setFactoryDelay(int fd) {
    try {
        if (fd < 0)
            throw cExceptions();
        this->factoryDelay = fd;
    } catch (cExceptions &e) {
        throw e.game_class_errors(2);
    }
}

void Game::setOrderDelay(int od) {
    try {
        if (od < 0)
            throw cExceptions();
        this->orderDelay = od;
    } catch (cExceptions &e) {
        throw e.game_class_errors(2);
    }
}

void Game::setShipmentDelay(int sd) {
    try {
        if (sd < 0)
            throw cExceptions();
        this->shipmentDelay = sd;
    } catch (cExceptions &e) {
        throw e.game_class_errors(2);
    }
}

void Game::setOrdersToBeExecuted(map<int, vector<Order>> otbe) {
    this->ordersToBeExecuted = std::move(otbe);
}

void Game::setShipmentsToBeExecuted(map<int, vector<Shipment>> stbe) {
    this->shipmentsToBeExecuted = std::move(stbe);
}

void Game::setPlayers(vector<Player *> inPlayers) {
    this->players = std::move(inPlayers);
}

void Game::setConsumerDemandPerWeek(vector<int> cdpw, bool overwrite) {
    try {
        // First make sure we dispose of the old data if we want to overwrite

        if (overwrite){
            try {
                this->clearConsumerDemandPerWeek();
                if (!this->consumerDemandPerWeek.empty())
                    throw cExceptions();
            } catch (cExceptions &e){
                throw e.memory_leaks_error(4);
            }
            this->consumerDemandPerWeek.reserve(cdpw.size());
            this->weeksToBePlayed = cdpw.size();
        }

        // Check for this exception

        if (!overwrite && this->weeksToBePlayed < cdpw.size() + this->consumerDemandPerWeek.size())
            throw cExceptions();
        // if not thrown we can copy
        std::copy(cdpw.begin(), cdpw.end(), back_inserter(this->consumerDemandPerWeek));
        // check that the copy was done successful
        if (overwrite && this->consumerDemandPerWeek != cdpw)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (overwrite)
            throw e.game_class_errors(14);
        else
            throw e.game_class_errors(15);
    }
}

void Game::setNumberOfPlayers(int nop) {
    try {
        if (nop > 4)
            throw cExceptions();
        this->numberOfPlayers = nop;
    } catch (cExceptions &e){
        throw e.game_class_errors(11);
    }

    this->numberOfPlayers = nop;
}

void Game::setCurrentWeek(int week) {
    try {
        if (week > weeksToBePlayed)
            throw cExceptions();
        this->currentWeek = week;
    } catch (cExceptions &e) {
        throw e.weeks_limit_error();
    }
}


int Game::getGId() {
    return this->gId;
}

int Game::getShipmentDelay() {
    return this->shipmentDelay;
}

int Game::getWeeksToBePlayed() {
    return this->weeksToBePlayed;
}

int Game::getInfoCode() {
    return this->infoCode;
}

double Game::getBackorderCost() {
    return this->backorderCost;
}

double Game::getHoldingCost() {
    return this->holdingCost;
}

int Game::getFactoryDelay() {
    return this->factoryDelay;
}

int Game::getOrderDelay() {
    return this->orderDelay;
}

int Game::getStartingInventory() {
    return this->startingInventory;
}

int Game::getCurrentWeek() {
    return this->currentWeek;
}

map<int, vector<Order>> Game::getOrdersToBeExecuted() {
    return ordersToBeExecuted;
}

map<int, vector<Shipment>> Game::getShipmentsToBeExecuted() {
    return shipmentsToBeExecuted;
}

vector<Player *> Game::getPlayers() {
    return this->players;
}

vector<int> Game::getConsumerDemandPerWeek() {
    return this->consumerDemandPerWeek;
}

int Game::getNumberOfPlayers() {
    return this->numberOfPlayers;
}

Player *Game::getDownstream(int role) {
    if (role < 0 || role > 3) {
        throw std::range_error("Value of role out of range [0..3]");
    }
    if (role == 3) {
        return nullptr;
    }
    return players[role+1];
}

Player *Game::getUpstream(int role) {
    if (role < 0 || role > 3) {
        throw std::range_error("Value of role out of range [0..3]");
    }
    if (role == 0) { // factory, no upstream
        return nullptr;
    }
    return players[role-1];}

int Game::getInstrId() {
    return this->instrId;
}

int Game::getPFactId() {
    return this->pFactId;
}

int Game::getPDistributorId() {
    return this->pDistributorId;
}

int Game::getPWholesalerId() {
    return this->pWholesalerId;
}

int Game::getPRetailerId() {
    return this->pRetailerId;
}


vector<string> Game::generatePasswords(int nPwd) {
    std::vector<std::string> passwords;
    passwords.reserve(nPwd);
    for (int i = 0; i < nPwd; i++) {
        static const char alphnum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
        int strLen = sizeof(alphnum) - 1;
        int n = 16;
        int c = 0;
        int s = 0;
        srand(time(nullptr));
        N:
        char C;
        std::string D;
        for (int z = 0; z < n; z++) {
            C = alphnum[rand() % strLen];
            D += C;
            if (isdigit(C)) {
                c++;
            }
            if (C == '!' || C == '@' || C == '$' || C == '%' || C == '^' || C == '&' || C == '*' || C == '#') {
                s++;
            }
        }
        if (n > 2 && (s == 0 || c == 0)) {
            goto N;
        }
        passwords.emplace_back(D);
    }
    return passwords;
};

bool Game::flushMemory() {
    // this makes sure we dont return anything until all memory has been checked.
    // if we add returns to the catch blocks we won't be able to check the ones beneath
    // the one that triggered the return
    bool isPlayersClear = false;
    bool isSTBEClear = false;
    bool isOTBEClear = false;
    bool isCDPWClear = false;

    try {
        this->clearPlayers();
        if (!players.empty())
            throw cExceptions();
        isPlayersClear = true;
    } catch (cExceptions &e) {
        throw e.memory_leaks_error(1);
    }
    try {
        this->clearOrdersToBeExecuted();
        if (!ordersToBeExecuted.empty())
            throw cExceptions();
        isOTBEClear = true;
    } catch (cExceptions &e) {
        throw e.memory_leaks_error(2);
    }
    try {
        this->clearShipmentsToBeExecuted();
        if (!shipmentsToBeExecuted.empty())
            throw cExceptions();
        isSTBEClear = true;
    } catch (cExceptions &e) {
        throw e.memory_leaks_error(3);
    }

    try {
        this->clearConsumerDemandPerWeek();
        if (!consumerDemandPerWeek.empty())
            throw cExceptions();
        isCDPWClear = true;
    } catch (cExceptions &e) {
        throw e.memory_leaks_error(4);
    }
    return (isPlayersClear && isSTBEClear && isOTBEClear && isCDPWClear);
}

void Game::initGame() {
    /*
    //########
    //## Orders and Shipments for week 1
    //########
    // Consumer ----> Retailer
    ordersToBeExecuted[0].push_back(Order(10, 4, 1, getUpstream(CONSUMER)));

    // Consumer <----- Retailer ----> Wholesaler
    ordersToBeExecuted[0].push_back(Order(11, 4, 1, getUpstream(RETAILER)));
    shipmentsToBeExecuted[0].push_back(Shipment(11, 4, 1, getDownstream(RETAILER)));

    // Retailer <----- Wholesaler ----> Distributor
    ordersToBeExecuted[0].push_back(Order(12, 4, 1, getUpstream(WHOLESALER)));
    shipmentsToBeExecuted[0].push_back(Shipment(12, 4, 1, getDownstream(WHOLESALER)));

    // Wholesaler <----- Distributoer ----> Factory
    ordersToBeExecuted[0].push_back(Order(13, 4, 1, getUpstream(DISTRIBUTOR)));
    shipmentsToBeExecuted[0].push_back(Shipment(13, 4, 1, getDownstream(DISTRIBUTOR)));

    // Wholesaler <----- Factory ----> Factory
    shipmentsToBeExecuted[0].push_back(Shipment(14, 4, 1, getUpstream(FACTORY)));
    shipmentsToBeExecuted[0].push_back(Shipment(14, 4, 1, getDownstream(FACTORY)));

    //########
    //## Orders and Shipments for week 2
    //#######

    // Consumer <----- Retailer ----> Wholesaler
    ordersToBeExecuted[1].push_back(Order(21, 4, 1, getUpstream(RETAILER)));
    shipmentsToBeExecuted[1].push_back(Shipment(11, 4, 1, getDownstream(RETAILER)));

    // Retailer <----- Wholesaler ----> Distributor
    ordersToBeExecuted[1].push_back(Order(22, 4, 1, getUpstream(WHOLESALER)));
    shipmentsToBeExecuted[1].push_back(Shipment(12, 4, 1, getDownstream(WHOLESALER)));

    // Wholesaler <----- Distributoer ----> Factory
    ordersToBeExecuted[1].push_back(Order(23, 4, 1, getUpstream(DISTRIBUTOR)));
    shipmentsToBeExecuted[1].push_back(Shipment(13, 4, 1, getDownstream(DISTRIBUTOR)));

    // Wholesaler <----- Factory ----> Factory
    shipmentsToBeExecuted[1].push_back(Shipment(24, 4, 1, getUpstream(FACTORY)));
    shipmentsToBeExecuted[1].push_back(Shipment(24, 4, 1, getDownstream(FACTORY)));
     */
}

void Game::startGame() {
    // start executing orders and shipment for 1st week
    currentWeek++;
    executeOrdersForCurrentWeek();
    executeShipmentsForCurrentWeek();
    infoCode = 1;
}

void Game::executeOrdersForCurrentWeek() {
    if (ordersToBeExecuted.empty()) {
        return;
    }
    if (ordersToBeExecuted.find(currentWeek) == ordersToBeExecuted.end()) {
        // No orders for this week
        return;
    }
    std::vector<Order> orders = ordersToBeExecuted[currentWeek];
    for (Order order: orders) {
        order.executeOrder();
    }
};

void Game::executeShipmentsForCurrentWeek() {
    if (shipmentsToBeExecuted.empty()) {
        return;
    }
    if (shipmentsToBeExecuted.find(currentWeek) == shipmentsToBeExecuted.end()) {
        // No shipments for this week
        return;
    }
    std::vector<Shipment> shipments = shipmentsToBeExecuted[currentWeek];
    for (Shipment shipment: shipments) {
        shipment.executeShipment();
    }
};

int Game::getConsumerOrderForWeek() {
    return this->consumerDemandPerWeek[currentWeek - 1];
}

int Game::advanceWeek() {
    nOrdersReceived = 0;
    nShipmentsReceived = 0;
    try{
        if(this->currentWeek + 1 > weeksToBePlayed){
            throw cExceptions();
        }
        currentWeek++;
        executeOrdersForCurrentWeek();
        executeShipmentsForCurrentWeek();
        return currentWeek;
    } catch (cExceptions &e){
        throw e.weeks_limit_error();
    }
}

void Game::addOrder(const int &role, int numberOfBeers) {
    if (role < 0 || role > 3) {
        throw std::range_error("Value of role out of range [0..3]");
    }
    if (numberOfBeers < 0) {
        throw std::range_error("Value of numberOfBeers out of range [0..inf]");
    }
    Order order;
    order.setNumberOfBeers(numberOfBeers);
    std::vector<Order> orders (4);
    if (ordersToBeExecuted.find(currentWeek) != ordersToBeExecuted.end()) { // found
        orders = ordersToBeExecuted[currentWeek];
    }
    orders[role] = order;
    ordersToBeExecuted[currentWeek] = orders;
}

void Game::addShipment(int role, int numberOfBeers) {
    if (role < 0 || role > 3) {
        throw std::range_error("Value of role out of range [0..3]");
    }
    if (numberOfBeers < 0) {
        throw std::range_error("Value of numberOfBeers out of range [0..inf]");
    }
    Shipment shipment;
    shipment.setNumberOfBeers(numberOfBeers);
    std::vector<Shipment> shipments (4);
    if (shipmentsToBeExecuted.find(currentWeek) != shipmentsToBeExecuted.end()) { // found
        shipments = shipmentsToBeExecuted[currentWeek];
    }
    shipments[role] = shipment;
    shipmentsToBeExecuted[currentWeek] = shipments;
}

void Game::updatePlayerInventories() {
    executeOrdersForCurrentWeek();
    executeShipmentsForCurrentWeek();
}

void Game::addPlayer(Player *player) {
    try {
        if (players.size() > 4)
            throw cExceptions();
        players.push_back(player);
    } catch (cExceptions &e) {
        throw e.game_class_errors(11);
    }
}

bool Game::AssessLogic(bool canBreak) {

    bool flag = true;

    // tests if all ids are correctly set
    try {
        if (this->gId == -1 || this->instrId == -1 || this->pFactId == -1 || this->pDistributorId == -1 ||
            this->pWholesalerId == -1 || this->pRetailerId == -1)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.id_error(3);
        std::cout << e.id_error(3).what();
        flag = false;
    }

    // tests if all ids are unique
    try {
        std::vector<UniqueID> ids;
        ids.reserve(6);
        ids.emplace_back(this->gId);
        ids.emplace_back(this->instrId);
        ids.emplace_back(this->pFactId);
        ids.emplace_back(this->pDistributorId);
        ids.emplace_back(this->pWholesalerId);
        ids.emplace_back(this->pRetailerId);
        auto it = std::unique(ids.begin(), ids.end());
        bool isUnique = (it == ids.end());
        // we can get tid of the vector now.
        ids.clear();
        ids.shrink_to_fit();
        if (!isUnique)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.id_error(1);
        std::cout << e.id_error(1).what();
        return false;
    }

    // checks if starting inventory has a valid value.
    try {
        if (this->startingInventory < 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.id_error(2);
        std::cout << e.game_class_errors(2).what();
        flag = false;
    }

    // checks if weeks to be played has a valid value.
    try {
        if (this->weeksToBePlayed <= 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (this->weeksToBePlayed < 0) {
            if (canBreak)
                throw e.game_class_errors(2);
            std::cout << e.game_class_errors(2).what();
        } else if (this->weeksToBePlayed == 0) {
            if (canBreak)
                throw e.game_class_errors(3);
            std::cout << e.game_class_errors(3).what();
        }
        flag = false;
    }


    try {
        if (this->currentWeek < 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(3);
        std::cout << e.game_class_errors(3).what();
        return false;
    }

    // tests if info code has minimum requirements / is valid.
    try {
        if (this->infoCode < 0 || floor(log10(this->infoCode) + 1) < 4)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (this->infoCode < 0) {
            if (canBreak)
                throw e.game_class_errors(2);
            else
                std::cout << e.game_class_errors(2).what();
        } else {
            if (canBreak)
                throw e.game_class_errors(4);
            else
                std::cout << e.game_class_errors(4).what();
        }
        flag = false;
    }

    // test if order value has a valid value.
    try {
        if (this->orderDelay < 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(2);
        std::cout << e.game_class_errors(2).what();
        flag = false;
    }

    // tests if shipment delay has a valid value.
    try {
        if (this->shipmentDelay < 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(2);
        std::cout << e.game_class_errors(2).what();
        flag = false;
    }

    // tests if factory delay has a valid value.
    try {
        if (this->factoryDelay < 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(2);
        std::cout << e.game_class_errors(2).what();
        flag = false;
    }

    // tests if holding cost has a valid value.
    try {
        if (this->holdingCost < 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(2);
        std::cout << e.game_class_errors(2).what();
        flag = false;
    }

    // tests if backorder cost has a valid value.
    try {
        if (this->backorderCost < 0)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(2);
        std::cout << e.game_class_errors(2).what();
        flag = false;
    }

    // tests if numberOfPlayers matches size of players vector.
    try {
        if (numberOfPlayers < players.size())
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(10);
        std::cout << e.game_class_errors(10).what();
        flag = false;
    }

    // tests if numberOfPlayers exceeds limit.
    try {
        if (numberOfPlayers > 4)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(11);
        std::cout << e.game_class_errors(11).what();
        flag = false;
    }

    // test if player vector exceeds limit.
    try {
        if (this->players.size() > 4)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(11);
        std::cout << e.game_class_errors(11).what();
        flag = false;
    }

    // test if IDs are matching.
    try {
        std::vector<UniqueID> ids;
        ids.reserve(4);
        ids.emplace_back(pFactId);
        ids.emplace_back(pDistributorId);
        ids.emplace_back(pWholesalerId);
        ids.emplace_back(pRetailerId);

        std::vector<UniqueID> idsFromP;
        idsFromP.reserve(4);
        idsFromP.emplace_back(players[0]->getPId());
        idsFromP.emplace_back(players[1]->getPId());
        idsFromP.emplace_back(players[2]->getPId());
        idsFromP.emplace_back(players[3]->getPId());

        std::sort(ids.begin(), ids.end());
        std::sort(idsFromP.begin(), idsFromP.end());

        if (ids != idsFromP)
            throw cExceptions();
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(13);
        std::cout << e.game_class_errors(13).what();
        flag = false;
    }

    // test if any consumer demand has invalid value.
    try {
        for (const auto &t : consumerDemandPerWeek) {
            if (t < 0)
                throw cExceptions();
        }
    } catch (cExceptions &e) {
        if (canBreak)
            throw e.game_class_errors(2);
        std::cout << e.game_class_errors(2).what();
        flag = false;
    }
    return flag;
}

void Game::clearConsumerDemandPerWeek() {
    this->consumerDemandPerWeek.clear();
    this->consumerDemandPerWeek.shrink_to_fit();
}

void Game::clearPlayers() {
    this->players.clear();
    this->players.shrink_to_fit();
}

void Game::clearOrdersToBeExecuted() {
    this->ordersToBeExecuted.clear();
}

void Game::clearShipmentsToBeExecuted() {
    this->shipmentsToBeExecuted.clear();
}

int Game::getConsumerDemandForWeek(int week) {
    if (week < 0 || week >= consumerDemandPerWeek.size()) {
        throw std::range_error("Value of week out of range [0..consumerDemandPerWeek.size()-1]");
    }
    return consumerDemandPerWeek[week];
}

bool Game::operator==(const Game &rhs) const {
    return gId == rhs.gId;
}
