//
//  12851_숨바꼭질 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
bool visited[MAX];
int n, k;

int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    int t = 0, num = 0;
    bool flag = false;
    
    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; ++i) {
            int x = q.front();
            q.pop();
            if (x == k) {
                ++num;
                flag = true;
            }
            visited[x] = true;
            int nx[3] = {x - 1, x + 1, x * 2};
            for (int j = 0; j < 3; ++j) {
                if (0 <= nx[j] && nx[j] <= MAX && !visited[nx[j]])
                    q.push(nx[j]);
            }
        }
        if (flag)
            break;
        ++t;
    }
    cout << t << endl;
    cout << num << endl;
    
    return 0;
}
