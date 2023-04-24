#ifndef RESULT_H
#define RESULT_H

#include "account.h"

class SuccessEvaluator{
    Market* market;

    public:
    float getAccountGains(Account);
    float getPositionGains(Position);

};
#endif