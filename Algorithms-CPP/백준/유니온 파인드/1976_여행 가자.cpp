//
//  1976_여행 가자.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 06/10/2019.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 201
using namespace std;

int par[MAX];

int find (int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, flag;
    cin >> n >> m;
    //initialize parents
    for (int i = 1; i <= n; ++i)
        par[i] = i;
    // input route
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> flag;
            if (flag) {
                par[find(j)] = find(i);
            }
        }
    }
    int prev_city = -1, city;
    for (int i = 1; i <= m; ++i) {
        cin >> city;
        if (prev_city > 0) {
            if (find(prev_city) != find(city)) {
                cout << "NO" << endl;
                return 0;
            }
        }
        prev_city = city;
    }
    cout << "YES" << endl;
    
    return 0;
}
