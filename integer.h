//
//  integer.h
//  Project1
//
//  Created by Thomas Conroy on 3/27/19.
//  Copyright © 2019 Thomas Conroy. All rights reserved.
//

#ifndef integer_h
#define integer_h


//int Integer_count = 0;
extern int Integer_count;
class Integer
{
public:
    
    Integer() :  value_(0) {} ;
    Integer(int x) : value_(x) {} ;
    Integer(const Integer & i1);
    
    const int value() const { return value_; }
    Integer & operator=(const Integer & prev_Integer);
    bool friend operator<(const Integer & compare_left, const Integer & compare_right);
    
private:
    int value_;
};

inline Integer::Integer(const Integer & i1)
{
    value_ = i1.value();
    Integer_count++;
}


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

#endif /* integer_h */
