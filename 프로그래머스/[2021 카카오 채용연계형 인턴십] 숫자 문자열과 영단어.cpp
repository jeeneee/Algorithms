#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const string eng[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
unordered_map<string, int> map;

void init() {
    for (int i = 0; i < 10; i++) {
        map[eng[i]] = i + 1;
    }
}

int solution(string s) {
    int answer = 0;
    init();
    string str = "";
    for (auto& c : s) {
        if (isdigit(c)) {
            answer = answer * 10 + c - '0';
            continue;
        }
        str += c;
        if (map[str]) {
            answer = answer * 10 + map[str] - 1;
            str = "";
        }
    }
    return answer;
}

int main() {
    string s = "onetwozero";
    cout << solution(s) << endl;
}
