//
//  15954_인형들.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 큰 수를 다루기 때문에 자료형에 주의해야 한다.
 분산 계산을 O(1)의 시간복잡도로 해결하기 위해 x^2 부분합과 x 부분합 두 개를 먼저 저장했다.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

const int MAX = 500 + 1;

int num[MAX];
int psum[MAX];
long long sq_psum[MAX];
int n, k;

    // [a, b]
long double average(int a, int b) {
    return (long double)(psum[b] - psum[a-1]) / (b-a+1);
}

long double covariance(int a, int b) {
    long double m = average(a, b);
    long double ret = sq_psum[b] - sq_psum[a-1];
    ret -= 2 * m * (psum[b] - psum[a-1]);
    ret += m * m * (b-a+1);
    ret /= (b-a+1);
    return ret;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        psum[i] = psum[i-1] + num[i];
        sq_psum[i] = sq_psum[i-1] + (long long)num[i] * num[i];
    }
    long double ans = ULLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+k-1; j <= n; ++j) {
            ans = min(ans, covariance(i, j));
        }
    }
    
    cout.setf(ios::fixed);
    cout.precision(11);
    cout << sqrt(ans) << endl;
    
    return 0;
}
