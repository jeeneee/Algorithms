//
//  [2017 카카오코드 예선] 카카오프렌즈 컬러링북.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int cnt;

void dfs(int color, int x, int y, int m, int n, vector<vector<int>>& picture) {
    picture[x][y] = 0;
    ++cnt;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( (0 <= nx && nx < m) && (0 <= ny && ny < n) )
            if (color == picture[nx][ny])
                dfs(color, nx, ny, m, n, picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (picture[i][j] != 0) {
                cnt = 0;
                ++number_of_area;
                dfs(picture[i][j], i, j, m, n, picture);
                max_size_of_one_area = max(max_size_of_one_area, cnt);
            }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}

int main() {
    int m = 6;
    int n = 4;
    vector<vector<int>> picture(m, vector<int>(n));
    
    picture = {
        {1, 1, 1, 0},
        {1, 2, 2, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 3},
        {0, 0, 0, 3}
    };
    
    vector<int> ans = solution(m, n, picture);
    for (auto a : ans)
        cout << a << endl;
    
    
    return 0;
}
