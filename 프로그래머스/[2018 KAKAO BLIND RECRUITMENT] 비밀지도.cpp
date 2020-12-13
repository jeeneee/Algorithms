//
//  [2018 KAKAO BLIND RECRUITMENT] 비밀지도.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; ++i) {
        int num = arr1[i] | arr2[i];
        string s;
        for (int j = n-1; j >= 0; --j) {
            if (num - pow(2, j) >= 0) {
                num -= pow(2, j);
                s += '#';
            } else {
                s += ' ';
            }
        }
        answer.push_back(s);
    }
    return answer;
}
