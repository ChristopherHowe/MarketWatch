import "market.h"

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

Stock Market::getStockBySymbol(string symbol){
    for(int i = 0; i< numStocks; i++){
        if (stocks[i].getSymbol() = symbol){
            return stocks[i];
        }
    }
    throw("stock not found");
}

void Market::addStock(Stock newStock){
    //implimentation not complete yet
    for(int i = 0; i < numStocks; i++){
        if (newStock.getSymbol() = stocks[i].getSymbol()){
            stocks[i].setPrice(newStock.getPrice());
        }
        if(stocks[i].getSymbol() < newStock.getSymbol()){
            continue
        }
        else{
            
        }
   }
}


