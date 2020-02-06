    //
    //  20-2 팰린드롬 만들기(PALINDROMIZE).cpp
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

int kmpSearch2(const string& H, const string& N) {
    int n = (int)H.size();
    vector<int> pi = getPartialMatch(N);
        // 현재 대응된 글자의 수
    int begin = 0, matched = 0;
        // 짚더미의 각 글자를 순회한다.
    while (begin < n) {
        if (matched < n && H[begin + matched] == N[matched]) {
            ++matched;
            if (begin + matched == n) {
                return (n - matched) * 2 + matched;
            }
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
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    string s, s2;
    cin >> t;
    while (t--) {
        cin >> s;
        s2.resize(s.length());
        reverse_copy(s.begin(), s.end(), s2.begin());
        cout << kmpSearch2(s, s2) << endl;
    }
    return 0;
}
