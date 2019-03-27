#include <iostream>
//using namespace std;

template <class T>
void insertion_sort(T a[],  int start, int stop) {
    for (int i = start+1; i < stop; ++i) {
        T x = a[i];
        int test_inc = i-1;
        
        while (test_inc >= start && x < a[test_inc]) {
            a[test_inc+1] = a[test_inc];
            --test_inc;
        }
        a[test_inc+1] = x;
    }
}

template <class T>
void print(T a[], int start, int stop) {
    for (int i = start; i < stop; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}


int main(int argc, const char * argv[]) {
    
    //Testing Insertion Sort
    int a[5] = {1, 3, 5, 4, 2};
    insertion_sort(a, 0, 5);
    print(a, 0, 5);
    
    return 0;
}
