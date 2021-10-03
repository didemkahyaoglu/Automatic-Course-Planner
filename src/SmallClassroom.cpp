#include "SmallClassroom.h"
#define CAPACITY 50 // Our default variable

SmallClassroom::SmallClassroom()
{
    //ctor
}
SmallClassroom::SmallClassroom(int numberOfSmall)
{
    this->numberOfSmall = numberOfSmall;
    this->s_capacity=CAPACITY;
}
int SmallClassroom::getNumberOfSmall() const
{
    return numberOfSmall;
}
void SmallClassroom::setNumberOfSmall(const int &value)
{
    numberOfSmall = value;
}
SmallClassroom::~SmallClassroom()
{
    //dtor
}

