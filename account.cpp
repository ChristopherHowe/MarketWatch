#include "account.h"

void Account::refreshAccount(){
    accountValue = getPositionTotal();
}

float Account::getPositionTotal(){
    float total = 0;
    for (int i = 0; i < numPositions; i++){
        total += positions[i].getValue();
    }
    return total;
}

float Account::getOriginalPositionTotal(){
    float total = 0;
    for (int i = 0; i < numPositions; i++){
        total += positions[i].getOriginalValue();
    }
    return total;
}

void Account::addPosition(Position newPosition){
    positions[numPositions] = newPosition;
    numPositions++;
}

void Account::removePosition(int index){
    for(int i = index; i< numPositions; i++){
        positions[i]=positions[i+1];
    }
    numPositions--;
}

//constructors
Account::Account(){
    numPositions = 0;
    cash = 0;
    accountValue = 0;
    owner = "default owner";
}
Account::Account(Position* newArray, int newNum, float newCash, string newOwner){
    for(int i = 0; i< newNum; i++){
        positions[i]=newArray[i];
    }
    numPositions = newNum;
    cash = newCash;
    owner = newOwner;

    refreshAccount();
}

//getters
Position* Account::getPositionArray() {
    return positions;
}
int Account::getNumPositions(){
    return numPositions;
}
float Account::getAccountValue(){
    return accountValue;
}
string Account::getOwner(){
    return owner;
}
float Account::getCash(){
    return cash;
}


//setters
void Account::setPositionArray(Position* newArray, int newNum){
    for (int i = 0; i < newNum; i++){
        positions[i] = newArray[i];
    }
    numPositions = newNum;
    refreshAccount();
}
void Account::setOwner(string newOwner){
    owner = newOwner;
    refreshAccount();
}
void Account::setCash(float newCash){
    cash = newCash;
    refreshAccount();
}