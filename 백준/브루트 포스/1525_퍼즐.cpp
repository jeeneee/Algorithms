//
//  1525_퍼즐.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/26.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int TARGET = 123456789;
/* up down left right */
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int start = 0;
    int num;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> num;
            if (num == 0)
                num = 9;
            start = start * 10 + num;
        }
    }
    
    map<int, int> visit;
    queue<int> q;
    visit[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == TARGET)
            break;
        
        string s_cur = to_string(cur);
        int z = (int)s_cur.find('9');
        int x = z % 3;
        int y = z / 3;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string temp = s_cur;
                swap(temp[y * 3 + x], temp[ny * 3 + nx]);
                int next = stoi(temp);
                
                if (!visit.count(next)) {
                    visit[next] = visit[cur] + 1;
                    q.push(next);
                }
                
            }
        }
    }
    
    if (!visit.count(TARGET))
        cout << -1 << endl;
    else
        cout << visit[TARGET] << endl;
    
    return 0;
}
