#ifndef BUYER_H
#define BUYER_H

#include "Money.h"
#include "Item.h"
#include "Machine.h"

class Buyer
{
    public:
        Buyer(){
            Money p(50);
            pocketMoney = p;
        }

        Buyer(int amount){
            Money p(amount);
            pocketMoney = p;
        }

        Buyer(Money p){
            pocketMoney = p;
        }

        void Buy(Machine, int, int);
        Money getPocket(){
            return pocketMoney;
        }

        void setPocket(int);

    protected:

    private:
        Money pocketMoney;
};

#endif // BUYER_H
