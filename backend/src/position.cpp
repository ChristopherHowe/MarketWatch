/*******************************
Author: Christopher Howe
Purpose: Includes implimentation for the position class
********************************/
#include "position.h"

Position::Position(){
    originalPricePerShare = 0;
    numShares = 0;
    type = "default";
    date = time_t();
}

Position::Position(Stock newStock, float newNumShares, Market* newMarket, string newType, time_t newDate){
    cout << "calling pos const" << endl;
    symbol = newStock.getSymbol();
    numShares = newNumShares;
    market = newMarket;
    price = getCPPS();
    originalPricePerShare = price;
    type = newType;
    date = newDate;
    cout << "finished pos const" << endl;
}

float Position::getOPPS(){
    return originalPricePerShare;
}
float Position::getCPPS(){
    price = market->getStockBySymbol(symbol).getPrice();
    return price;
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

//don't want to use this since position updates its value based on market and calls to getCPPS
//needs a little more work
/*ostream & operator << (ostream & out, const Position& p){
    out << "{\"symbol\": " << p.symbol
        << ", \"CPPS\": " << p.
        << ", \"OPPS\": " << p.originalPricePerShare 
        << ", \"numShares\": " << p.numShares
        << "}";
    return out;
}*/