//
//  2458_키 순서.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/18.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 501;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    bool height[MAX][MAX];
    int n, m;
    cin >> n >> m;
    // init height
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            if (i == j) height[i][j] = 1;
            else height[i][j] = 0;
        }
    }
    int a, b;
    while (m--) {
        cin >> a >> b;
        height[a][b] = 1;
    }
    
    // Floyd Warshall
    for (int k = 1; k < n+1; ++k) {
        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                if (height[i][k] && height[k][j])
                    height[i][j] = 1;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 1; i < n+1; ++i) {
        bool flag = false;
        for (int j = 1; j < n+1; ++j) {
            if (!height[i][j] && !height[j][i])
                flag = true;
        }
        if (!flag) cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}
