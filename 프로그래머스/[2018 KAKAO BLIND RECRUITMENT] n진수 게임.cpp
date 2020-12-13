//
//  [2018 KAKAO BLIND RECRUITMENT] n진수 게임.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

const char c[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

string nBase(int x, int n) {
    string ret = "";
    if (x == 0) return "0";
    while (x) {
        ret = c[x % n] + ret;
        x /= n;
    }
    return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string s;
    for (int i = 0; i < m * t; ++i)
        s += nBase(i, n);
    for (int i = 0; i < t; ++i)
        answer += s[p + m * i - 1];
    return answer;
}
