//
//  1107_리모컨.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/22.
//  Copyright © 2019 장우진. All rights reserved.
//
/*
    1. while문을 썼기 때문에 num이 0일 때 따로 처리해야함.
    2. 채널 N 범위가 0부터 50만이지만 0~5(6, 7, 8 등등)까지의 버튼이 고장난 경우 더 큰 수가 필요하다.
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define ABS(x) ( ((x) < 0) ? -(x) : (x) )
bool ch[10];
const int MAX = 1000000 + 1;

int oneByOne(int n) {
    return ABS(n - 100);
}

bool isPossible(int num) {
    if (num == 0)
        return ch[0];
    while (num) {
        if (!ch[num % 10])
            return false;
        num /= 10;
    }
    return true;
}

int calDigits(int num) {
    if (num == 0)
        return 1;
    int cnt = 0;
    while (num) {
        num /= 10;
        cnt++;
    }
    return cnt;
}

int byDirectly(int n) {
    int min_cnt = 987654321;
    for (int i = 0; i < MAX; ++i) {
        int cnt = 0;
        if (isPossible(i)) {
            cnt += calDigits(i);
            cnt += ABS(n - i);
            min_cnt = min(min_cnt, cnt);
        }
    }
    return min_cnt;
}

int main() {
    int n, m;
    fill(ch, ch + 10, true);
    cin >> n >> m;
    int ch_num;
    for (int i = 0; i < m; ++i) {
        cin >> ch_num;
        ch[ch_num] = false;
    }
    cout << min(oneByOne(n), byDirectly(n)) << '\n';
    
    return 0;
}
