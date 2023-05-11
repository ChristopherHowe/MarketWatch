/*******************************
Author: Christopher Howe
Purpose: Includes implimentation for the stock class
********************************/
#include "stock.h"

ostream & operator << (ostream & out, const Stock &s){
    out << "{\"symbol\": " << s.symbol << " \"price\": " << s.price << "}";
    return out;
}

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