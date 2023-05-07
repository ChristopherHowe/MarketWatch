#include "api.h"
#include <unistd.h>
#include <cstdlib>
#include "library.h"
#include "json.hpp"
#include <fstream>




using json = nlohmann::json;



void displayStocks(Market);
void cliPurchase(Market*, User&);
void dispayConfig(ApiConfig config);
void getConfiguration(ApiConfig &config);
void getStockData(ApiConfig config, Query query, TimeDB &timeDB, Market &market);
Query makeStockQuery(string symbol, int interval /*minutes*/, int numVals);
void useFakeData(ApiConfig config, Query query, TimeDB &timeDB, Market &market);




int main(){ 
    
     
    ApiConfig apiCnfg;

    TimeDB timeDB;
    Market market;

    Position testPositions[0] = {};
    Account testAccounts[1] = {Account(testPositions, 0, 1000.00, "John")};
    User testUser(testAccounts,1);
    User* userArray[MAX_USERS] = {&testUser};
    int numUsers = 1;

    System system = fillSystem(&market, &timeDB, userArray, numUsers 0);

    

    getConfiguration(apiCnfg);
    cout << "started main" << endl;

    //displayConfig(apiCnfg);
    Query query = makeStockQuery("ABC", 15, 30);
    //getStockData(apiCnfg, query, timeDB, market);
    useFakeData(apiCnfg, query, timeDB, market);

    vector<StockSnapshot> stockHistory = timeDB.getStockRecord(timeDB.getFirstTime(), timeDB.getLastTime(), "ABC");
    //displayStockRecord(stockHistory);
    //displayStockRecTimes(stockHistory);
    hostAPI(system);
    
    market.updateStocks(timeDB.getAllSnapshots()[0].market);
    cout << "updated market to 0" << endl;

    
    cliPurchase(&market,testUser);
    
    market.updateStocks(timeDB.getAllSnapshots()[10].market);
    displayStocks(market);
    
    return 0;
}

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

void getConfiguration(ApiConfig &config){
    try{
        config.key = getenv("TWELVE_KEY");
        config.domain = getenv("API_DOMAIN");
    }
    catch(runtime_error) {
        throw runtime_error("failed to get environment variables, try running ./env.sh first");
    }
}

void displayConfig(ApiConfig config){
    cout << "key: " <<config.key << endl;
    cout << "domain: " << config.domain << endl;
}

void displayStocks(Market market){
    cout<< "available stocks:" << endl;
    for(int i = 0; i < market.getNumStocks(); i++){
        cout << i + 1 << ".  symbol: " << market.getStocks()[i].getSymbol() << " " << "price: " << market.getStocks()[i].getPrice() << endl;
    }
}

void cliPurchase(Market* market, User &user){
    int choice;
    int shares;
    displayStocks(*market);
    cout << "which would you like to purchase?: ";
    cin >> choice;
    cout << "how many shares would you like?: ";
    cin >> shares;
    user.purchasePosition(market->getStocks()[choice - 1], market, shares);
}

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