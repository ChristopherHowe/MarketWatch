/*******************************
Author: Christopher Howe
Purpose: Includes implimentation for the user class
********************************/
#include "user.h"

void User::changeActiveAccount(int AccountIndex){
    if (AccountIndex < numAccounts && AccountIndex > 0){
        activeAccount = AccountIndex;
    }
}

bool User::purchasePosition(Stock stock, Market* market, float numShares, string type){
    cout << "called purchase position" << endl;
    Position newPosition(
        stock,
        numShares, 
        market,
        type,
        time(NULL));
    float c = accounts[activeAccount].getCash();
    float p = newPosition.getValue();
    cout << "got position value: " << p << endl;
    if (c >= p){
        accounts[activeAccount].addPosition(newPosition);
        accounts[activeAccount].setCash(c - p);
        cout << "successfully purchased position" << endl;
        return true;
    }
    return false;
} 

float User::sellPosition(int positionIndex){
    float p = accounts[activeAccount].getPositionArray()[positionIndex].getValue();
    float c = accounts[activeAccount].getCash();
    accounts[activeAccount].removePosition(positionIndex);
    accounts[activeAccount].setCash(c + p);
    return p;
}

//constructors
User::User(){
    numAccounts = 1;
    accounts[0] = Account({}, 0, 0, "default owner");
    activeAccount = 0;
}

User::User(Account* newAccounts, int newNumAccounts){
    for(int i = 0; i < newNumAccounts; i++){
        accounts[i] = newAccounts[i];
    }
    numAccounts = newNumAccounts;
    activeAccount = 0;
}

//getters
Account* User::getAccounts(){
    return accounts;
}
Account User::getAccount(int index){
    return accounts[index];
}
int User::getActiveInd(){
    return activeAccount;
}

Account User::getActiveAccount(){
    return accounts[activeAccount];
}

int User::getNumAccounts(){
    return numAccounts;
}

float User::getBalance(){
    float balance=0;
    for(int i = 0; i < numAccounts; i++){
        balance += accounts[i].getAccountValue();
    }
    return balance;
}


void User::addAccount(Account newAccount){
    if(numAccounts < MAX_ACCOUNTS){
        accounts[numAccounts] = newAccount;
        numAccounts++;
        return;
    }
    throw runtime_error("failed to add account, max accounts reached");
}

Account User::removeAccount(int accountIndex){
    if(accountIndex >= numAccounts){
        throw runtime_error("cannot delete this account, excedes available accounts");
    }
    Account accountToDelete = accounts[accountIndex];
    for(int i = accountIndex; i < numAccounts; i++){
        accounts[i] = accounts[i + 1];
    }
    numAccounts--;
    return accountToDelete;
    
}

ostream & operator << (ostream & out, const User & u){
    cout << "here" << endl;
    out << "{\"accounts\": [";
    for(int i =0; i < u.numAccounts; i++){
        cout << u.accounts[i];
    }
    out << "]" << ","  << "}";
    return out;
}

