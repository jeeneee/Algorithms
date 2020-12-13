//
//  1920_수 찾기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/17.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    int * A = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A, A + n);
    scanf("%d", &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        int le = 0, ri = n - 1, mid;
        if (x < A[le] || x > A[ri]) {
            printf("0\n");
            continue;
        }
        bool flag = false;
        while (le <= ri) {
            mid = (le + ri) / 2;
            if (x == A[mid]) {
                printf("1\n");
                flag = true;
                break;
            }
            else if (x < A[mid])
                ri = mid - 1;
            else
                le = mid + 1;
        }
        if (!flag)
            printf("0\n");
    }
    delete []A;
    return 0;
}
