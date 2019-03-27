//
//  sort.h
//  Project1
//
//  Created by Thomas Conroy on 3/27/19.
//  Copyright © 2019 Thomas Conroy. All rights reserved.
//

#ifndef sort_h
#define sort_h

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
void selection_sort(T a[], int start, int stop) {
    while (stop - start > 1) {
        auto itr_max = std::max_element(a+start, a+stop);
        std::swap(*itr_max, a[stop-1]);
        --stop;
    }
}

template <class T>
void partition(T a[], int start, int stop, int & pivot) {
    std::swap(a[start], a[pivot]);
    T * temp = new T[stop - start];
    int front = 0;
    int back = stop - start - 1;
    for (int i = start + 1; i < stop; ++i) {
        if (a[i] < a[start]) {
            temp[front] = a[i];
            front++;
        } else {
            temp[back] = a[i];
            back--;
        }
    }
    temp[front] = a[start];
    pivot = start + front;
    
    std::copy(temp, temp+stop-start, a+start);
    delete[] temp;
}

template <class T>
void partition_inPlace(T a[], int start, int stop, int & pivot) {
    int p = start;
    int q = start;
    int r = stop-1;
    std::swap(a[r], a[pivot]);
    T pivot_value = a[r];
    while (q != r) {
        if (a[q] <= pivot_value) {
            std::swap(a[q], a[p]);
            ++p;
        }
        ++q;
    }
    std::swap(a[r], a[p]);
    pivot = p;
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

template <class T>
void quicksort_inPlace(T a[], int start, int stop) {
    if (stop - start > 1) {
        int pivot = start + rand() % (stop-start);
        partition_inPlace(a, start, stop, pivot);
        quicksort_inPlace(a, start, pivot);
        quicksort_inPlace(a, pivot+1, stop);
    }
}

#endif /* sort_h */
