//
//  [2018 KAKAO BLIND RECRUITMENT] 다트 게임.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/02.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0, prev = 0, now = 0;
    for (int i = 0; i < dartResult.size(); ++i) {
        if ('0' <= dartResult[i] && dartResult[i] <= '9') {
            prev = now;
            now = 0;
            if (dartResult[i+1] == '0') {
                now = 10;
                ++i;
            } else {
                now = dartResult[i] - '0';
            }
        } else if (dartResult[i] == 'S') {
            answer += now;
        } else if (dartResult[i] == 'D') {
            now = now * now;
            answer += now;
        } else if (dartResult[i] == 'T') {
            now = now * now * now;
            answer += now;
        } else if (dartResult[i] == '*') {
            answer += prev + now;
            now *= 2;
        } else if (dartResult[i] == '#') {
            answer -= now * 2;
            now *= -1;
        }
    }
    return answer;
}
