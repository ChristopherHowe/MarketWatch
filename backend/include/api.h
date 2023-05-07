#ifndef API_H
#define API_H
#include <restbed>
#include <memory>
#include <cstdlib>
#include "appStructs.h"

using namespace std;


int hostAPI(System system);
void get_method_handler( const shared_ptr< restbed::Session > session );
#endif
