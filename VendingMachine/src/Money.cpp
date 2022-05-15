#include "Money.h"

Money::Money(double n)
{
    twenty = n/20;
    n -= twenty * 20;
    ten = n/10;
    n -= ten * 10;
    five = n/5;
    n -= five * 5;
    ones = n/1;
    n -= ones;
    halfs = n * 2;
    n -= halfs * (1.0/2.0);
}

double Money::toInt(){
    //Converts from bills and coins to integer
    return(twenty * 20.0 + ten * 10.0 + five * 5.0 + ones + halfs * 2.0);
}

bool Money::operator< (Money& another){
    return (this->toInt() < another.toInt());
}

Money Money::operator- (Money& another){
    if((*this) < another){
        cout << "Invalid Operation!!\nAborting...\n";
        return (*this);
    }

    Money ret(this->toInt() - another.toInt());
    return ret;
}

Money Money::operator+ (Money& another){
    Money ret;
    ret.twenty = twenty + another.twenty;
    ret.ten = ten + another.ten;
    ret.five = five + another.ten;
    ret.ones = ones + another.ones;
    ret.halfs = halfs + another.halfs;
    return ret;
}

Money Money::operator-= (Money& another){
    (*this) = (*this) - another;
    return (*this);
}

Money Money::operator+= (Money& another){
    (*this) = (*this) + another;
    return (*this);
}

bool Money::operator>= (Money& another){
    return (!((*this) < another));
}
