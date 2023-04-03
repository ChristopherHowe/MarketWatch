#include "user.h"
#include "market.h"

void displayStocks(Market);
void cliPurchase(Market*, User&);

int main(){
    Stock testMarket[3] = {Stock("XYZ",1.23), Stock("ABC", 12.34), Stock("DEF", 23.45)};
    Stock newMarket[3] = {Stock("XYZ",2.34),Stock("ABC",23.45)};
    Market market(testMarket, 3);
    cout << "market: " << &market << endl;
    
    Position testPositions[1] = {Position(testMarket[0], 2.0, &market, "buy", time(NULL))};
    Account testAccounts[1] = {Account(testPositions, 1, 100.00, "John")};
    
    User testUser(testAccounts,1);
    cout << testUser << endl;
    cliPurchase(&market,testUser);
    cout << testUser << endl;
    market.updateStocks(newMarket,2);
    cout << testUser << endl;
    displayStocks(market);
    return 0;
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