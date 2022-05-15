#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using namespace std;

class Money
{
    friend ostream& operator<< (ostream& out, const Money money){
        out << money.twenty << " " << money.ten << " " << money.five << " " << money.ones << " " << money.halfs << endl;
        return out;
    }

    public:
        Money(){
            halfs = ones = five = ten = twenty = 0;
        }

        Money(double n);

        double toInt();

        Money operator- (Money&);
        Money operator+ (Money&);
        Money operator-= (Money&);
        Money operator+= (Money&);
        bool operator< (Money&);
        bool operator>= (Money&);

    protected:

    private:
        int halfs, ones, five, ten, twenty;
};

#endif // MONEY_H
