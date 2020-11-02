//
//  1561_놀이 공원.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/11/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, arr[10000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    cin >> arr[i];
    long long lo = 0, hi = 2e13;
    long long num = 0, mins = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long sum = 0;
        for (int i = 0; i < m; ++i)
        sum += mid / arr[i] + 1;
        if (sum < n) {
            lo = mid + 1;
            num = sum;
        }
        else {
            hi = mid - 1;
            mins = mid;
        }
    }
    int answer = 0;
    for (int i = 0; i < m; ++i) {
        if (mins % arr[i] == 0)
            num++;
        if (num == n) {
            answer = i + 1;
            break;
        }
    }
    cout << answer << endl;
    return 0;
}
