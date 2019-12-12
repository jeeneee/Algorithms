//
//  1021_회전하는 큐.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 15/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#define MAX 3000
using namespace std;

int main() {
    int n, m, deque[MAX], leftIdx = MAX / 2, rightIdx = MAX / 2, idx = 0;
    scanf("%d %d", &n, &m);
    // initialize deque (push_back)
    for (int i = 0; i < n; ++i) {
        deque[leftIdx + i] = i + 1;
        rightIdx++;
    }
    int* arr = new int[m];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    while (idx < m) {
        int size = rightIdx - leftIdx;
        int front = 0;
        for (int i = leftIdx; deque[i] != arr[idx]; ++i, ++front);
        int back = size - front;
        if (front < back) {
            while (front--) {
                deque[rightIdx++] = deque[leftIdx++];
                ans++;
            }
            leftIdx++;
        }
        else {
            while (back--) {
                deque[--leftIdx] = deque[--rightIdx];
                ans++;
            }
            leftIdx++;
        }
        idx++;
    }
    printf("%d\n", ans);
    
    delete []arr;
    return 0;
}
