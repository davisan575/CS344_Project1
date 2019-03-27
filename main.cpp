#include <iostream>
#include "sort.h"
//using namespace std;


int main(int argc, const char * argv[]) {
   
    //Testing Insertion Sort
    std::cout << "insertion_sort Test" << std::endl;
    int a[5] = {1, 3, 5, 4, 2};
    insertion_sort(a, 0, 5);
    print(a, 0, 5);
    std::cout << std::endl;

    //Testing partition
    std::cout << "partition Test" << std::endl;
    int b[6] = {19,4,3,20,7,8};
    int pivot = 0;
    std::cout << "Pivot: " << b[pivot] << std::endl;
    partition(b, 0, 6, pivot);
    print(b, 0, 6);
    std::cout << "Returned pivot index: " << pivot << std::endl << std::endl;;
 
    //Testing quicksort with first element pivot
    std::cout << "quicksort First Element Pivot Test" << std::endl;
    int c[7] = {11,4,7,8,5,1,12};
    quicksort_first(c, 0, 7);
    print(c, 0, 7);
    std::cout << std::endl;

    //Testing quicksort with random element pivot
    std::cout << "quicksort Random Element Pivot Test" << std::endl;
    int d[9] = {15,6,69,100,8,0,3,42,7};
    quicksort_first(d, 0, 9);
    print(d, 0, 9);
    std::cout << std::endl;
    
    //Testing partition in place
    std::cout << "partition in place Test" << std::endl;
    int e[6] = {19,4,3,20,7,8};
    pivot = 5;
    std::cout << "Pivot: " << e[pivot] << std::endl;
    partition_inPlace(e, 0, 6, pivot);
    print(e, 0, 6);
    std::cout << "Returned pivot index: " << pivot << std::endl << std::endl;;
    
    //Testing quicksort with in place partitioning
    std::cout << "quicksort In Place Partitioning Test" << std::endl;
    int f[9] = {15,6,69,100,8,0,3,42,7};
    quicksort_inPlace(f, 0, 9);
    print(f, 0, 9);
    std::cout << std::endl;
    
    //Testing selection sort
    std::cout <<"selection_sort test" << std::endl;
    int g[5] = {2,4,5,1,3};
    selection_sort(g, 0, 5);
    print(g, 0, 5);
    std::cout << std::endl;
    
    return 0;
}
