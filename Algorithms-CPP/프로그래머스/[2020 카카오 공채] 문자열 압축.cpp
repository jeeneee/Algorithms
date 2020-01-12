//
//  [2020 카카오 공채] 문자열 압축.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int digits(int x) {
    int ret = 0;
    while (x) {
        ++ret;
        x /= 10;
    }
    return ret;
}

int solution(string s) {
    int answer = (int)s.length();
    for (int i = 1; i <= s.length() / 2; ++i) {
        int cnt = 1;
        int len = (int)s.length();
        for (int j = 0; j + i < s.length(); j += i) {
            if ( s.substr(j, i) == s.substr(j+i, i) ) {
                ++cnt;
                len -= i;
            } else {
                if (cnt > 1) len += digits(cnt);
                cnt = 1;
            }
        }
        if (cnt > 1) {
            len += digits(cnt);
        }
        answer = min(answer, len);
    }
    return answer;
}

int main() {
    string str[5] = {
        "aabbaccc",
        "ababcdcdababcdcd",
        "abcabcdede",
        "abcabcabcabcdededededede",
        "xababcdcdababcdcd"
    };
    
    for (int i = 0; i < 5; ++i) {
        cout << solution(str[i]) << endl;
    }
    
    return 0;
}
