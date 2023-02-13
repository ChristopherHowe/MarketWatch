#include "user.h"

Position* User::purchasePosition(Stock stock, int numShares, int accountIndex){
    Position newPosition(stock.getPrice(), stock.getPrice(), numShares, stock.getSymbol(), "buy", time(NULL))
    float c = accounts[accountIndex].getCash();
    float p = newPosition.getValue();
    if (c >= p){
        accounts[accountIndex].addPosition(newPosition);
        account[accountIndex].setCash(c - p)
        return &newPosition;
    }
    else{
        return null;
    }
} 

float User::sellPosition(int positionIndex, int accountIndex){
    float p = accounts[accountIndex].getPositionArray()[positionIndex].getValue();
    float c = accounts(accountIndex).getCash();
    accounts[accountIndex].removePosition(positionIndex);
    accounts[accountIndex].setCash(c + p);

}

//constructors
User::User(){
    balance = 0;
    numAccounts = 1;
    accounts[0] = Account({}, 0, 0, "default owner");
}

User::User(Account newAccounts[], int newNumAccounts, float newBalance){
    for(int i = 0; i < newNumAccounts; i++){
        accounts[i] = newAccounts[i];
    }
    numAccounts = newNumAccounts;
    balance = newBalance;
}

//getters
Account[] User::getAccounts(){
    return accounts;
}
Account User::getAccount(int index){
    return accounts[index];
}

int User::getNumAccounts(){
    return numAccounts;
}

float User::getBalance(){
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
