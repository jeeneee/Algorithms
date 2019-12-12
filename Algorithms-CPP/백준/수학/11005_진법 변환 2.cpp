//
//  11005_진법 변환 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/12.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string ans;
    int n, b;
    cin >> n >> b;
    while (n) {
        int mod = n % b + 48;
        if (mod > 57) mod += 7;
        ans.push_back(mod);
        n /= b;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
