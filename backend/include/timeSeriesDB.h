#ifndef TIME_SERIES_H
#define TIME_SERIES_H
#include "market.h"
#include <ctime>
#include "library.h"

struct MarketSnapshot{
    Market market;
    time_t timestamp;
};

struct StockSnapshot{
    Stock stock;
    time_t timestamp;
    friend ostream & operator << (ostream & out, const StockSnapshot& s);
};

void displayStockRecord(vector<StockSnapshot> v);
void displayStockRecTimes(vector<StockSnapshot> v);

class TimeDB{
    vector<Market> marketSnaps;
    vector<time_t> snapTimes;
    
    public:
    TimeDB();
    Market getLatestmarket();
    vector<MarketSnapshot> getAllSnapshots();
    vector<StockSnapshot> getStockRecord(time_t start, time_t end, string symbol);
    time_t getFirstTime();
    time_t getLastTime();
    bool isEmpty();

    bool addSnapshot(Market, time_t);

};
#endif