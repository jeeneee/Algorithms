//
//  2003_수들의 합 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int start = 0;
    int end = 0;
    int ans = 0;
    int sum = 0;
    while(1) {
        if (sum >= m) sum -= arr[start++];
        else if (end == n) break;
        else sum += arr[end++];
        if (sum == m) ans++;
    }
    cout << ans << endl;
    
    delete []arr;
    return 0;
}
