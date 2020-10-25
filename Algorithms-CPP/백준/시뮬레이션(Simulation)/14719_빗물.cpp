//
//  14719_빗물.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/10/25.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<int> v(w);
    int highest = 0, cnt = 0;
    for (int i = 0; i < w; ++i) {
        cin >> v[i];
        highest = max(highest, v[i]);
    }
    int left = 0, right = w-1;
    if (v[0] != highest) {
        for (int i = 1; i < w; ++i) {
            if (v[i] == highest) {
                left = i;
                break;
            }
            if (v[i] < v[i-1]) {
                cnt += v[i-1] - v[i];
                v[i] = v[i-1];
            }
        }
    }
    if (v[w-1] != highest) {
        for (int i = w-2; i >= 0; --i) {
            if (v[i] == highest) {
                right = i;
                break;
            }
            if (v[i] < v[i+1]) {
                cnt += v[i+1] - v[i];
                v[i] = v[i+1];
            }
        }
    }
    for (int i = left + 1; i < right; ++i)
    cnt += highest - v[i];
    cout << cnt << endl;
    return 0;
}
