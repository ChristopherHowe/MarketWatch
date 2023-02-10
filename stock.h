#ifndef STOCK_H
#define STOCK_H

import <iostream>

using namespace std

class Stock {
    protected:
    string symbol;
    float price;

    public:
    Stock();
    Stock(string, float);

    string getSymbol();
    float getPrice();

    void setSymbol(string);
    void setPrice(float);
}
#endif