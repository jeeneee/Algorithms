//
//  3108_로고.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/26.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int N;
const int MAX = 1000;

typedef struct rect {
    int x1, y1, x2, y2;
} Rect;

Rect r[MAX + 1];
bool visit[MAX + 1];

bool isOverlap(const Rect a, const Rect b) {
    if (a.x1 > b.x1 && a.y1 > b.y1 && a.x2 < b.x2 && a.y2 < b.y2) return false;
    if (a.x1 < b.x1 && a.y1 < b.y1 && a.x2 > b.x2 && a.y2 > b.y2) return false;
    if (a.x1 > b.x2 || a.y1 > b.y2 || b.x1 > a.x2 || b.y1 > a.y2) return false;
    return true;
}

void dfs(int a) {
    if (visit[a]) return;
    visit[a] = true;
    
    for (int b = 0; b < N; ++b) {
        if (isOverlap(r[a], r[b]))
            dfs(b);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> r[i].x1 >> r[i].y1 >> r[i].x2 >> r[i].y2;
    }
    
    r[N] = {0, 0, 0, 0};
    ++N;
    
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (!visit[i]) {
            dfs(i);
            ++cnt;
        }
    }
   
    cout << cnt - 1 << endl;
    
    return 0;
}
