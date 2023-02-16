#ifndef USER_H
#define USER_H

#include "account.h"


class User {
    Account accounts[];
    int numAccounts;
    int activeAccount;

    void calculateBalance();

    public:
    User();
    User(Account[], int newNumAccounts);

    Account[] getAccounts();
    Account getAccount(int);
    Account getActiveAccount();
    int getNumAccounts();
    float getBalance();
    
    void changeActiveAccount(int accountIndex);
    Account addAccount(Account);
    Account removeAccount(int accountIndex);

    Position* purchasePosition(Stock, int numShares);
    float sellPosition(int positionIndex);
}

#endif