#include <iostream>
#include "sort.h"
#include "integer.h"
//using namespace std;

int Integer_count;

int main(int argc, const char * argv[]) {
    
    const int n = 10000;
    
    Integer array1[n]; // In order
    Integer array2[n]; // Reverse order
    Integer array3[n]; // Random
    Integer array4[n]; // Random
    Integer array5[n]; // Random
    Integer array3rand[n]; // Random
    Integer array4rand[n]; // Random
    Integer array5rand[n]; // Random
    
    int SScount[5] = {0,0,0,0,0};
    int IScount[5] = {0,0,0,0,0};
    int MScount[5] = {0,0,0,0,0};
    int DQScount[5] = {0,0,0,0,0};
    int RQScount[5] = {0,0,0,0,0};
    int RQSIPcount[5] = {0,0,0,0,0};
    int STLcount[5] = {0,0,0,0,0};
    
    // Decalring our constant random arrays
    for (int i = 0; i < n; ++i) {
        array3rand[i] = Integer(rand() % n);
        array4rand[i] = Integer(rand() % n);
        array5rand[i] = Integer(rand() % n);
    }
    
    // Preparing arrays to be sorted
    for (int i = 0; i < n; ++i) {
        array1[i] = Integer(i+1);
        array2[i] = Integer(n-i);
        array3[i] = array3rand[i];
        array4[i] = array4rand[i];
        array5[i] = array5rand[i];
    }
    
    // Selection sort
    std::cout << "Selection Sort" << std::endl;
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
*/
    Integer_count = 0;
    selection_sort(array1, 0, n);
    SScount[0] = Integer_count;
    Integer_count = 0;
    selection_sort(array2, 0, n);
    SScount[1] = Integer_count;
    Integer_count = 0;
    selection_sort(array3, 0, n);
    SScount[2] = Integer_count;
    Integer_count = 0;
    selection_sort(array4, 0, n);
    SScount[3] = Integer_count;
    Integer_count = 0;
    selection_sort(array5, 0, n);
    SScount[4] = Integer_count;
   
    print(SScount, 0, 5);
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    // Insertion sort
    std::cout << "Insertion Sort" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        array1[i] = Integer(i+1);
        array2[i] = Integer(n-i);
        array3[i] = array3rand[i];
        array4[i] = array4rand[i];
        array5[i] = array5rand[i];
    }
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    Integer_count = 0;
    insertion_sort(array1, 0, n);
    IScount[0] = Integer_count;
    Integer_count = 0;
    insertion_sort(array2, 0, n);
    IScount[1] = Integer_count;
    Integer_count = 0;
    insertion_sort(array3, 0, n);
    IScount[2] = Integer_count;
    Integer_count = 0;
    insertion_sort(array4, 0, n);
    IScount[3] = Integer_count;
    Integer_count = 0;
    insertion_sort(array5, 0, n);
    IScount[4] = Integer_count;
    
    print(IScount, 0, 5);
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    
    // Insertion sort
    std::cout << "mergesort" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        array1[i] = Integer(i+1);
        array2[i] = Integer(n-i);
        array3[i] = array3rand[i];
        array4[i] = array4rand[i];
        array5[i] = array5rand[i];
    }
    /*
     for (int i = 0; i < n; ++i) {
     std::cout << array1[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array2[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array3[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array4[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array5[i].value() << ' ';
     }
     std::cout << std::endl;
     */
    Integer_count = 0;
    mergesort(array1, 0, n);
    MScount[0] = Integer_count;
    Integer_count = 0;
    mergesort(array2, 0, n);
    MScount[1] = Integer_count;
    Integer_count = 0;
    mergesort(array3, 0, n);
    MScount[2] = Integer_count;
    Integer_count = 0;
    mergesort(array4, 0, n);
    MScount[3] = Integer_count;
    Integer_count = 0;
    mergesort(array5, 0, n);
    MScount[4] = Integer_count;
    
    print(MScount, 0, 5);
    /*
     for (int i = 0; i < n; ++i) {
     std::cout << array1[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array2[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array3[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array4[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array5[i].value() << ' ';
     }
     std::cout << std::endl;
     */
    
    // Quicksort first element sort
    std::cout << "Quicksort, not in place, first element" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        array1[i] = Integer(i+1);
        array2[i] = Integer(n-i);
        array3[i] = array3rand[i];
        array4[i] = array4rand[i];
        array5[i] = array5rand[i];
    }
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    Integer_count = 0;
    quicksort_first(array1, 0, n);
    DQScount[0] = Integer_count;
    Integer_count = 0;
    quicksort_first(array2, 0, n);
    DQScount[1] = Integer_count;
    Integer_count = 0;
    quicksort_first(array3, 0, n);
    DQScount[2] = Integer_count;
    Integer_count = 0;
    quicksort_first(array4, 0, n);
    DQScount[3] = Integer_count;
    Integer_count = 0;
    quicksort_first(array5, 0, n);
    DQScount[4] = Integer_count;
    
    print(DQScount, 0, 5);
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    // Quicksort random element sort
    std::cout << "Quicksort, not in place, random element" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        array1[i] = Integer(i+1);
        array2[i] = Integer(n-i);
        array3[i] = array3rand[i];
        array4[i] = array4rand[i];
        array5[i] = array5rand[i];
    }
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    Integer_count = 0;
    quicksort_random(array1, 0, n);
    RQScount[0] = Integer_count;
    Integer_count = 0;
    quicksort_random(array2, 0, n);
    RQScount[1] = Integer_count;
    Integer_count = 0;
    quicksort_random(array3, 0, n);
    RQScount[2] = Integer_count;
    Integer_count = 0;
    quicksort_random(array4, 0, n);
    RQScount[3] = Integer_count;
    Integer_count = 0;
    quicksort_random(array5, 0, n);
    RQScount[4] = Integer_count;
    
    print(RQScount, 0, 5);
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    // Quicksort in place sort
    std::cout << "Quicksort, in place, random element" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        array1[i] = Integer(i+1);
        array2[i] = Integer(n-i);
        array3[i] = array3rand[i];
        array4[i] = array4rand[i];
        array5[i] = array5rand[i];
    }
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    Integer_count = 0;
    quicksort_inPlace(array1, 0, n);
    RQSIPcount[0] = Integer_count;
    Integer_count = 0;
    quicksort_inPlace(array2, 0, n);
    RQSIPcount[1] = Integer_count;
    Integer_count = 0;
    quicksort_inPlace(array3, 0, n);
    RQSIPcount[2] = Integer_count;
    Integer_count = 0;
    quicksort_inPlace(array4, 0, n);
    RQSIPcount[3] = Integer_count;
    Integer_count = 0;
    quicksort_inPlace(array5, 0, n);
    RQSIPcount[4] = Integer_count;
    
    print(RQSIPcount, 0, 5);
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    
    // STL sort
    std::cout << "STL sort algorithm" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        array1[i] = Integer(i+1);
        array2[i] = Integer(n-i);
        array3[i] = array3rand[i];
        array4[i] = array4rand[i];
        array5[i] = array5rand[i];
    }
    /*
     for (int i = 0; i < n; ++i) {
     std::cout << array1[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array2[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array3[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array4[i].value() << ' ';
     }
     std::cout << std::endl;
     for (int i = 0; i < n; ++i) {
     std::cout << array5[i].value() << ' ';
     }
     std::cout << std::endl;
    */
    Integer_count = 0;
    std::sort(array1, array1+n);
    STLcount[0] = Integer_count;
    Integer_count = 0;
    std::sort(array2, array2+n);
    STLcount[1] = Integer_count;
    Integer_count = 0;
    std::sort(array3, array3+n);
    STLcount[2] = Integer_count;
    Integer_count = 0;
    std::sort(array4, array4+n);
    STLcount[3] = Integer_count;
    Integer_count = 0;
    std::sort(array5, array5+n);
    STLcount[4] = Integer_count;
    
    print(STLcount, 0, 5);
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << array1[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array2[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array3[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array4[i].value() << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array5[i].value() << ' ';
    }
    std::cout << std::endl;
    */
    
    
    return 0;
}
