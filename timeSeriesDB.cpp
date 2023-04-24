#include "timeSeriesDB.h"

TimeDB::TimeDB(){

}

Market TimeDB::getLatestmarket(){
    return marketSnaps.back();
}

vector<MarketSnapshot> TimeDB::getAllSnapshots(){
    vector<MarketSnapshot> result;
    for(int i = 0; i < snapTimes.size(); i++){
        MarketSnapshot newEntry = {
            marketSnaps[i],
            snapTimes[i]
        };
    }
    return result;
}
vector<StockSnapshot> TimeDB::getStockRecord(time_t start, time_t end, string symbol){
    int startInd = 0, endInd = snapTimes.size();
    for(int i = 0; i < snapTimes.size(); i++){
        if(snapTimes[i] == start){
            startInd = i;
        }
        if(snapTimes[i] == end){
            endInd = i;
        }
        if(startInd > endInd){
            throw runtime_error("start index is after the end index");
        }
    }
    vector<StockSnapshot> result;
    for(int i=startInd; i < endInd; i++){
        StockSnapshot newEntry= {
            marketSnaps[i].getStockBySymbol(symbol),
            snapTimes[i]
        };
        result.push_back(newEntry);
    }
    return result;
}
time_t TimeDB::getFirstTime(){
    return snapTimes.front();
}
time_t TimeDB::getLastTime(){
    return snapTimes.back();
}

bool TimeDB::addSnapshot(Market market, time_t time){
    if(snapTimes.size() > 0){
        if(time < snapTimes.back()){
            throw runtime_error("while adding snapshot snap time is less than last time");
        }
    }
    marketSnaps.push_back(market);
    snapTimes.push_back(time);
    return true;
}