#include "appStructs.h"


System fillSystem(Market* market, TimeDB *timeDB, User **userArray, int numUsers, int activeUser){
    System system = {market, timeDB};
    for(int i = 0; i < numUsers; i++){
        system.users[i] = userArray[i];
        system.numUsers++;
    }
    system.activeUser = activeUser;
    return system;
}