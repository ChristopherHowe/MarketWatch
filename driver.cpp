#include "user.h"
#include "market.h"

void displayStocks();

int main(){
    Stock testMarket[3] = {Stock("XYZ",1.23), Stock("ABC", 12.34), Stock("DEF", 23.45)};
    Stock newMarket[3] = 
    Position testPositions[1] = {Position(11.0, 11.0, 2, "XYZ", "buy", time(NULL))};
    Account testAccounts[1] = {Account(testPositions, 1, 100.00, "John")};
    
    User testUser(testAccounts,1);
    Market market(testMarket, 3);

    cliPurchase(market,testUser);
    market.addStock

    displayStocks();
    return 0;
}
    
void displayStocks(Market market){
    cout<< "available stocks:" << endl;
    for(int i = 0; i < market.getNumStocks(); i++){
        cout << i + 1 << ".  symbol: " << market.getStocks()[i].getSymbol() << " " << "price: " << market.getStocks()[i].getPrice() << endl;
    }
}

void cliPurchase(Market market, User user){
    int choice;
    int shares;
    displayStocks(market);
    cout << "which would you like to purchase?: ";
    cin >> choice;
    cout << "how many shares would you like?: ";
    cin >> shares;
    user.purchasePosition(market.getStocks()[choice - 1], shares);
}