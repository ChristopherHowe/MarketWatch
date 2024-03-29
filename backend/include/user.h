/*******************************
Author: Christopher Howe
Purpose: Defines the user class, users are the designed way for
entities to interact with the system.
********************************/

#ifndef USER_H
#define USER_H

#include "account.h"

#define MAX_ACCOUNTS 10


class User {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts;
    int activeAccount;

    void calculateBalance();

    public:
    User();
    User(Account*, int newNumAccounts);

    Account* getAccounts();
    Account getAccount(int);
    Account getActiveAccount();
    int getActiveInd();
    int getNumAccounts();
    float getBalance();
    
    void changeActiveAccount(int accountIndex);
    void addAccount(Account);
    Account removeAccount(int accountIndex);

    bool purchasePosition(Stock, Market*, float numShares, string type);
    float sellPosition(int positionIndex);

    friend ostream & operator << (ostream & out, const User& u);
};

#endif