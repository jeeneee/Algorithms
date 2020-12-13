//
//  1182_부분 수열의 합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//
/* 완전 탐색 O(2^N) 2^20 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
bool visited[MAX];
int arr[MAX];
vector<int> picked;
int N, S;
int ans = 0;

void pick(int toPick, int idx) {
    int sum = 0;
    if (toPick == 0) {
        for (auto &c: picked)
            sum += c;
        if (sum == S)
            ++ans;
    }
    
    for (int i = idx; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            picked.push_back(arr[i]);
            pick(toPick - 1, i);
            visited[i] = false;
            picked.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; ++i) {
        pick(i, 0);
    }
    
    cout << ans << '\n';
    
    return 0;
}
