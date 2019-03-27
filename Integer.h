#include <iostream>

#ifndef _Integer_h_
#define _Integer_h_

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
    //Integer_count++;
}



#endif
