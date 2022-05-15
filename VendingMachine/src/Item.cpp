#include "Item.h"

Item::Item()
{
    m_no_units = 10;
    Item_name = "New Item";
    Money p(10);
    m_price = p;
}

bool Item::getItem(int amount, Money& paid){
    //checks if amount and price entered by buyer are sufficient to buy the desired item
    if(m_no_units >= amount){
        if(m_price < paid){
            cout << "Thanks for buying!! =D\n";
            m_no_units -= amount;
            paid -= m_price;
            return true;
        }
        else{
            cout << "Amount of money entered is not sufficient!\n";
            return false;
        }
    }

    else{
        cout << "Quantity available of desired item is less than requested amount, sorry for the inconvenience..\n";
        return false;
    }
}
