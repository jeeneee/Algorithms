//
//  4354_문자열 제곱.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/05.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while (1) {
        cin >> s;
        if (s == ".")
            break;
        
        int len = (int)s.length();
        vector<int> pi = getPartialMatch(s);
        
        // 팰린드롬
        if (pi[len-1] == 0 || pi[len-1] % (len - pi[len-1]))
            cout << 1 << '\n';
        else
            cout << len / (len - pi[len-1]) << '\n';
    }
    return 0;
}
