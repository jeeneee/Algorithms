//
//  2875_대회 or 인턴.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/20.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k, girl, boy; // 1team: 2girl 1boy
    cin >> n >> m >> k;
    int team = 0;
    for (int i = 0; i <= k; ++i) {
        girl = n - i;
        boy = m - (k - i);
        team = max(team, min(girl / 2, boy));
    }
    cout << team << endl;
    
    return 0;
}
