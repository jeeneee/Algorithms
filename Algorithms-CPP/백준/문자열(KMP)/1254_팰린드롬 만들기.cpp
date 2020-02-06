//
//  1254_팰린드롬 만들기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// H = Haystack, N = Needle, n = H_size, m = N_size
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

int kmpSearch(const string& H, const string& N) {
    vector<int> pi = getPartialMatch(N);
    int n = (int)H.size();
    int begin = 0, matched = 0;
    while (begin < n) {
        if (H[begin + matched] == N[matched]) {
            ++matched;
            if (begin + matched == n)
                return (n - matched) * 2 + matched;
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
    return 2 * n - 1;
}

int main() {
    string s, s2;
    cin >> s;
    s2.resize(s.size());
    reverse_copy(s.begin(), s.end(), s2.begin());
    cout << kmpSearch(s, s2) << '\n';
    return 0;
}
