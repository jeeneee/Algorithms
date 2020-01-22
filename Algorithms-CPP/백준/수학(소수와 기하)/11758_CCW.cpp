//
//  11758_CCW.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/21.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 ref: https://www.acmicpc.net/blog/view/27
 */
#include <iostream>
using namespace std;

int main() {
    int ans;
    int x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    int s = (x[1]-x[0]) * (y[2]-y[0]) - (y[1]-y[0]) * (x[2]-x[0]);
    
    if (s > 0)
        ans = 1;
    else if (s < 0)
        ans = -1;
    else
        ans = 0;
    
    cout << ans << endl;
    
    return 0;
}
