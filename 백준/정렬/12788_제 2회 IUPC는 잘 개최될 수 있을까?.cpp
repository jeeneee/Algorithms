//
//  12788_제 2회 IUPC는 잘 개최될 수 있을까?.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k, x;
    vector<int> v;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    int ans = 0, sum = 0;
    bool flag = false;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        sum += *it;
        ++ans;
        if (sum >= m * k) {
            flag = true;
            break;
        }
    }
    
    if (flag)
        cout << ans << endl;
    else
        cout << "STRESS" << endl;
    
    return 0;
}
