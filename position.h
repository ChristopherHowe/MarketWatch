#ifndef POSITION_H
#define POSITION_H

#include <iostream>

using namespace std;

class Position {
    float originalPricePerShare;
    float currentPricePerShare;
    string symbol;

    public:
    Position();
    Position(float, float, string);

    float getOPPS();
    float getCPPS();
    string getSymbol();

    void setOPPS(float);
    void setCPPS(float);
    void getSymbol(string);
}