//
//  9019_DSLR.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/25.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1234567890
const int MAX = 10000;

bool visit[MAX];
queue<int> q;
vector<vector<pair<int, char> > > v(MAX);
char command[4] = {'D', 'S', 'L', 'R'};

int calc(int x, char c) {
    int nx = 0;
    switch (c) {
        case 'D':
            nx = (x * 2) % MAX;
            break;
        case 'S':
            nx = (x + 9999) % 10000;
            break;
        case 'L':
            nx = (x % 1000) * 10 + x / 1000;
            break;
        case 'R':
            nx = (x % 10) * 1000 + x / 10;
            break;
    }
    return nx;
}

void bfs(int a, int b) {
    q.push(a);
    visit[a] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == b)
            break;
        for (int i = 0; i < 4; ++i) {
            int nx = calc(x, command[i]);
            if (!visit[nx]) {
                q.push(nx);
                visit[nx] = true;
                v[nx].push_back( {x, command[i]} );
            }
        }
    }
}

void back_tracking(int a, int x) {
    vector<char> ans;
    while(true) {
        ans.push_back(v[x].front().second);
        x = v[x].front().first;
        if (x == a)
            break;
    }
    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        for (int i = 0; i < MAX; ++i)
            v[i].clear();
        while (!q.empty())
            q.pop();
        fill(visit, visit + MAX, false);
        cin >> a >> b;
        bfs(a, b);
        back_tracking(a, b);
    }
    return 0;
}
