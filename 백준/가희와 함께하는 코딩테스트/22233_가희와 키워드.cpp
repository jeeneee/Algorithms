#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

unordered_set<string> keyword;
int n, m;

vector<string> extract(string str) {
    istringstream ss(str);
    vector<string> ret;
    while (ss.good()) {
        string s;
        getline(ss, s, ',');
        ret.push_back(s);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        keyword.insert(s);
    }

    int cnt = n;
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (auto word : extract(s)) {
            if (keyword.count(word)) {
                cnt--;
                keyword.erase(word);
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
