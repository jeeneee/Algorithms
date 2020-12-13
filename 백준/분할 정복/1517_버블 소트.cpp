//
//  1517_버블 소트.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/20.
//  Copyright © 2019 장우진. All rights reserved.
//
/* MERGE SORT를 이용해 swap 횟수를 구할 수 있다. */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 500000;

int sorted[MAX];
long long cnt = 0;

void merge(int arr[], int start, int mid, int end) {
    /* i는 앞 배열 인덱스, j는 뒷 배열 인덱스, k는 sorted 배열 인덱스 */
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else {
            sorted[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }
    if (i > mid)
        for (int t = j; t <= end; ++t)
            sorted[k++] = arr[t];
    else
        for (int t = i; t <= mid; ++t)
            sorted[k++] = arr[t];
    
    for (int t = start; t <= end; ++t)
        arr[t] = sorted[t];
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);

    printf("%lld\n", cnt);
    
    delete []arr;
    return 0;
}
