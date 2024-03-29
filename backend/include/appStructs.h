/*******************************
Author: Christopher Howe
Purpose: Contains functions and structures that relatively high level
ie they interact with the structures I have created.
********************************/

#ifndef APP_STRUCTS_H
#define APP_STRUCTS_H

#include "market.h"
#include "user.h"
#include "timeSeriesDB.h"

struct System{
  Market* market;
  TimeDB* timeDB;
  User* users[MAX_USERS];
  int numUsers;
  int activeUser;
};

System fillSystem(Market* market, TimeDB *timeDB, User **userArray, int numUsers, int activeUser);

#endif