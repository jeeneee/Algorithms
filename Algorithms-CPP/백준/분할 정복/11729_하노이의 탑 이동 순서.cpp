//
//  11729_하노이의 탑 이동 순서.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/19.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

void hanoi(int from, int by, int to, int n) {
    if (n == 0) return;
    hanoi(from, to, by, n - 1);
    printf("%d %d\n", from, to);
    hanoi(by, from, to, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n) - 1);
    hanoi(1, 2, 3, n);
    return 0;
}
