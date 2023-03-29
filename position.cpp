#include "position.h"

Position::Position(){
    originalPricePerShare = 0;
    numShares = 0;
    symbol = "DEFAULT";
}

Position::Position(float newOPPS, float newCPPS, float newNumShares, string newSymbol, string newType, time_t newDate){
    originalPricePerShare = newOPPS;
    currentPricePerShare = newCPPS;
    numShares = newNumShares;
    symbol = newSymbol;
    type = newType;
    date = newDate;
}

float Position::getOPPS(){
    return originalPricePerShare;
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
    return numShares * currentPricePerShare;
}

void Position::setOPPS(float newOPPS){
    originalPricePerShare = newOPPS;
}
void Position::setCPPS(float newCPPS){
    currentPricePerShare = newCPPS;
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
