//
//  1963_소수 경로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/24.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int isPrime[MAX];
bool visit[MAX];
queue<int> q;

void findPrime() {
    fill(isPrime, isPrime + MAX, true);
    for (int i = 2; i * i <= MAX; ++i) {
        if (isPrime[i])
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
    }
}

void bfs(int a, int b) {
    int cnt = 0;
    bool flag = false;
    q.push(a);
    visit[a] = true;
    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            int i_x = q.front();
            string s_x = to_string(i_x);
            q.pop();
            if (i_x == b) {
                flag = true;
                break;
            }
            for (int j = 0; j < 4; ++j) {
                string temp_x = s_x;
                for (int k = 0; k < 10; ++k) {
                    if (j == 0 && k == 0) continue;
                    temp_x[j] = k + '0';
                    int new_x = stoi(temp_x);
                    if (isPrime[new_x] && !visit[new_x]) {
                        q.push(new_x);
                        visit[new_x] = true;
                    }
                }
            }
        }
        if (flag)
            break;
        cnt++;
    }
    if (flag) cout << cnt << '\n';
    else cout << "Impossible" << '\n';
}

int main() {
    int t, a, b;
    findPrime();
    cin >> t;
    while (t--) {
        while (!q.empty()) {
            q.pop();
        }
        fill(visit, visit + MAX, false);
        cin >> a >> b;
        bfs(a, b);
    }
    return 0;
}
