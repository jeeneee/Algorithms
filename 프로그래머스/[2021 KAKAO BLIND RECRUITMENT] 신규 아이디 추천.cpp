#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string temp = "";

    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    for (char c : new_id)
        if ('a' <= c && c <= 'z' || '0' <= c && c <= '9' || strchr("-_.", c))
            temp += c;

    new_id.clear();
    for (char c : temp) {
        if (!new_id.empty() && new_id.back() == '.' && c == '.') continue;
        new_id += c;
    }

    if (new_id.front() == '.') new_id.erase(new_id.begin());
    if (new_id.back() == '.') new_id.pop_back();

    if (new_id.empty()) new_id = "a";

    if (new_id.size() > 15) new_id = new_id.substr(0, 15);
    if (new_id.back() == '.') new_id.pop_back();

    while (new_id.size() < 3) new_id += new_id.back();

    return new_id;
}

int main() {
    string new_ids[] = {"...!@BaT#*..y.abcdefghijklm", "z-+.^.",
                        "=.=", "123_.def", "abcdefghijklmn.p"};
    for (auto new_id : new_ids) {
        cout << solution(new_id) << endl;
    }
    return 0;
}