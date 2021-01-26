#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> cands;
bool chk[10];

void backTracking(int idx, string s, string& order, int num) {
    if (s.size() == num) {
        cands[s]++;
        return;
    }

    for (int i = idx; i < order.size(); i++) {
        if (!chk[i]) {
            chk[i] = true;
            backTracking(i + 1, s + order[i], order, num);
            chk[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto& order : orders) sort(order.begin(), order.end());

    for (auto num : course) {
        for (auto& order : orders) backTracking(0, "", order, num);
        int mx = 0;
        for (auto& cand : cands) mx = max(mx, cand.second);
        if (mx >= 2)
            for (auto& cand : cands)
                if (cand.second == mx) answer.push_back(cand.first);
        cands.clear();
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};
    for (auto s : solution(orders, course)) {
        cout << s << endl;
    }
    return 0;
}