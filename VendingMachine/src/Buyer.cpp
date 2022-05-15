#include "Buyer.h"

void Buyer::Buy(Machine machine, int item_id, int amount){
    machine.buyItem(item_id, amount, pocketMoney);
}

void Buyer::setPocket(int pMoney){
    //Sets amount of money the buyer has on him
    Money holder(pMoney);
    pocketMoney = holder;
}