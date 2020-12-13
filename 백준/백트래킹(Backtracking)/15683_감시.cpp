//
//  15683_감시.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/03.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 완전 탐색(백트래킹)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;
const int INF = 987654321;
const int dx[4] = {0, -1, 0, 1}; // right, up, left, down
const int dy[4] = {1, 0, -1, 0};


int n, m, ans = INF;
int map[MAX][MAX];
int temp_map[MAX][MAX];
vector<pair<int, int> > camera;
vector<int> angle;
bool visited[MAX][MAX][4];

void copy() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            temp_map[i][j] = map[i][j];
        }
    }
}

int check() {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (temp_map[i][j] == 0)
                ++ret;
        }
    }
    return ret;
}

void dfs(int cnt) {
    if (cnt == camera.size()) {
        for (int i = 0; i < camera.size(); ++i) {
            int x = camera[i].first;
            int y = camera[i].second;
                // 카메라 방향으로 시야를 넓힌다. angle과 다름
            for (int j = 0; j < 4; ++j) {
                if (visited[x][y][j]) {
                    int nx = x + dx[(angle[i] + j) % 4];
                    int ny = y + dy[(angle[i] + j) % 4];
                    while ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
                        if (temp_map[nx][ny] == 6)
                            break;
                        if (temp_map[nx][ny] == 0)
                            temp_map[nx][ny] = -1;
                        nx += dx[(angle[i] + j) % 4];
                        ny += dy[(angle[i] + j) % 4];
                    }
                }
            }
        }
            //        cout << endl;
            //        for (int i = 0; i < n; ++i) {
            //            for (int j = 0; j < m; ++j) {
            //                cout << temp_map[i][j] << ' ';
            //            }
            //            cout << endl;
            //        }
        ans = min(ans, check());
        copy();
        return;
    }
    
    for (int i = 0; i < 4; ++i) {
        angle.push_back(i);
        dfs(cnt + 1);
        angle.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            int x = map[i][j];
            if (1 <= x && x <= 5) {
                camera.push_back(make_pair(i, j));
                if (x == 1) {
                    visited[i][j][0] = true;
                } else if (x == 2) {
                    visited[i][j][0] = true;
                    visited[i][j][2] = true;
                } else if (x == 3) {
                    visited[i][j][0] = true;
                    visited[i][j][1] = true;
                } else if (x == 4) {
                    visited[i][j][0] = true;
                    visited[i][j][1] = true;
                    visited[i][j][2] = true;
                } else if (x == 5) {
                    visited[i][j][0] = true;
                    visited[i][j][1] = true;
                    visited[i][j][2] = true;
                    visited[i][j][3] = true;
                }
            }
        }
    }
    copy();
    dfs(0);
    cout << ans << endl;
    return 0;
}
