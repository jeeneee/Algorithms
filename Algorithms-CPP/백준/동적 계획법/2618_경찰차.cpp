//
//  2618_경찰차.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/27.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 TOP-DOWN 방식. solution 함수를 다시 복습하자.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;

struct Pos {
    int x, y;
};
    // 두 경찰차에 주어지는 사건의 위치(처음 위치만 다름) = 두 경찰차의 위치
Pos pol[MAX], pol2[MAX];
    // dp[i][j]에서 i는 fir이 맡고있는 사건 넘버, j는 sec이 맡고있는 사건 넘버이며, 값은 최소 거리
int dp[MAX][MAX];
int n, w;

    // args : case number
int solution(int c, int c2) {
    if (c == w || c2 == w)
        return 0;
    int& ref = dp[c][c2];
    if (ref != -1)
        return ref;
    
    int next_c = max(c, c2) + 1;
    int d = abs(pol[c].x - pol[next_c].x) + abs(pol[c].y - pol[next_c].y);
    d += solution(next_c, c2);
    
    int d2 = abs(pol2[c2].x - pol2[next_c].x) + abs(pol2[c2].y - pol2[next_c].y);
    d2 += solution(c, next_c);
    
    return ref = min(d, d2);
}

vector<int> v;
void tracking(int c, int c2) {
    if (c == w || c2 == w)
        return;
    
    int next_c = max(c, c2) + 1;
    int d = abs(pol[c].x - pol[next_c].x) + abs(pol[c].y - pol[next_c].y);
    d += dp[next_c][c2];
    
    int d2 = abs(pol2[c2].x - pol2[next_c].x) + abs(pol2[c2].y - pol2[next_c].y);
    d2 += dp[c][next_c];
    
    if (d < d2) {
        v.push_back(1);
        tracking(next_c, c2);
    } else {
        v.push_back(2);
        tracking(c, next_c);
    }
}

int main() {
    int x, y;
    scanf("%d %d", &n, &w);
    pol[0] = {1, 1};
    pol2[0] = {n, n};
    for (int i = 1; i <= w; ++i) {
        scanf("%d %d", &x, &y);
        pol[i] = pol2[i] = {x, y};
    }
    memset(dp, -1, sizeof(dp));
    
    printf("%d\n", solution(0, 0));
    
    tracking(0, 0);
    
    for (int a : v)
        printf("%d\n", a);
    
    return 0;
}
