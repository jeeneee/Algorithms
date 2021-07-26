#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> priority;

struct Node {
    string filename;
    string ext;

    Node(string _filename, string _ext) : filename(_filename), ext(_ext) {}

    bool operator<(const Node& rhs) const {
        if (filename == rhs.filename) {
            int p1 = priority[ext];
            int p2 = priority[rhs.ext];
            if (p1 == p2) {
                return ext < rhs.ext;
            }
            return p1 < p2;
        }
        return filename < rhs.filename;
    }
};

Node extract(string s) {
    auto idx = s.find('.', 0);
    return Node(s.substr(0, idx), s.substr(idx + 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string s;

    cin >> n >> m;
    vector<Node> v;

    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(extract(s));
    }

    for (int i = 0; i < m; i++) {
        cin >> s;
        priority[s] = -1;
    }

    sort(v.begin(), v.end());

    for (auto node : v) {
        cout << node.filename + "." + node.ext << '\n';
    }

    return 0;
}
