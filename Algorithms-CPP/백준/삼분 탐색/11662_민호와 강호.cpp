//
//  11662_민호와 강호.cpp
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

typedef struct _point {
    double x;
    double y;
} point;
point A, B, C, D;

// A -> B
pdd minho(double r) {
    return { A.x+(B.x-A.x)*r/100, A.y+(B.y-A.y)*r/100 };
}

// C -> D
pdd kangho(double r) {
    return { C.x+(D.x-C.x)*r/100, C.y+(D.y-C.y)*r/100 };
}

double distSq(pdd a, pdd b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main() {
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;
    /* lo p q hi */
    double lo = 0, hi = 100, ans = INT_MAX;
    while (hi - lo >= 1e-10) {
        double p = (2*lo + hi) / 3, q = (lo + 2*hi) / 3;
        pdd minho_p = minho(p), minho_q = minho(q);
        pdd kangho_p = kangho(p), kangho_q = kangho(q);
        double dist_p = distSq(minho_p, kangho_p);
        double dist_q = distSq(minho_q, kangho_q);
        ans = min(ans, min(dist_p, dist_q));
        if (dist_p <= dist_q) hi = q;
        else lo = p;
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << sqrt(ans);
    return 0;
}
