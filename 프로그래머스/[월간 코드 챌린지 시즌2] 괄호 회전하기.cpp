#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, char> match;

void init() {
    match[')'] = '(';
    match['}'] = '{';
    match[']'] = '[';
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    init();
    s = s + s;

    for (int i = 0; i < n; i++) {
        vector<char> v;
        bool flag = true;
        for (int j = i; j < i + n; j++) {
            char ch = s[j];
            if (ch == '(' || ch == '{' || ch == '[')
                v.push_back(ch);
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (v.empty() || v.back() != match[ch]) {
                    flag = false;
                    break;
                }
                v.pop_back();
            }
        }
        if (flag && v.empty()) answer++;
    }
    return answer;
}