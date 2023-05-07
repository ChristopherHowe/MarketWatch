#include "api.h"

System globSystem;

void stocks_handler( const shared_ptr< restbed::Session > session )
{
    Market* market = globSystem.market;
    stringstream out;
    out<< "{\"available stocks\" : [";
    for(int i = 0; i < market->getNumStocks(); i++){
        out << "{\"symbol\": \"" << market->getStocks()[i].getSymbol() << "\" " << "\"price\": " << market->getStocks()[i].getPrice() << "},";
    }
    out << "]}";
    session->close( restbed::OK, out.str().c_str(), { { "Content-Length", to_string(strlen(out.str().c_str())) } } );
}

void user_handler( const shared_ptr< restbed::Session > session )
{
    User* user = globSystem.users[globSystem.activeUser];
}


int hostAPI(System paramSystem)
{
    globSystem = paramSystem;
    auto resource = make_shared< restbed::Resource >( );
    resource->set_path( "/stocks" );
    resource->set_method_handler( "GET", stocks_handler );
    
    auto settings = make_shared< restbed::Settings >( );
    settings->set_port( 1984 );
    settings->set_bind_address( "127.0.0.1" );
    settings->set_default_header( "Connection", "close" );
    
    restbed::Service service;
    service.publish( resource );
    service.start( settings );
    
    return EXIT_SUCCESS;
}