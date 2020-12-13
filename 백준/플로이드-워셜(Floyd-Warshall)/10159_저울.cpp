//
//  10159_저울.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/18.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    bool weight[MAX][MAX];
    int n, m;
    cin >> n >> m;
    // init weight
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            weight[i][j] = 0;
        }
    }
    int a, b;
    while (m--) {
        cin >> a >> b;
        weight[a][b] = 1;
    }
    
    // Floyd Warshall
    for (int k = 1; k < n+1; ++k) {
        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                if (weight[i][k] && weight[k][j])
                    weight[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i < n+1; ++i) {
        int cnt = 0;
        for (int j = 1; j < n+1; ++j) {
            if (!weight[i][j] && !weight[j][i])
                cnt++;
        }
        cout << cnt-1 << '\n';
    }
    
    return 0;
}
