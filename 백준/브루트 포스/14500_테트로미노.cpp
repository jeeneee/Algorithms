//
//  14500_테트로미노.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/30.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 500;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int map[MAX][MAX];
bool visited[MAX][MAX];
int max_area;
int n, m;
int ans;

inline bool pass(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void Area(int x, int y, int current_area, int cnt) {
    visited[x][y] = true;
    if (cnt == 3) {
        ans = max(ans, current_area);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!visited[nx][ny] && pass(nx, ny)) {
            Area(nx, ny, current_area + map[nx][ny], cnt + 1);
            visited[nx][ny] = false;
        }
    }
}

void Shape1(int x, int y)
{
    int temp = 0;
    temp = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1];
    ans = max(ans, temp);
}

void Shape2(int x, int y)
{
    int temp = 0;
    temp = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
    ans = max(ans, temp);
}

void Shape3(int x, int y)
{
    int temp = 0;
    temp = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
    ans = max(ans, temp);
}

void Shape4(int x, int y)
{
    int temp = 0;
    temp = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1];
    ans = max(ans, temp);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            memset(visited, false, sizeof(visited));
            Area(i, j, map[i][j], 0);
                // ㅗ, ㅜ, ㅏ, ㅓ
            if (i - 1 >= 0 && j + 2 < m) Shape1(i, j);
            if (j + 2 < m && i + 1 < n) Shape2(i, j);
            if (i + 2 < n && j + 1 < m) Shape3(i, j);
            if (i + 1 < n && i - 1 >= 0 && j + 1 < m) Shape4(i, j);
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
