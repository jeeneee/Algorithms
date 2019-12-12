//
//  10971_외판원 순회 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/24.
//  Copyright © 2019 장우진. All rights reserved.
//
/* 130ms가 나왔다. 어딜 고쳐야 할지 모르겠다. 나중에 검토해야 함. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10;

int costs[MAX][MAX];
bool visited[MAX];
int ans = 1234567890;
int n;

void go(int toGo, int cur_costs, int cur_city, int start_city) {
    if (toGo == 0) {
        if (costs[cur_city][start_city] == 0) return;
        cur_costs += costs[cur_city][start_city];
        ans = min(ans, cur_costs);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (j != start_city && !visited[j] && costs[cur_city][j] > 0) {
            visited[j] = true;
            cur_costs += costs[cur_city][j];
            go(toGo - 1, cur_costs, j, start_city);
            visited[j] = false;
            cur_costs -= costs[cur_city][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> costs[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
        go(n-1, 0, i, i);
    cout << ans << '\n';
    
    return 0;
}
