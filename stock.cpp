#include "stock.h"

Stock::Stock(){
    symbol = "default stock";
    price = 0;
}

Stock::Stock(string newSymbol, float newPrice){
    symbol = newSymbol;
    price = newPrice;
}

string Stock::getSymbol(){
    return symbol;
}

float Stock::getPrice(){
    return price;
}

void Stock::setSymbol(string newSymbol){
    symbol = newSymbol;
}

void Stock::setPrice(float newPrice){
    price = newPrice;
}