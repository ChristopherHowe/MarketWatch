#include "position.h"

Position::Position(){
    originalPricePerShare = 0;
    numShares = 0;
    symbol = "DEFAULT";
    type = "default";
    date = time_t();
}

Position::Position(float newOPPS, float newNumShares, Market* newMarket, string newSymbol, string newType, time_t newDate){
    originalPricePerShare = newOPPS;
    numShares = newNumShares;
    market = newMarket;
    symbol = newSymbol;
    type = newType;
    date = newDate;
    //cout << "in position constructor: market: " << market << endl;
}

float Position::getOPPS(){
    return originalPricePerShare;
}
float Position::getCPPS(){
    //cout << "market: " << market << endl;
    return market->getStockBySymbol(symbol).getPrice();
}


float Position::getNumShares(){
    return numShares;
}

string Position::getType(){
    return type;
}

time_t Position::getDate(){
    return date;
}

float Position::getOriginalValue(){
    return numShares * originalPricePerShare;
}

float Position::getValue(){
    //cout << "calling getValue" << endl;
    return numShares * getCPPS();
}

void Position::setOPPS(float newOPPS){
    originalPricePerShare = newOPPS;
}

void Position::setNumShares(float newNumShares) {
    numShares = newNumShares;
}
void Position::setType(string newType){
    type = newType;
}
void Position::setDate(time_t newDate){
    date = newDate;
}
