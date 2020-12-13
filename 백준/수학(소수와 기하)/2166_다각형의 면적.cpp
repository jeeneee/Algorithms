//
//  2166_다각형의 면적.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/22.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 CCW, 신발끈 공식
 ref: https://ko.wikipedia.org/wiki/신발끈_공식
 */

#include <iostream>
#include <vector>
using namespace std;

typedef struct _point {
    long long x;
    long long y;
} point;

int main() {
    int n;
    scanf("%d", &n);
    point *p = new point[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    
    long long temp = 0;
    
    for (int i = 0; i+1 < n; ++i) {
        temp += p[i].x * p[i+1].y;
    }
    temp += p[n-1].x * p[0].y;
    
    for (int i = 0; i+1 < n; ++i) {
        temp -= p[i].y * p[i+1].x;
    }
    temp -= p[n-1].y * p[0].x;
    
    if (temp < 0) temp *= -1;
    double ans = (double)temp * 0.5;
    printf("%.1lf\n", ans);
    
    delete []p;
    return 0;
}
