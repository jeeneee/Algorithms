//
//  5014_스타트링크.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/26.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000000;
bool visited[MAX + 1];

int main() {
    int f, s, g, u, d;
    queue<int> q;
    cin >> f >> s >> g >> u >> d;
    
    int cnt = 0;
    bool flag = false;
    q.push(s);
    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            int cur = q.front();
            q.pop();
            if (cur == g) {
                flag = true;
                break;
            }
            if (!visited[cur]) {
                visited[cur] = true;
                if (cur + u <= MAX)
                    q.push(cur + u);
                if (cur - d >= 0)
                    q.push(cur - d);
            }
        }
        if (flag)
            break;
        ++cnt;
    }
    
    if (flag)
        cout << cnt << endl;
    else
        cout << "use the stairs" << endl;
    
    return 0;
}
