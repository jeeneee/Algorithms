//
//  1208_부분수열의 합 2.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/29.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
 + 비트마스크
 우선 배열을 반으로 쪼개 두 배열의 모든 부분 집합의 합을 구한 후,
 투 포인터를 이용해 해결하였다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, S;
    cin >> N >> S;
    
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    
    int half = N / 2;
    
    
    // 앞 배열의 모든 부분집합
    vector<int> first(1 << (N - half));
    for (int i = 0; i < 1 << (N - half); ++i) {
        for (int j = 0; j < N - half; ++j) {
            if (i&(1 << j))
                first[i] += v[j];
        }
    }
    
    // 뒷 배열의 모든 부분집합
    vector<int> second(1 << half);
    for (int i = 0; i < 1 << half; ++i) {
        for (int j = 0; j < half; ++j) {
            if (i&(1 << j))
                second[i] += v[j + (N - half)];
        }
    }
    
    // first: 오름차 순, second: 내림차 순
    sort(first.begin(), first.end());
    sort(second.begin(), second.end(), greater<int>());
    
    // 투 포인터
    int idx1 = 0;
    int idx2 = 0;
    long long result = 0;
    while (idx1 < 1 << (N - half) && idx2 < 1 << half) {
        if (first[idx1] + second[idx2] == S) {
            long long cnt1 = 1, cnt2 = 1;
            idx1++; idx2++;
            while (idx1 < 1 << (N - half) && first[idx1] == first[idx1 - 1]) {
                idx1++;
                cnt1++;
            }
            while (idx2 < 1 << half && second[idx2] == second[idx2 - 1]) {
                idx2++;
                cnt2++;
            }
            result += cnt1 * cnt2;
        }
        // 이를 위해 오름차 순, 내림차 순으로 정렬하였다.
        else if (first[idx1] + second[idx2] < S)
            idx1++;
        else if (first[idx1] + second[idx2] > S)
            idx2++;
    }
    
    // 0일 때 공집합이 겹치기에 하나 뺀다.
    if (S == 0)
        result--;
    cout << result << endl;
    
    return 0;
}
