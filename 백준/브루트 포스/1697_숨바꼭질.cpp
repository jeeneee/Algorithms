//
//  1697_숨바꼭질.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/24.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 nx[j] >= 0 && nx[j] < MAX && !visit[nx[j]]에서 순서에 유의해야 한다.
 인덱스 크기를 먼저 비교해야 함!!!
 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;

queue<int> q;
bool visit[MAX];

int main() {
    int n, k, t = 0;
    cin >> n >> k;
    
    q.push(n);
    visit[n] = true;
    bool flag = false;
    
    while(!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front();
            q.pop();
            if (x == k) {
                flag = true;
                break;
            }
            int nx[3] = {x-1, x+1, x*2};
            for (int j = 0; j < 3; ++j) {
                if (nx[j] >= 0 && nx[j] < MAX && !visit[nx[j]]) {
                    visit[nx[j]] = true;
                    q.push(nx[j]);
                }
            }
        }
        if (flag)
            break;
        t++;
    }
    cout << t << '\n';
    return 0;
}
