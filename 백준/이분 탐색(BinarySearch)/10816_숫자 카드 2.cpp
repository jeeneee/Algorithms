//
//  10816_숫자 카드 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/18.
//  Copyright © 2019 장우진. All rights reserved.
//

/*
 lower_bound, upper_bound를 구현할 때 반열린 구간 Notation을 지키는 것이 좋다.

 ##### lower_bound 구현하기 #####
 1. 이분탐색을 수행하듯이 lo, mid, hi 파라미터를 반복문 돌려가면서 적당히 조정한다.(while(lo < hi))
 2. mid가 가리키는 값이 value보다 작으면(elements[mid] < value), 탐색해야 하는 범위가 뒤쪽에 있다고 가정한다. → lo = mid + 1
 3. mid가 가리키는 값이 value보다 크거나 같으면(elements[mid] ≥ value), 탐색해야 하는 범위는 좁혀진다.(high = mid)
 4. 탐색에 성공하여 value 이상의 값이 처음 나타나는 위치를 발견하게 된다면, 탐색 범위가 좁혀진 lo(==hi)를 반환한다.
 5. 탐색에 실패하여 mid가 포함되지 않는 구간인 high에 도달하게 된다면, 없다고 가정하고 high를 반환한다.
 ##### upper_bound 구현하기 #####
 1. 이분탐색을 수행하듯이 lo, mid, hi 파라미터를 반복문 돌려가면서 적당히 조정한다.(while(lo < hi))
 2. mid가 가리키는 값이 value보다 작거나 같으면(elements[mid] <= value), 탐색해야 하는 범위가 뒤쪽에 있다고 가정한다. → lo = mid + 1
 3. mid가 가리키는 값이 value보다 크면(elements[mid] > value), 탐색해야 하는 범위는 좁혀진다.(high = mid)
 4. 탐색에 성공하여 value를 넘는 값이 처음 나타나는 위치를 발견하게 된다면, 탐색 범위가 좁혀진 lo(==hi)를 반환한다.
 5. mid가 포함되지 않는 구간인 high에 도달하게 된다면, 없다고 가정하고 high를 반환한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(int A[], int low, int high, int value) {
    while (low < high) {
        int mid = (low + high) / 2;
        if (mid == high)
            return high;
        if (A[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upperBound(int A[], int low, int high, int value) {
    while (low < high) {
        int mid = (low + high) / 2;
        if (mid == high)
            return high;
        if (A[mid] <= value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int * A = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    
    sort(A, A + n);
    
    scanf("%d", &m);
    while (m--) {
        int x, lo = 0, hi = n;
        scanf("%d", &x);
        printf("%d ", upperBound(A, lo, hi, x) - lowerBound(A, lo, hi, x));
    }
    delete []A;
    return 0;
}
