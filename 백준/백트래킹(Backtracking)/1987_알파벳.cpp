//
//  1987_알파벳.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
// up down left right
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int N, M;
char board[MAX][MAX];
bool visited[26]; // alphabet
int max_cnt = 0;

void dfs(int x, int y, int cnt) {
    max_cnt = max(max_cnt, cnt);
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( (0 <= nx && nx < M) && (0 <= ny && ny < N) )
            if (!visited[board[ny][nx] - 'A']) {
                visited[board[ny][nx] - 'A'] = true;
                dfs(nx, ny, cnt + 1);
                visited[board[ny][nx] - 'A'] = false;
            }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    
    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    
    cout << max_cnt << endl;
    
    return 0;
}

/*
 2 5
 A B D E F
 B C D A G
 2 4
 CAAB
 ADCB
 */
