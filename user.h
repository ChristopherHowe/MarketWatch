#ifndef USER_H
#define USER_H

#include "account.h"


class User {
    Account accounts[];
    int numAccounts;
    float balance;

    void calculateBalance();

    public:
    User();
    User(Account[], int newNumAccounts);

    Account[] getAccounts();
    Account[] getAccount(int);
    int getNumAccounts();
    float getBalance();
    
    Account addAccount(Account);
    Account removeAccount(int accountIndex);

    Position* purchasePosition(Stock,int numShares, int accountIndex);
    float sellPosition(int positionIndex, int accountIndex);
}

#endif