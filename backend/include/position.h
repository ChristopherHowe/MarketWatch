/*******************************
Author: Christopher Howe
Purpose: Defines a position class which should essentially be
essentailly everything you need for basic position transactions
********************************/

#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <ctime>
#include "market.h"


class Position : public Stock {
    float originalPricePerShare;
    float numShares;
    Market* market;
    string type;
    time_t date;
    
    public:
    Position();
    Position(Stock, float, Market*, string, time_t);

    float getCPPS();
    float getOPPS();
    float getNumShares();
    string getType();
    time_t getDate();

    float getOriginalValue();
    float getValue();

    void setOPPS(float);
    void setNumShares(float);
    void setType(string);
    void setDate(time_t);
};

#endif