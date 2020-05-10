#include <iostream>
#include "Exceptions.h"
#include "UniqueID.h"

int UniqueID::nextID = 0;

UniqueID::UniqueID() {
    this->id = ++nextID;
}

UniqueID::UniqueID(bool test) {
    if (test) {
        this->id = nextID;
    } else {
        nextID = 0;
        this->id = -1;
    }
}

UniqueID::UniqueID(const UniqueID &orig) {
    this->id = orig.id;
}

UniqueID &UniqueID::operator=(const UniqueID &orig) {
    this->id = orig.id;
    return (*this);
}

UniqueID &UniqueID::operator=(const int &x) {
    this->id = x;
    return (*this);
}

UniqueID::UniqueID(int nId, bool overwrite) {
    if (overwrite) {
        this->id = nId;
    } else {
        try {
            if (nId <= nextID || nId == -1)
                throw cExceptions();
            else
                this->id = nId;
        } catch (cExceptions &e) {
            throw e.id_error(1);
        }
    }
}

bool UniqueID::operator<(const UniqueID &a) {
    return this->id < a.id;
}

bool UniqueID::operator>(const UniqueID &a) {
    return this->id > a.id;
}

bool UniqueID::operator==(const UniqueID &a) {
    return this->id == a.id;
}

bool UniqueID::operator<=(const UniqueID &a) {
    return this->id <= a.id;
}

bool UniqueID::operator>=(const UniqueID &a) {
    return this->id >= a.id;
}

UniqueID::operator int() const {
    return this->id;
}
