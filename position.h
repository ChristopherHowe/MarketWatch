#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <ctime>
#include "stock.h"

using namespace std;

class Position : public Stock {
    float originalPricePerShare;
    float numShares;
    string type;
    time_t date;
    
    public:
    Position();
    Position(float, float, float, string, string, time_t);

    float getCPPS();
    float getNumShares();
    string getType();
    time_t getDate();

    float getValue();
    float getOriginalValue();

    void setOPPS(float);
    void setNumShares(float);
    void setType(string);
    void getDate(time_t);
}