//
//  1701_Cubeditor.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/05.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N) {
    int m = (int)N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    // getPartialMatch 함수를 통해 생성된 배열(pi)는 본래 인덱스 0부터 계산된 배열이므로,
    // 입력받은 문자열의 모든 부분 문자열을 다 계산해줘야 한다.
    for (int i = 0; i < s.size(); ++i) {
        string sub_s = s.substr(i, s.size());
        vector<int> failure_function = getPartialMatch(sub_s);
        for (auto a : failure_function)
            ans = max(ans, a);
    }
    cout << ans << endl;
    return 0;
}
