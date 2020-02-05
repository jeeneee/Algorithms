//
//  15684_사다리 조작.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/04.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool map[32][12];
    // n=세로선, m=사다리 수, h=가로선
int n, m, h;
int ans;
bool flag;

bool down(int x, int y) {
    int i = y;
    int j = x;
    while (i <= h) {
        if (j < n && map[i][j]) ++j;
        else if (j > 1 && map[i][j-1]) --j;
        ++i;
    }
    if (j == x)
        return true;
    else
        return false;
}

void dfs(int x, int y, int cnt) {
    if (flag)
        return;
    if (cnt == ans) {
        for (int i = 1; i <= n; ++i) {
            if (!down(i, 1))
                return;
        }
        flag = true;
        return;
    }
    for (int i = y; i <= h; ++i) {
        for (int j = 1; j < n; ++j) {
            if (!map[i][j-1] && !map[i][j] && !map[i][j+1]) {
                map[i][j] = 1;
                dfs(j, i, cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        map[a][b] = 1;
    }
    for (int i = 0; i <= 3; ++i) {
        ans = i;
        dfs(1, 1, 0);
        if (flag) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
