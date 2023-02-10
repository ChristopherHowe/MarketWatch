#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "position.h"

#define MAX_POSITIONS 100
 
class Account {
    Position positions[MAX_POSITIONS];
    int numPositions;
    float accountValue;
    float cash;
    string owner;

    void refreshAccount();

    public::   
    //contstructors
    Account();
    Account(Position[],int, float, string);

    //getters
    Position[] getPositionArray();
    int getNumPositions();
    float getAccountValue();
    float getPositionTotal();
    float getOriginalPositionTotal();
    float getCash();
    string getOwner();

    //setters
    void setPositionArray(Position[], int);
    void setOwner(string);
    void setCash(float);

    //position array manipulators
    void addPosition(Position);
    void removePosition(int);
}