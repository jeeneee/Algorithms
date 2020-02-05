#include <iostream>
#include <vector>
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

vector<int> kmpSearch(const string& H, const string &N) {
    int n = (int)H.size(), m = (int)N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;
    while (begin + m <= n) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if (matched == m)
                ret.push_back(begin + 1);
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
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> res = kmpSearch(T, P);
    cout << res.size() << '\n';
    for (auto a : res)
        cout << a << ' ';
    cout << '\n';
    
    return 0;
}
