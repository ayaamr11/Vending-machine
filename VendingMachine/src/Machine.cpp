#include "Machine.h"

int Machine::Machine_Item_counter = 0;      //Counts number of items inside Machine

void Machine::check_OFS(){
    //Check whether Machine is empty
    if(myItems.empty())
        out_of_stock = true;
}

void Machine::addItem(Item item){
    //Add Item to the Machine
    myItems.insert(item);
    Items_counter[item] = 10;
    Items_IDs[++Machine_Item_counter] = item;
}

void Machine::buyItem(int f_id, int amount, Money& paid){
    //Buy desired amount of an item from the Machine
    Item item = Items_IDs[f_id];
    if(item.getItem(amount, paid)){
        Items_counter[item] -= amount;
        Items_IDs[f_id].SetItemAmount(Items_counter[item]);
        if(!Items_counter[item])
            myItems.erase(item);
    }
}

int Machine::GetAmount(int f_id){
    //returns amount of specific item available in the Machine
    return Items_counter[Items_IDs[f_id]];
}

void Machine::showItemList(){
    //Shows Items and their available amounts in the Machine
    cout << "ID \t ITEMS LIST \t AMOUNT\n\n";
    for(const auto &i : Items_IDs) {
        cout << i.first << "-\t" << i.second.GetItemName() << "\t" << i.second.GetItemAmount() << "\n";
    }
}