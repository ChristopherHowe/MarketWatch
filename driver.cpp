#include "user.h"
#include "market.h"

void displayStocks();

int main(){
    Stock testMarket[3] = {Stock("XYZ",1.23), Stock("ABC", 12.34), Stock("DEF", 23.45)};
    Position testPositions[1] = {Position(11.0, 11.0, 2, "XYZ", "buy", time(NULL))};
    Account testAccounts[1] = {Account(testPositions,1,100.00,"John")};
    
    User testUser(testAccounts,1);
    Market market(testMarket, 3);

    testUser.purchasePosition()

    displayStocks();
    return 0;
}
    
void displayStocks(){
    cout<< "available stocks:" << endl;
    for(int i = 0; i < market.getNumStocks(); i++){
        cout << "symbol: " << market.getStocks()[i].getSymbol() << endl;
    }
}