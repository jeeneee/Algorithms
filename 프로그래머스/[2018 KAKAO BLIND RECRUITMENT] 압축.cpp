//
//  [2018 KAKAO BLIND RECRUITMENT] 압축.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    const string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, int> dict;
    for (int i = 0; i < 26; ++i)
        dict[s.substr(i, 1)] = i + 1;
    int i = 0, j = 0, idx = 27;
    while (i < msg.size()) {
        for (j = i; j < msg.size(); ++j) {
            if (dict.count(msg.substr(i, j - i + 1))) continue;
            break;
        }
        answer.push_back(dict[msg.substr(i, j - i)]);
        dict[msg.substr(i, j - i + 1)] = idx++;
        i = j;
    }
    return answer;
}
