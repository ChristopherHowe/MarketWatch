/*******************************
Author: Christopher Howe
Purpose: Defines the market class, a market is a snapshot of time of the market.
in the future this solution might change.
********************************/

#ifndef MARKET_H
#define MARKET_H

#include "stock.h"
#include <vector>
#define MAX_STOCKS 100

class Market {
    vector<Stock> stocks;
    int numStocks;

    public:
    Market();
    Market(Stock[], int);

    Stock getStock(int index);
    int getNumStocks();
    Stock getStockBySymbol(string);

    void addStock(Stock);
    void updateStocks(Stock[], int);
    void updateStocks(const Market &rhs);

    friend ostream & operator << (ostream &, const Market &);
};

#endif