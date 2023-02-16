#include "market.h"

Market::Market(){
    numStocks = 0;
}

Market::Market(Stock newStocks[], newNumStocks){
    for(int i = 0; i < newNumStocks; i++){
        stocks[i] = newStocks[i];
    }
    numStocks = newNumStocks;
}

Stock[] Market::getStocks(){
    return stocks;
}

int Market::getNumStocks(){
    return numStocks;
}

Stock Market::getStockBySymbol(string symbol){
    for(int i = 0; i< numStocks; i++){
        if (stocks[i].getSymbol() = symbol){
            return stocks[i];
        }
    }
    throw "stock not found";
}

void Market::addStock(Stock newStock){
    //implimentation not complete yet
    for(int i = 0; i < numStocks; i++){
        if (newStock.getSymbol() = stocks[i].getSymbol()){
            stocks[i].setPrice(newStock.getPrice());
        }
        else(stocks[i].getSymbol() != newStock.getSymbol()){
            stocks[numStocks] = newStock;
            numStocks++;
        }
   }
}

void Market::updateStocks(Stock[] newStocks, int numNewStocks){
    Stock notUpdated[];
    int numNotUpdated;
    for(int i = 0; i < numStocks; i++){
        bool exists;
        for(int x = 0; x < newNumStocks; x++){
            if(stocks[i].getSymbol() == newStocks[x].getSymbol()){
                stocks
            }
        }
}
