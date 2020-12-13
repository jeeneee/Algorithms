//
//  1912_연속합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/31.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, ans = INT_MIN, sum = 0;
    cin >> n;
    for (int i = 0, tmp; i < n; ++i) {
        cin >> tmp;
        sum = max(tmp, sum + tmp);
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
