#include "account.h"

void Account::refreshAccount(){
    return;
}

float Account::getPositionTotal(){
    float total = 0;
    for (int i = 0; i < numPositions; i++){
        total += positions[i].getValue();
        //cout << i<< ". value: " << positions[i].getValue() << endl;
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
    refreshAccount();
}

void Account::removePosition(int index){
    for(int i = index; i< numPositions; i++){
        positions[i]=positions[i+1];
    }
    numPositions--;
    refreshAccount();
}

//constructors
Account::Account(){
    numPositions = 0;
    cash = 0;
    owner = "default owner";
}
Account::Account(Position* newArray, int newNum, float newCash, string newOwner){
    for(int i = 0; i< newNum; i++){
        positions[i] = newArray[i];
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
    return getPositionTotal() + cash;
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