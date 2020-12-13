//
//  [2018 KAKAO BLIND RECRUITMENT] 프렌즈 4블록.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int move(int n, int m, vector<string>& board) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ret = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m-1; ++j) {
            if (board[i][j] == ' ') continue;
            if (board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1]
                && board[i][j] == board[i+1][j+1]) {
                visited[i][j] = visited[i][j+1] = true;
                visited[i+1][j] = visited[i+1][j+1] = true;
                
            }
        }
    }
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (visited[i][j]) {
                ++ret;
                for (int k = i-1; k >= 0; --k) {
                    board[k+1][j] = board[k][j];
                    board[k][j] = ' ';
                }
            }
        }
    }
    return ret;
}

int solution(int n, int m, vector<string> board) {
    int answer = 0;
    while (1) {
        int ret = move(n, m, board);
        if (ret == 0) break;
        answer += ret;
    }
    return answer;
}
