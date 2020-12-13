//
//  조이스틱.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/16.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(string name) {
    int n = name.size();
    int answer = 0;
    string tmp = "";
    for (int i = 0; i < n; ++i) tmp += 'A';
    int idx = 0;
    while (1) {
		cout << idx << ' ' << answer << endl;
		int d = name[idx] - 'A';
        answer += min(d, 26-d);
		name[idx] = 'A';
        if (name == tmp) break;
        int left = 1, right = 1;
        for (int i = 1; i < n; ++i) {
            if (name[(idx+i+n)%n] == 'A') ++right;
            else break;
        }
        for (int i = 1; i < n; ++i) {
            if (name[(idx-i+n)%n] == 'A') ++left;
            else break;
        }
        if (left < right) {
            answer += left;
            idx = (idx - left + n) % n;
        } else {
            answer += right;
            idx = (idx + right + n) % n;
        }
    }
    return answer;
}

int main() {
	cout << solution("JAN") << endl;
	return 0;
}
