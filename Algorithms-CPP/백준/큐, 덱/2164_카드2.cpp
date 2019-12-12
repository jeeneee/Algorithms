//
//  2164_카드2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 14/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 1000003
using namespace std;

int main() {
    int n, queue[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        queue[i] = i + 1;
    }
    int leftIdx = 0, rightIdx = n;
    while (true) {
        if (rightIdx == leftIdx + 1) {
            printf("%d\n", queue[leftIdx]);
            break;
        }
        leftIdx++;
        if (rightIdx == leftIdx + 1) {
            printf("%d\n", queue[leftIdx]);
            break;
        }
        queue[rightIdx++] = queue[leftIdx++];
    }
    return 0;
}
