#include "BigClassroom.h"
#define CAPACITY 100 // Our default variable

BigClassroom::BigClassroom()
{
    //ctor
}
BigClassroom::BigClassroom(int numberOfBig)
{
    this->numberOfBig = numberOfBig;
    this->b_capacity=CAPACITY;
}
int BigClassroom::getNumberOfBig() const
{
    return numberOfBig;
}
void BigClassroom::setNumberOfBig(const int &value)
{
    numberOfBig = value;
}

BigClassroom::~BigClassroom()
{
    //dtor
}

