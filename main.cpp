#include <iostream>
//using namespace std;

template <class T>
void print(T a[], int start, int stop) {
    for (int i = start; i < stop; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}

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
void partition(T a[], int start, int stop, int & pivot) {
    std::swap(a[start], a[pivot]); // Putting pivot in  front of array
    T * temp = new T[stop - start]; // Creating temp array to partition
    int front = 0; // Index of elements less than pivot
    int back = stop - start - 1; // Index of elements greater than pivot
    for (int i = start + 1; i < stop; ++i) {
        if (a[i] < a[start]) {
            temp[front] = a[i];
            front++;
        } else {
            temp[back] = a[i];
            back--;
        }
    }
    temp[front] = a[start]; // Adding the pivot to appropriate location
    pivot = start + front;
    
    std::copy(temp, temp+stop-start, a+start);
    delete[] temp;
}

template <class T>
void quicksort_first(T a[], int start, int stop) {
    if (stop - start > 1) {
        int pivot = start;
        partition(a, start, stop, pivot);
        quicksort_first(a, start, pivot);
        quicksort_first(a, pivot+1, stop);
    }
}

template <class T>
void quicksort_random(T a[], int start, int stop) {
    if (stop - start > 1) {
        int pivot = start + rand() % (stop-start);
        partition(a, start, stop, pivot);
        quicksort_first(a, start, pivot);
        quicksort_first(a, pivot+1, stop);
    }
}


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
    
    
    return 0;
}
