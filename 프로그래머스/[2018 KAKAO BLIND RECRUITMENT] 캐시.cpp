//
//  [2018 KAKAO BLIND RECRUITMENT] 캐시.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> l;
    if (cacheSize == 0) return cities.size() * 5;
    for (auto& city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        bool flag = false;
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (*it == city) {
                flag = true;
                l.erase(it);
                l.push_back(*it);
                answer += 1;
                break;
            }
        }
        if (!flag) {
            if (l.size() == cacheSize)
                l.pop_front();
            l.push_back(city);
            answer += 5;
        }
    }
    return answer;
}

int main() {
    cout << solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << endl;
   return 0;
}
