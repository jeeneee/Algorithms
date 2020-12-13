//
//  9252_LCS 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int dp[MAX][MAX];
string a, b, ans;

void tracking(int i, int j) {
    int &ref = dp[i][j];
    if (ref == 0)
        return;
    
    // 왼쪽이나 위에서 온 것이 아니면 대각선에서 온 것이다.
    if (ref != dp[i-1][j] && ref != dp[i][j-1]) {
        ans.push_back(b[j-1]);
        tracking(i-1, j-1);
    } else if (ref == dp[i][j-1]) {  // 왼쪽
        tracking(i, j-1);
    } else if (ref == dp[i-1][j]) {  // 위
        tracking(i-1, j);
    }
}

int main() {
    cin >> a >> b;
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[a.length()][b.length()] << endl;
    
    tracking((int)a.length(), (int)b.length());
    
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    
    return 0;
}
