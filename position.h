#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <ctime>
#include "market.h"

using namespace std;

class Position : public Stock {
    float originalPricePerShare;
    float currentPricePerShare;
    float numShares;
    Market* market;
    string symbol;
    string type;
    time_t date;
    
    public:
    Position();
    Position(float, float, Market*, string, string, time_t);

    float getOPPS();
    float getCPPS();
    float getNumShares();
    string getType();
    time_t getDate();

    float getOriginalValue();
    float getValue();

    void setOPPS(float);
    void setCPPS(float);
    void setNumShares(float);
    void setType(string);
    void setDate(time_t);

    friend ostream & operator << (ostream & out, const Position & p);
};

#endif