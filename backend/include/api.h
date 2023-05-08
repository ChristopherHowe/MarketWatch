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
void stocks_handler( const shared_ptr< restbed::Session > session );
void user_handler( const shared_ptr< restbed::Session > session );


#endif
