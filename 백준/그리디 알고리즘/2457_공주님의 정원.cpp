//
//  2457_공주님의 정원.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/11/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calc(int m, int d) {
    int ret = d;
    for (int i = 0; i < m; ++i)
    ret += daysInMonth[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        v[i] = make_pair(calc(m1, d1), calc(m2, d2));
    }
    
    sort(v.begin(), v.end());
    
    int s = calc(3, 1);
    int e = calc(11, 30);
    int today = 0, i = 0, cnt = 0;
    while (today <= e && i < n) {
        bool flag = false;
        for (int j = i; j < n; ++j) {
            if (v[j].first > s) break;
            flag = true;
            today = max(today, v[j].second);
            i = j + 1;
        }
        if (!flag) {
            cnt = 0;
            break;
        }
        s = today;
        cnt++;
    }
    if (today <= e) cnt = 0;
    cout << cnt << endl;
    return 0;
}
