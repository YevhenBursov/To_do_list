#pragma once

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include "Array_lib.h"
using namespace std;

template <typename tp_1>
void randArr(tp_1* arr, const int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 100-50) /* (tp_1)(1 + rand() % 5)*/;
    }
}

template <typename tp_1>
void printArr(const tp_1* arr, const int n) {
    for (int i = 0; i < n; i++) {
        cout <<setw(5)<< arr[i] << " ";
    }
}

template <typename tp_1>
void my_swap(tp_1* a, tp_1* b) {
    tp_1 t = *a;
    *a = *b;
    *b = t;
}

template <typename tp_1>
bool firsIsBiger(tp_1 a, tp_1 b) {
    return a > b;
}


template <typename tp_1>
void sortArr(tp_1* arr, const int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (firsIsBiger(arr[j], arr[j + 1])) {
                my_swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

template <typename tp_1>
int lineSearch(const tp_1* arr, const int n, const tp_1 key) {
    for (int i = 0; i < n; i++) {
        if (fabs(arr[i] - key) < 0.0002) { //fabs аблолютное значение 
            return key;
        }
    }
    return 0;
}


template <typename tp_1>
void my_swap1(tp_1* a, tp_1* m) {
    for (int i = 0; i < m; a++, i++) {
        if (i % 2 != 0) {
            int n = *a;
            *a = *(a - 1);
            *(a - 1) = n;
        }
    }
    
}

template <typename tp_1>
void swap(tp_1* a, tp_1* b) {
    tp_1 t = *a;
    *a = *b;
    *b = t;
}



template <typename tp_1>
void addElement(tp_1*& arr, int& n, tp_1 el, int index) {
    tp_1* temp = new tp_1[n + 1];
    for (int i = 0; i < index; i++) {
        temp[i] = arr[i];
    }
    temp[index] = el;
    n++;
    for (int i = index + 1; i < n; i++) {
        temp[i] = arr[i - 1];
    }
    delete[] arr;
    arr = temp;
}

template <typename tp_1>
void delElement(tp_1*& arr, int& n, int index) {
    tp_1* temp = new tp_1[n - 1];
    for (int i = 0; i < index; i++) {
        temp[i] = arr[i];
    }

    for (int i = index + 1; i < n; i++) {
        temp[index++] = arr[i];
    }
    n--;
    arr = temp;
}
