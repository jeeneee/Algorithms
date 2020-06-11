//
//  쇠막대기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string arrangement) {
    int answer = 0, open = 0;
    for (int i = 0; i < arrangement.size(); ++i) {
        if (arrangement[i] == '(') {
            if (arrangement[i+1] == ')') {
                answer += open;
                ++i;
            }
            else ++open;
        } else {
            --open;
            ++answer;
        }
    }
    return answer;
}

int main() {
	cout << solution("()(((()())(())()))(())") << endl;
	return 0;
}
