//
//  2098_외판원 순회.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/23.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 16;
const int INF = 1234567890;
int N, start = 0; // 시작 지점(순회하기 때문에 꼭 0이 아니어도 된다.)
// 비용, 방문 배열
int cost[MAX_N][MAX_N], cache[MAX_N][1<<MAX_N];

int TSP(int current, int visited) {
    // 기저 사례: 모든 도시를 순회한 경우
    if (visited == (1<<N) - 1)
        return cost[current][start] ? cost[current][start] : INF;
    // ret=현재까지 방문한 도시들에 대한 최소 비용
    int &ret = cache[current][visited];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i = 0; i < N; ++i) {
        if (visited & (1<<i)) continue;
        if (cost[current][i] == 0) continue;
        ret = min(ret, TSP(i, visited | (1<<i)) + cost[current][i]);
    }
    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
        fill_n(cache[i], 1<<N, -1);
    }
    cout << TSP(start, 1) << endl;
    return 0;
}

