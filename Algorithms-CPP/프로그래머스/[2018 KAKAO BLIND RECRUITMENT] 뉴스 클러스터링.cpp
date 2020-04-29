//
//  [2018 KAKAO BLIND RECRUITMENT] 뉴스 클러스터링.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;
    double total = 0, dup = 0;
    map<string, int> m;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    // str1
    for (int i = 0; i < str1.size()-1; ++i) {
        if (str1[i] < 'a' || str1[i] > 'z') continue;
        if (str1[i+1] < 'a' || str1[i+1] > 'z') continue;
        string s = str1.substr(i, 2);
        total++;
        if (m.count(s)) m[s]++;
        else m.insert( {s, 1} );
    }
    //str2
    for (int i = 0; i < str2.size()-1; ++i) {
        if (str2[i] < 'a' || str2[i] > 'z') continue;
        if (str2[i+1] < 'a' || str2[i+1] > 'z') continue;
        string s = str2.substr(i, 2);
        if (m.count(s)) {
            if (m[s] > 0) {
                m[s]--;
                dup++;
            } else {
                total++;
            }
        } else {
            total++;
        }
    }
    if (total != 0)
        answer *= (dup / total);
    return answer;
}
