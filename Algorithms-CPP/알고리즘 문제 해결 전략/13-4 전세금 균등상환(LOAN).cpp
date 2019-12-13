//
//  13-4 전세금 균등상환(LOAN).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/13.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 이분법
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

double balance(double amount, int duration, double rates,
               double monthlyPayment) {
    double balance = amount;
    for (int i = 0; i < duration; ++i) {
        balance *= (1 + (rates / 12.0 / 100));
        balance -= monthlyPayment;
    }
    return balance;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        double n, p; // 전세금, 연이율
        int m;  // 상환기간
        cin >> n >> m >> p;
        double lo = 0, hi = n * (1.0 + (p / 12.0) / 100.0);
        for (int i = 0; i < 100; ++i) {
            double mid = (lo + hi) / 2.0;
            if (balance(n, m, p, mid) <= 0)
                hi = mid;
            else
                lo = mid;
        }
        printf("%.10lf\n", hi);
    }
    return 0;
}
