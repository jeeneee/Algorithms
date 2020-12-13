//
//  1783_병든 나이트.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/21.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, ans;
    cin >> n >> m;
    if (n == 1)
        ans = 1;
    else if (n == 2)
        ans = min( (m-1)/2+1, 4 );
    else {
        if (m < 7)
            ans = min(m, 4);
        else
            ans = m - 2;
    }
    cout << ans << '\n';
    return 0;
}
