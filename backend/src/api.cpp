#include "api.h"

System globSystem;

string quickRound(float val, int pres){
    std::stringstream stream;
    stream << std::fixed << std::setprecision(pres) << val;
    return stream.str();
}
// gets list of all stocks that are currently available on the market.
void stocks_handler( const shared_ptr< restbed::Session > session )
{
    Market* market = globSystem.market;
    json out;
    for(int i = 0; i < market->getNumStocks(); i++){
        out["availableStocks"][i] = {
            {"price", quickRound(market->getStock(i).getPrice(),2)},
            {"symbol", market->getStock(i).getSymbol()}
        };
    }
    session->close( restbed::OK, out.dump(), { { "Content-Length", to_string(strlen(out.dump().c_str())) } } );
}

//converts the user object to a json structure

json userToJson(User* user){
    json userJson = {
        {"activeUser", globSystem.activeUser},
        {"activeAccount", user->getActiveInd()},
    };
    for(int i = 0; i < user->getNumAccounts(); i++){
        Account account = user->getAccount(i);
        userJson["accounts"][i] = {
            {"cash", quickRound(account.getCash(),2)},
            {"owner", account.getOwner()}
            };
        for(int x = 0; x < account.getNumPositions(); x++){
            Position position = account.getPositionArray()[x];
            userJson["accounts"][i]["positions"][x] = {
                {"symbol", position.getSymbol()},
                {"numShares", quickRound(position.getNumShares(),2)},
                {"originalPrice", quickRound(position.getOPPS(),2)},
                {"currentPrice", quickRound(position.getCPPS(),2)}
            };
        }
    }
    return userJson;
}

// outputs the user json

void user_handler( const shared_ptr< restbed::Session > session ){
    User* user = globSystem.users[globSystem.activeUser];
    json userJson = userToJson(user);
    session->close( restbed::OK, userJson.dump(), { { "Content-Length", to_string(strlen(userJson.dump().c_str())) } } );
}


//Allows api users to make requests tp purchase positions using the active account
//expects {symbol, numShares, type, }

void purchase_position_handler( const shared_ptr< restbed::Session > session ){
    const auto request = session->get_request( );
    size_t content_length = request->get_header( "Content-Length", 0 );
    session->fetch( content_length, [ request ]( const shared_ptr< restbed::Session > session, const restbed::Bytes & body ){
        
        json data = json::parse(body.data( ));

        User* user = globSystem.users[globSystem.activeUser];
        Stock stock = globSystem.market->getStockBySymbol(data["symbol"]);
        string numShares = data["numShares"];
        
        if(user->purchasePosition(stock, globSystem.market, stof(numShares), data["type"])){
            session->close( 
                restbed::OK,
                "{\"status\": \"SUCCESS\"}",
                { 
                    { "Content-Length", to_string(strlen("{\"status\": \"SUCCESS\"}")).c_str()},
                    { "Connection", "close" }
                } 
            );
        }
        //fprintf( stdout, "%.*s\n", ( int ) body.size( ), body.data( ) );
    } );

}

//core of api, hosts all the resources that the service hosts.

int hostAPI(System paramSystem)
{
    globSystem = paramSystem;
    auto stocks = make_shared< restbed::Resource >( );
    stocks->set_path( "/stocks" );
    stocks->set_method_handler( "GET", stocks_handler );

    auto user = make_shared< restbed::Resource >( );
    user->set_path( "/user" );
    user->set_method_handler( "GET", user_handler );

    auto purchase = make_shared< restbed::Resource >( );
    purchase->set_path( "/purchase/position" );
    purchase->set_method_handler( "POST", purchase_position_handler );
    
    auto settings = make_shared< restbed::Settings >( );
    settings->set_port( 1984 );
    settings->set_bind_address( "127.0.0.1" );
    settings->set_default_header( "Connection", "close" );
    
    restbed::Service service;
    service.publish( stocks );
    service.publish( user );
    service.publish( purchase );
    service.start( settings );
    
    return EXIT_SUCCESS;
}