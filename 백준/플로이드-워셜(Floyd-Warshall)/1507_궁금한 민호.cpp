//
//  1507_궁금한 민호.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/20.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;

int main() {
    int graph[MAX][MAX];
    bool route[MAX][MAX];
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    
    for (int i = 0; i < MAX; ++i)
        fill_n(route[i], MAX, true);
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i == k || k == j)
                    continue;
                else if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                else if (graph[i][j] == graph[i][k] + graph[k][j]) {
                    route[i][j] = false;
                }
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (route[i][j])
                res += graph[i][j];
    
    cout << res / 2 << endl;
        
    return 0;
}
