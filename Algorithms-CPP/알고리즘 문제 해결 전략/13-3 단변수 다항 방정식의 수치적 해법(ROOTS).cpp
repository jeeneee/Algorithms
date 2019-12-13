//
//  13-3 단변수 다항 방정식의 수치적 해법(ROOTS).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/13.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const double L = 25;

double evaluate(const vector<double>& poly, double x0) {
    unsigned long n = poly.size() - 1;
    double ret = 0;
    for (int i = 0; i <= n; ++i) {
        ret += poly[n-i] * pow(x0, i);
    }
    return ret;
}

vector<double> differentiate(const vector<double>& poly) {
    unsigned long n = poly.size() - 1;
    vector<double> ret;
    for (int i = 0; i < n; ++i) {
        ret.push_back(poly[i] * (n-i));
    }
    return ret;
}

vector<double> solveNaive(const vector<double>& poly) {
    unsigned long n = poly.size() - 1;
    vector<double> ret;
    if (n == 1)
        ret.push_back(-(poly[1] / poly[0]));
    else if (n == 2) {
        double a = poly[0];
        double b = poly[1];
        double c = poly[2];
        double ans = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        double ans2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        if (ans == ans2)
            ret.push_back(ans);
        else {
            ret.push_back(min(ans, ans2));
            ret.push_back(max(ans, ans2));
        }
    }
    return ret;
}

vector<double> solve(const vector<double>& poly) {
    unsigned long n = poly.size() - 1;
    if (n <= 2) return solveNaive(poly);
    // 방정식을 미분하여 n-1차 방정식을 얻는다.
    vector<double> derivative = differentiate(poly);
    vector<double> sols = solve(derivative);
    
    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);
    vector<double> ret;
    for (unsigned long i = 0; i+1 < sols.size(); ++i) {
        double x1 = sols[i], x2 = sols[i+1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
        if (y1*y2 > 0) continue;
        if (y1 > y2) { swap(x1, x2); swap(y1, y2); }
        for (int iter = 0; iter < 100; ++iter) {
            double mx = (x1 + x2) / 2.0;
            double my = evaluate(poly, mx);
            if (y1*my > 0) {
                y1 = my;
                x1 = mx;
            } else {
                y2 = my;
                x2 = mx;
            }
        }
        ret.push_back((x1 + x2) / 2.0);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<double> poly(n+1);
        for (int i = 0; i < n+1; ++i) {
            cin >> poly[i];
        }
        vector<double> ret = solve(poly);
        
        for (auto a : ret) {
            printf("%.12lf ", a);
        }
        printf("\n");
    }
    return 0;
}
