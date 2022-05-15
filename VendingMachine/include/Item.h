#ifndef ITEM_H
#define ITEM_H

#include "Money.h"
#include <iostream>

using namespace std;

class Item
{
    string m_id;

    public:
        Item();

        Item(int amount, Money price, string item_name, string ID):m_id(ID){
            m_no_units = amount;
            m_price = price;
            Item_name = item_name;
        }

        bool getItem(int, Money&);

        string GetItemName() const {
            return Item_name;
        }

        void SetItemAmount(int amo){
            //Sets the amount available of a specific item
            m_no_units = amo;
        }

        int GetItemAmount() const {
            return m_no_units;
        }

        const string& getID() const {
            return m_id;
        }
        bool operator< (const Item& item) const{
            return item.m_id < this->m_id;
        }

    protected:

    private:
        string Item_name;
        int m_no_units;
        Money m_price;
};

#endif // ITEM_H
