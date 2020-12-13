//
//  14891_톱니바퀴.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/03.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 처음에는 비트마스크를 이용해 풀려고 했지만 코드가 복잡해져 덱을 이용했다.
 덱은 앞 요소와 뒤 요소를 처리하는 데에 상수 시간 밖에 걸리지 않고,
 배열처럼 중간 요소에 직접 접근할 수 있어 이 문제를 푸는 데 용이하다.
 */
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX = 4;
deque<int> dq[MAX];
vector<int> direction(MAX);

void toRight(int n, int d) {
    for (int i = n + 1; i < MAX; ++i) {
        if (dq[i-1][2] == dq[i][6])
            return;
        else {
            d = d * -1;
            direction[i] = d;
        }
    }
}

void toLeft(int n, int d) {
    for (int i = n-1; i >= 0; --i) {
        if (dq[i+1][6] == dq[i][2])
            return;
        else {
            d = d * -1;
            direction[i] = d;
        }
    }
}

void mov(int n, int d) {
    int x;
    if (d == -1) {       // 반시계 방향
        x = dq[n].front();
        dq[n].pop_front();
        dq[n].push_back(x);
    } else if (d == 1) { // 시계 방향
        x = dq[n].back();
        dq[n].pop_back();
        dq[n].push_front(x);
    }
}

int main() {
    string s;
    for (int i = 0; i < 4; ++i) {
        cin >> s;
        for (auto c : s)
            dq[i].push_back(c - 48);
    }
    int k, n, d;
    cin >> k;
    while (k--) {
        for (int i = 0; i < MAX; ++i)
            direction[i] = 0;
        cin >> n >> d;
        n -= 1;
        direction[n] = d;
        toLeft(n, d);
        toRight(n, d);
        for (int i = 0; i < MAX; ++i) {
            mov(i, direction[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < MAX; ++i) {
        ans += dq[i].front() * (1 << i);
    }
    cout << ans << endl;
    
    return 0;
}
