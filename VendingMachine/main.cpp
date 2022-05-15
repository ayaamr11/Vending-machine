/***        VENDING MACHINE         ***
 * AUTHORS: Aya Amr         20170359
 *          Nada Mahmoud    20170370
 */

#include <iostream>
#include "Machine.h"
#include "Buyer.h"
#include "Item.h"
#include "Money.h"

using namespace std;

int main()
{
    Machine machine1;

    //Add default item in machine
    Money choco_price(5);
    Item chocolate(10, choco_price, "Chocolate", "0");
    machine1.addItem(chocolate);

    Buyer buyer1;
    cout << "How much pocket money do you have? ";
    double buyer_pocket;
    cin >> buyer_pocket;
    buyer1.setPocket(buyer_pocket);

    while(true){
        cout << "How can I help you?\n"
                "1- Buy Item\n"
                "2- Add an Item\n"
                "3- Show list of Items\n"
                "4- Print available pocket money\n"
                "5- Exit\n";

        int choice; cin >> choice;

        switch (choice){
            case 1:                         //Buy Item
                machine1.showItemList();
                cout << "Please enter the amount of money to exchange for desired item: ";

                double input_money; cin >> input_money;

                while(input_money > buyer_pocket){
                    cout << "Sorry, the amount of money Entered is more than the available pocket money.\nPlease Enter a valid amount or 0 to abort: ";
                    cin >> input_money;
                    if(input_money == 0)
                        break;              //break from while
                }

                if(input_money == 0)
                    break;                  //break from switch

                else {
                    cout << "Pick an item by ID: ";
                    int item_id;
                    cin >> item_id;

                    cout << "Enter amount to buy: ";
                    int amount_to_buy;
                    cin >> amount_to_buy;

                    while (amount_to_buy > machine1.GetAmount(item_id)) {
                        cout << "Sorry amount desired is more than the available quantity.\nPlease Enter a valid amount to buy or 0 to abort: ";
                        cin >> amount_to_buy;
                        if (amount_to_buy == 0)
                            break;                  //break from while
                    }

                    if (amount_to_buy == 0)
                        break;                      //break from case

                    else {
                        buyer_pocket -= input_money;
                        buyer1.setPocket(buyer_pocket);
                        Money paid(input_money);
                        machine1.buyItem(item_id, amount_to_buy, paid);
                        break;
                    }
                }

            case 2: {               //Add Item
                string item_name;
                double price_double;

                cout << "Enter item name: ";
                cin >> item_name;

                cout << "Enter item price: ";
                cin >> price_double;

                Money price(price_double);
                string init_id = to_string(Machine::Machine_Item_counter + 1);

                Item newItem(10, price, item_name, init_id);
                machine1.addItem(newItem);
            }
                break;

            case 3:                         //Shows list of items available in the machine
                machine1.showItemList();
                break;

            case 4:                         //Prints amount of pocket money on the buyer
                cout << "In terms of bills and coins:\nTwenty Ten Five Ones Halfs\n"
                        << buyer1.getPocket()
                        << "Total money: " << buyer1.getPocket().toInt() << "\n";
                break;

            case 5:                         //Exits
                    cout << "Thanks for using our vending machine!!\n";
                    return 0;

            default:
                cout << "Sorry Wrong choice, please re-enter a valid choice: ";
        }
    }
}
