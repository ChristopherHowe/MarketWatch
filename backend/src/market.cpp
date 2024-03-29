/*******************************
Author: Christopher Howe
Purpose: Includes implimentation for the market class
********************************/
#include "market.h"

Market::Market(){
    numStocks = 0;
}

Market::Market(Stock newStocks[], int newNumStocks){
    for(int i = 0; i < newNumStocks; i++){
        stocks.push_back(newStocks[i]);
    }
    numStocks = newNumStocks;
}

Stock Market::getStock(int index){
    if(index >= numStocks){
        throw runtime_error("index provided in get stock is higher than available index");
    }
    return stocks[index];
}

int Market::getNumStocks(){
    return numStocks;
}

Stock Market::getStockBySymbol(string symbol){
    for(int i = 0; i< numStocks; i++){
        if (stocks[i].getSymbol() == symbol){
            return stocks[i];
        }
    }
    throw runtime_error("stock not found");
}

void Market::addStock(Stock newStock){
    //implimentation not complete yet
    for(int i = 0; i < numStocks; i++){
        if (newStock.getSymbol() == stocks[i].getSymbol()){
            stocks[i].setPrice(newStock.getPrice());
            return;
        }
    }
    stocks.push_back(newStock);
    numStocks++;
}

void Market::updateStocks(const Market &rhs){
    stocks = rhs.stocks;
    numStocks = rhs.numStocks;
}

void Market::updateStocks(Stock* newStocks, int newNumStocks){
    vector<Stock> notUpdated = stocks;
    int numNotUpdated;
    for(int i = 0; i < newNumStocks; i++){
        bool found = false;
        for(int x = 0; x < numStocks; x++){
            if(stocks[x].getSymbol() == newStocks[i].getSymbol()){
                stocks[x].setPrice(newStocks[i].getPrice());
                
                //remove from notupdated need for loop since tryna find symbol FIX LATER
                for(int z=0;z<notUpdated.size();z++){
                    if(notUpdated[z].getSymbol()==stocks[x].getSymbol()){
                        notUpdated.erase(notUpdated.begin()+z);
                        break;
                    }
                }
                found = true;
                break;
            }  
        }
        if(!found){
            stocks.push_back(newStocks[i]);
            numStocks++;
        } 
    }
    for(int i = 0; i < notUpdated.size(); i++){
        for(int x = 0; x < numStocks; x++){
            if(stocks[x].getSymbol() == notUpdated[i].getSymbol()){
                stocks.erase(stocks.begin() + x);
                numStocks--;
            }
        }
    }
}

ostream & operator << (ostream &out, const Market &market){
    out << "{\"stocks\": ";
    for(int x = 0; x < market.numStocks; x++){
        out << market.stocks[x];
    }
    return out;
}