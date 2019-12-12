//
//  2667_단지 번호 붙이기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/17.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 오른쪽 왼쪽 아래 위 */
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int MAX = 27; // padding
int map[MAX][MAX];
int n, cnt;

void dfs(int r, int c) {
    map[r][c] = 0;
    ++cnt;
    for (int i = 0; i < 4; ++i) {
        if (map[ r + dy[i] ][ c + dx[i] ])
            dfs(r + dy[i], c + dx[i]);
    }
}

int main() {
    vector<int> ans;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%1d", &map[i][j]);
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (map[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
    
    sort(ans.begin(), ans.end());
    
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}
