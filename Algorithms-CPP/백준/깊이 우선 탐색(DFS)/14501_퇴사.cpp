//
//  14501_퇴사.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/30.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 15 + 1;
int t[MAX], p[MAX];
int n, ans;

void dfs(int cur, int profit) {
    if (cur == n+1) {
        ans = max(ans, profit);
        return;
    }
    dfs(cur+1, profit);
    if (cur + t[cur] <= n+1)
        dfs(cur + t[cur], profit + p[cur]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> p[i];
    dfs(1, 0);
    cout << ans << endl;
    
    return 0;
}
