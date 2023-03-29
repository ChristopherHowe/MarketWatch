#include "stock.h"

#define MAX_STOCKS 100

class Market {
    Stock stocks[MAX_STOCKS];
    int numStocks;

    public:
    Market();
    Market(Stock[], int);

    Stock* getStocks();
    int getNumStocks();
    Stock getStockBySymbol(string);

    void addStock(Stock);
    void updateStocks(Stock[], int);
};