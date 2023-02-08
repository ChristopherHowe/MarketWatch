#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <ctime>

using namespace std;

class Position {
    float originalPricePerShare;
    float currentPricePerShare;
    float numShares;
    
    string symbol;
    string type;
    time_t date;
    
    public:
    Position();
    Position(float, float, float, string, string, time_t);

    float getOPPS();
    float getCPPS();
    float getNumShares();
    string getSymbol();
    string getType();
    time_t getDate();

    float getValue();
    float getOriginalValue();

    void setOPPS(float);
    void setCPPS(float);
    void setNumShares(float);
    void getSymbol(string);
    void setType(string);
    void getDate(time_t);
}