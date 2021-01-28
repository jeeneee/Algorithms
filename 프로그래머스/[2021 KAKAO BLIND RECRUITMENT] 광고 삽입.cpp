#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 360000;
long long psum[MAX];

int toInt(string t) {
    int h, m, s;
    sscanf(t.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

string toString(int t) {
    string h = to_string(t / 3600);
    string m = to_string((t % 3600) / 60);
    string s = to_string(t % 60);
    if (h.size() < 2) h = "0" + h;
    if (m.size() < 2) m = "0" + m;
    if (s.size() < 2) s = "0" + s;
    return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int n = logs.size();
    int playTime = toInt(play_time);
    int advTime = toInt(adv_time);

    for (int i = 0; i < n; i++) {
        psum[toInt(logs[i].substr(0, 8))]++;
        psum[toInt(logs[i].substr(9))]--;
    }

    for (int i = 1; i < playTime; i++) psum[i] += psum[i - 1];

    for (int i = 1; i < playTime; i++) psum[i] += psum[i - 1];

    long long mx = psum[advTime - 1], start = 0;
    for (int i = advTime; i < playTime; i++) {
        if (psum[i] - psum[i - advTime] > mx) {
            mx = psum[i] - psum[i - advTime];
            start = i - advTime + 1;
        }
    }

    return toString(start);
}

int main() {
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00",
                           "00:25:50-00:48:29", "01:30:59-01:53:29",
                           "01:37:44-02:02:30"};
    cout << solution("02:03:55", "00:14:15", logs) << endl;
    return 0;
}