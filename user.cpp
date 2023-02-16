#include "user.h"

void User::setActiveAccount(int AccountIndex){
    if (AccountIndex < numAccounts && AccountIndex > 0){
        activeAccount = AccountIndex;
    }
}

Position* User::purchasePosition(Stock stock, int numShares){
    Position newPosition(stock.getPrice(), stock.getPrice(), numShares, stock.getSymbol(), "buy", time(NULL))
    float c = accounts[activeAccount].getCash();
    float p = newPosition.getValue();
    if (c >= p){
        accounts[activeAccount].addPosition(newPosition);
        account[activeAccount].setCash(c - p)
        return &newPosition;
    }
    else{
        return null;
    }
} 

float User::sellPosition(int positionIndex){
    float p = accounts[activeAccount].getPositionArray()[positionIndex].getValue();
    float c = accounts(activeAccount).getCash();
    accounts[activeACcount].removePosition(positionIndex);
    accounts[activeAccount].setCash(c + p);

}

//constructors
User::User(){
    numAccounts = 1;
    accounts[0] = Account({}, 0, 0, "default owner");
}

User::User(Account newAccounts[], int newNumAccounts, float newBalance){
    for(int i = 0; i < newNumAccounts; i++){
        accounts[i] = newAccounts[i];
    }
    numAccounts = newNumAccounts;
}

//getters
Account[] User::getAccounts(){
    return accounts;
}
Account User::getAccount(int index){
    return accounts[index];
}

Account User::getActiveAccount(){
    return accounts[activeAccount];
}

int User::getNumAccounts(){
    return numAccounts;
}

float User::getBalance(){
    float balance;
    for(int i = 0; i < numAccounts; i++){
        balance += accounts[i].getAccountValue();
    }
    return balance;
}


Account User::addAccount(Account newAccount){
    accounts[numAccounts] = newAccount;
    numAccounts++;
}

Account User::removeAccount(int accountIndex){
    for(int i = index; i < numAccounts; i++){
        accounts[i] = accounts[i + 1]
    }
    numAccounts--;
}
