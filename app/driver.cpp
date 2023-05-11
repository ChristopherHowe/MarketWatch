/*******************************
Author: Christopher Howe
Purpose: entry point for market watch project
********************************/

#include "api.h"
#include <unistd.h>
#include <cstdlib>
#include "library.h"
#include <fstream>


void displayStocks(Market);
void cliPurchase(Market*, User&); // used for testing, allows user to make purchases through the CLI
void displayConfig(ApiConfig config); // displays whatever configuration is loaded (debugging)
void getConfiguration(ApiConfig &config); // loads the environment variables that are required to get market data, 
void getStockData(ApiConfig config, Query query, TimeDB &timeDB, Market &market); // uses a query and gets the time series data from 12-data
Query makeStockQuery(string symbol, int interval /*minutes*/, int numVals); // creates a stock query object used to get time series data from 12-data
void useFakeData(ApiConfig config, Query query, TimeDB &timeDB, Market &market); //loads fake data from a file to avoid using api tokens


int main(){ 
    ApiConfig apiCnfg;
    TimeDB timeDB;
    Market market;

    getConfiguration(apiCnfg);
    displayConfig(apiCnfg); // displays the configuration for debugging
    
    Query query = makeStockQuery("ABC", 15, 30); // determines what data will be queried from 12 data

    getStockData(apiCnfg, query, timeDB, market);
    //useFakeData(apiCnfg, query, timeDB, market); // allows programmer to useFakeData instead of data from the api to preserve credits
    
    Position testPositions[1] = {Position(market.getStock(0), 1, &market,"BUY", time(NULL))};
    Account testAccounts[1] = {Account(testPositions, 1, 1000.00, "John")};
    User testUser(testAccounts,1);
    User* userArray[MAX_USERS] = {&testUser};
    int numUsers = 1;

    System system = fillSystem(&market, &timeDB, userArray, numUsers, 0);
    cout << "hosting MarketWatch API..." << endl; 
    hostAPI(system); // after completing all the setup, starts the API
    
    return 0;
}

// creates a stock query object used to get time series data from 12-data
Query makeStockQuery(string symbol, int interval /*minutes*/, int numVals){
    return Query{
            "/time_series?symbol=" + symbol + 
            ",EUR/USD,IXIC&interval=" + to_string(interval) +
            "min&outputsize=" + to_string(numVals) + 
            "&apikey=",
            symbol,
            numVals
        };
}

// uses a query and gets the time series data from 12-data
void getStockData(ApiConfig config, Query query, TimeDB &timeDB, Market &market){
    cout <<  "called get stock data symbol: " << query.symbol  << endl;
    string url = config.domain + query.queryString + config.key;

    Response res = curlWrap(url);
    json data = json::parse(res.body);
    //cout << data << endl;
    for(int i =query.vals-1; i >= 0; i--){ 
        //cout << "getting price and time" << endl;
        std::string price = data[query.symbol]["values"][i]["close"];
        std::string time_details = data[query.symbol]["values"][i]["datetime"];

        //cout << i   << ". price: " << price << " time: " << data[symbol]["values"][i]["datetime"] << endl;
        
        market.addStock(Stock(query.symbol, stof(price)));
        //cout << "added stock to market: " << market << endl;

        //parsing time string to time
        struct tm tm;
        strptime(time_details.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
        time_t t = mktime(&tm);

        timeDB.addSnapshot(market,t);
    }
    cout <<  "finished loading stock data" << endl;
}

// loads the environment variables that are required to get market data, 
// in the future this may become a yaml file 
void getConfiguration(ApiConfig &config){
    try{
        config.key = getenv("TWELVE_KEY");
        config.domain = getenv("API_DOMAIN");
    }
    catch(runtime_error) {
        throw runtime_error("failed to get environment variables, try running ./env.sh first");
    }
}

// displays whatever configuration is loaded (debugging)
void displayConfig(ApiConfig config){
    cout << "key: " <<config.key << endl;
    cout << "domain: " << config.domain << endl;
}

//displays all stocks available on a market
void displayStocks(Market market){
    cout<< "available stocks:" << endl;
    for(int i = 0; i < market.getNumStocks(); i++){
        cout << i + 1 << ".  symbol: " << market.getStock(i).getSymbol() << " " << "price: " << market.getStock(i).getPrice() << endl;
    }
}

// used for testing, allows user to make purchases through the CLI
void cliPurchase(Market* market, User &user){
    int choice;
    int shares;
    displayStocks(*market);
    cout << "which would you like to purchase?: ";
    cin >> choice;
    cout << "how many shares would you like?: ";
    cin >> shares;
    user.purchasePosition(market->getStock(choice - 1), market, shares,"buy");
}

//loads fake data from a file to avoid using api tokens
void useFakeData(ApiConfig config, Query query, TimeDB &timeDB, Market &market){
    cout <<  "using fake data to preserve credits"  << endl;
    ifstream file;
    file.open("../test.txt");
    json data = json::parse(file);
    //cout << data << endl;
    for(int i =query.vals-1; i >= 0; i--){ 
        //cout << "getting price and time" << endl;
        std::string price = data[query.symbol]["values"][i]["close"];
        std::string time_details = data[query.symbol]["values"][i]["datetime"];

        //cout << i   << ". price: " << price << " time: " << data[symbol]["values"][i]["datetime"] << endl;
        
        market.addStock(Stock(query.symbol, stof(price)));
        //cout << "added stock to market: " << market << endl;

        //parsing time string to time
        struct tm tm;
        strptime(time_details.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
        time_t t = mktime(&tm);

        timeDB.addSnapshot(market,t);
    }
    cout <<  "finished loading fake stock data" << endl;
}