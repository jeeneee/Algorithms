//
//  10819_차이를 최대로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/24.
//  Copyright © 2019 장우진. All rights reserved.
//
/* 백트래킹 N과 M 과 비슷하다. 차이점이라면 모든 조합을 다 찾아야 한다는 것. 최대 8! */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ABS(x) ( ((x) < 0) ? -(x) : (x) )

vector<int> arr;
vector<int> picked;
bool visited[8];
int ans = 0;

void calc(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += ABS(picked[i] - picked[i-1]);
    }
    ans = max(ans, sum);
}

void pick(int toPick, int n) {
    if (toPick == 0) { calc(n); return; }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            picked.push_back(arr[i]);
            pick(toPick - 1, n);
            visited[i] = false;
            picked.pop_back();
        }
    }
}

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    pick(n, n);
    cout << ans << '\n';
    
    return 0;
}
