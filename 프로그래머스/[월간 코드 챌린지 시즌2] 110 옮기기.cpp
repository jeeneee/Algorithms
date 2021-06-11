#include <string>
#include <vector>
#include <stack>

using namespace std;

string go(string str) {
    string ret;
    stack<char> st;
    int cnt = 0;
    char a, b, c;
    for (auto ch : str) {
        st.push(ch);
        c = st.top();
        if (c == '0' && st.size() >= 3) {
            st.pop();
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (a == '1' && b == '1') {
                cnt++;
            } else {
                st.push(a);
                st.push(b);
                st.push(c);
            }
        }
    }

    while (!st.empty()) {
        ret = st.top() + ret;
        st.pop();
    }
    string temp = "";
    while (cnt--) temp += "110";

    int i = ret.size() - 1;
    while (i >= 0 && ret[i] == '1') i--;
    ret.insert(i + 1, temp);

    return ret;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (auto& str : s)
        answer.push_back(go(str));
    return answer;
}