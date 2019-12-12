//
//  1260_DFS와 BFS.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/14.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int MAX = 1001;

bool visit[MAX];
vector<int> a[MAX];
queue<int> q;

void DFS(int x) {
    if (visit[x])
        return;
    visit[x] = true;
    printf("%d ", x);
    for (int i = 0; i < int(a[x].size()); i++) {
        int y = a[x][i];
        DFS(y);
    }
}

void BFS(int start) {
    q.push(start);
    visit[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for (int i = 0; i < int(a[x].size()); i++) {
            int y = a[x][i];
            if (!visit[y]) {
                q.push(y);
                visit[y] = true;
            }
        }
    }
}

int main() {
    int N, M, V, from, to;
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &from, &to);
        a[from].push_back(to);
        a[to].push_back(from);
    }
    for (int i = 1; i <= N; i++) {
        sort(a[i].begin(), a[i].end());
    }
    DFS(V);
    puts("");
    fill(visit, visit + MAX, 0);
    BFS(V);
    puts("");
}

