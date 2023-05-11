/*******************************
Author: Christopher Howe
Purpose: API library for hosting, stores a system structure 
which contains pointers to all the system objects so that it can interact with them
not the most elegant solution but it works
********************************/

#ifndef API_H
#define API_H
#include <restbed>
#include <memory>
#include <cstdlib>
#include "appStructs.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;


int hostAPI(System system);
//handlers
void stocks_handler( const shared_ptr< restbed::Session > session );
void user_handler( const shared_ptr< restbed::Session > session );
void purchase_position_handler( const shared_ptr< restbed::Session > session );
//helpers
json userToJson(User* user);
string quickRound(float val, int pres);


#endif
