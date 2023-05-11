/*******************************
Author: Christopher Howe
Purpose: Includes implimentation for the TimeDB class
********************************/
#include "timeSeriesDB.h"

TimeDB::TimeDB(){

}

Market TimeDB::getLatestmarket(){
    return marketSnaps.back();
}

vector<MarketSnapshot> TimeDB::getAllSnapshots(){
    if(snapTimes.size() == 0){
        throw runtime_error("cannot get snapshots, DB is empty");
    }
    vector<MarketSnapshot> result;
    for(int i = 0; i < snapTimes.size(); i++){
        MarketSnapshot newEntry = {
            marketSnaps[i],
            snapTimes[i]
        };
        result.push_back(newEntry);
    }
    return result;
}
vector<StockSnapshot> TimeDB::getStockRecord(time_t start, time_t end, string symbol){
    int startInd = -1, endInd = -1;
    for(int i = 0; i < snapTimes.size(); i++){
        if(snapTimes[i] == start){
            startInd = i;
        }
        if(snapTimes[i] == end){
            endInd = i;
        }
    }
    if(startInd == -1){
        throw runtime_error("failed to find specified start time");
    }
    if(endInd == -1){
        throw runtime_error("failed to find specified end time");
    }
    if(startInd > endInd){
        throw runtime_error("start index is after the end index");
    }
    vector<StockSnapshot> result;
    for(int i = startInd; i <= endInd; i++){
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
    string timeString = time_tToStr(time);
    if(snapTimes.size() > 0){
        if(time < snapTimes.back()){
            throw runtime_error("while adding snapshot snap time is less than last time");
        }
    }
    marketSnaps.push_back(market);
    snapTimes.push_back(time);
    return true;
}

bool TimeDB::isEmpty(){
    return snapTimes.size() == 0;
}


ostream & operator << (ostream & out, const StockSnapshot& s){
    out << "{" << s.stock << ", \"time\": " << time_tToStr(s.timestamp) << "}";
    return out;
}

void displayStockRecord(vector<StockSnapshot> v){
    cout << v[0].stock.getSymbol() << " History: " << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<  ", ";
    }
    cout << endl;
}

void displayStockRecTimes(vector<StockSnapshot> v){
    cout << v[0].stock.getSymbol() << " History: " << endl;
    for(int i = 0; i < v.size(); i++){
        cout << time_tToStr(v[i].timestamp) << endl;
    }
    cout << endl;

}