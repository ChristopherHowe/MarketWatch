/*******************************
Author: Christopher Howe
Purpose: Defines a simple stock class
********************************/
#ifndef STOCK_H
#define STOCK_H

#include <iostream>

using namespace std;

class Stock {
    protected:
    std::string symbol;
    float price;

    public:
    Stock();
    Stock( std::string, float);

    std::string getSymbol();
    float getPrice();

    void setSymbol(std::string);
    void setPrice(float);
    friend ostream & operator << (ostream & out, const Stock &s);
};
#endif