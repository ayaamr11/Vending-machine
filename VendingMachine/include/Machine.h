#ifndef MACHINE_H
#define MACHINE_H

#include "Item.h"
#include "Money.h"
#include <set>
#include <map>

using namespace std;

class Machine
{
    public:
        Machine(){}

        void check_OFS();
        void addItem(Item);
        void buyItem(int, int, Money&);
        void showItemList();
        int GetAmount(int);

        static int Machine_Item_counter;

    protected:

    private:
        set<Item> myItems;
        map<Item, int> Items_counter;
        map<int, Item> Items_IDs;
        bool out_of_stock = false;
};

#endif // MACHINE_H
