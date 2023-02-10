import "stock.h"

#define MAX_STOCKS 100

class Market {
    Stock stocks[MAX_STOCKS];
    int numStocks;

    public:
    Market();
    Market(Stock[], int);

    Stock[] getStocks();
    Stock getStockBySymbol(string)

    void addStock(Stock);
    void addStocks(Stock[], int);


}