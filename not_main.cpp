#include <iostream>
#include <string>

#include "Integer.h"

int Integer_count;

int main()
{
    Integer_count = 0;
    
    Integer x(5);
    Integer y(10);
    std::cout << "Integer count before any operations: " << Integer_count << std::endl;
    bool check = x < y;
    std::cout << "Integer count after one less than comparison: " << Integer_count << std::endl;
    bool check2 = y < x;
    std::cout << "Integer count after another less than comparison: " << Integer_count << std::endl;
    int val = x.value();
    std::cout << "value of x: " << val << std::endl;
    x = y;
    val = x.value();
    std::cout << "value of x after being set to y: " << val << std::endl;
    std::cout << "Integer count after x is set to y: " << Integer_count << std::endl;
    
    std:: cout << check << std::endl;
    std::cout << check2 << std::endl;
    
    return 0;
}
