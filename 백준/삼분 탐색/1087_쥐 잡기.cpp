//
//  1087_쥐 잡기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/19.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<double, double> pdd;

int mouse[50][4]; // px, py, vx, vy

// t초 후의 위치(x, y)
pdd pos(int idx, double t) {
    return { mouse[idx][0] + mouse[idx][2] * t,
        mouse[idx][1] + mouse[idx][3] * t };
}

// t초 후의 쥐들의 위치를 얻어 우리의 최대 길이를 구한다.
double findLen(double t, int n) {
    double max_x = INT_MIN, max_y = INT_MIN;
    double min_x = INT_MAX, min_y = INT_MAX;
    for (int i = 0; i < n; ++i) {
        max_x = max(max_x, pos(i, t).first);
        min_x = min(min_x, pos(i, t).first);
        max_y = max(max_y, pos(i, t).second);
        min_y = min(min_y, pos(i, t).second);
    }
    return max(max_x - min_x, max_y - min_y);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> mouse[i][j];
        }
    }
    /* 0초 ~ 2000초 사이에서 삼분 탐색 (입력이 -1000~1000 사이의 정수이기 때문) */
    double lo = 0, hi = 2000, ans = INT_MAX;
    while (hi - lo >= 1e-12) {
        double p = (2*lo + hi) / 3, q = (lo + 2*hi) / 3;
        double len_p = findLen(p, n);
        double len_q = findLen(q, n);
        ans = min(ans, min(len_p, len_q));
        if (len_p <= len_q) hi = q;
        else lo = p;
    }
    cout.setf(ios::fixed);
    cout.precision(12);
    cout << ans << '\n';
    
    return 0;
}
