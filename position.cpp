import "position.h"

Position::Position(){
    originalPricePerShare = 0;
    currentPricePerShare = 0;
    symbol = "DEFAULT"
}

Position::Position(float newOPPS, float newCPPS, string newSymbol){
    originalPricePerShare = newOPPS;
    currentPricePerShare = newCPPS;
    symbol = newSymbol    
}

float Position::getOPPS(){
    return originalPricePerShare;
}

float Position::getCPPS(){
    return currentPricePerShare;
}

string Position::getSymbol(){
    return symbol;
}

void Position::setOPPS(float newOPPS){
    originalPricePerShare = newOPPS;
}

void Position::setCPPS(float newCPPS){
    currentPricePerShare = newCPPS;
}

void Position::setSymbol(string newSymbol){
    symbol = newSymbol;
}

