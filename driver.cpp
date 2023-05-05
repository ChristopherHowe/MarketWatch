#include "user.h"
#include "market.h"
#include "timeSeriesDB.h"
#include <unistd.h>
#include <curl/curl.h>
#include <cstdlib>
#include "libstructs.h"

void displayStocks(Market);
void cliPurchase(Market*, User&);
void getApiData(ApiConfig config);
void getConfiguration(ApiConfig &config);
void getStockData(ApiConfig config, string symbol, int interval /*seconds*/);

int main(){
    CURL *curl;
    CURLcode res;
    ApiConfig apiCnfg;
    getConfiguration(apiCnfg);

    struct MemoryStruct chunk;
 
    chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
    chunk.size = 0;    /* no data at this point */

    getApiData(apiCnfg);
    getStockData(apiCnfg, "ABC", 5);


    throw runtime_error("done");
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }


    /*
    TimeDB timeDB;
    Stock testMarket[3] = {Stock("XYZ",1.23), Stock("ABC", 12.34), Stock("DEF", 23.45)};
    Stock newMarket[3] = {Stock("XYZ",2.34),Stock("ABC",23.45)};
    Stock B[3] = {Stock("XYZ",111)};
    Stock C[3] = {Stock("XYZ",222)};
    Stock D[3] = {Stock("XYZ",333)};

    Market market(testMarket, 3);
    timeDB.addSnapshot(market,time(NULL));
    sleep(1);
    market.updateStocks(newMarket,2);
    timeDB.addSnapshot(market,time(NULL));
    sleep(1);
    market.updateStocks(B,1);
    timeDB.addSnapshot(market,time(NULL));
    sleep(1);
    market.updateStocks(C,1);
    timeDB.addSnapshot(market,time(NULL));
    sleep(1);
    market.updateStocks(D,1);
    timeDB.addSnapshot(market,time(NULL));
    vector<StockSnapshot> stockHistory = timeDB.getStockRecord(timeDB.getFirstTime()+1, timeDB.getLastTime()-1, "XYZ");
    */

    /*cout << "market: " << &market << endl;
    
    Position testPositions[1] = {Position(testMarket[0], 2.0, &market, "buy", time(NULL))};
    Account testAccounts[1] = {Account(testPositions, 1, 100.00, "John")};
    
    User testUser(testAccounts,1);
    cliPurchase(&market,testUser);
    market.updateStocks(newMarket,2);
    displayStocks(market);
    return 0;*/
}


void getStockData(ApiConfig config, string symbol, int interval /*minutes*/){
    CURL *curl;
    CURLcode res;
    string url = config.domain + "/time_series?symbol=" + symbol + ",EUR/USD,IXIC&interval=" + to_string(interval) + "min&apikey=" + config.key;
    cout << "url: " << url << endl;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        res = curl_easy_perform(curl);
        cout <<  "res: " << res << endl;
        curl_easy_cleanup(curl);
    }
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



void getApiData(ApiConfig config){
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