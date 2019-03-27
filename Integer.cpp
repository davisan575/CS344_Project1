#include <iostream>
#include "Integer.h"


extern int Integer_count;
bool operator<(const Integer & compare_left, const Integer & compare_right)
{
    Integer_count++;
    if(compare_left.value() < compare_right.value())
    {
        return true;
    }
    else
    {
        return false;
    }
}

Integer & Integer::operator=(const Integer & prev_Integer)
{
    Integer_count++;
    value_ = prev_Integer.value();
    return *this;
}
