//
//  네트워크.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/05.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool visited[200];

void dfs(int x, int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && computers[x][i]) {
            visited[i] = true;
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++answer;
            visited[i] = true;
            dfs(i, n, computers);
        }
    }
    return answer;
}
