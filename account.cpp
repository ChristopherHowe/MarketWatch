#include "account.h"

void Account::refreshAccount(){
    
}

float Account::getPositionTotal(){
    float total = 0;
    for (int i = 0; i < numPositions; i++)
}

float Account::getOriginalPositionTotal(){

}

Account::Account(){
    numPositions = 0;
    cash = 0;
    accountValue = 0;
    owner = "default owner";
}
Account::Account(Position[] newArray, int newNum, float newCash string newOwner){
    for(int i = 0; i< newNum; i++){
        positions[i]=newArray[i];
    }
    numPositions = newNum;
    cash = newCash;
    owner = newOwner;

    refreshAccount();
}

//getters
Position Account::getPositionArray() {
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
string Account::getCash(){
    return cash;
}


//setters
void Account::setPositionArray(Position[] newArray, int newNum){
    for (int i = 0; i < newNum; i++){
        positions[i] = newArray[i];
    }
    numPositions = newNum;
}
void Account::setOwner(string newOwner) : owner(newOwner);
void Account::setCash(float newCash) : cash(newCash);