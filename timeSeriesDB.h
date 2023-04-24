#ifndef TIME_SERIES_H
#define TIME_SERIES_H
#include "market.h"
#include <ctime>

struct MarketSnapshot{
    Market market;
    time_t timestamp;
};

struct StockSnapshot{
    Stock stock;
    time_t timestamp;
};

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