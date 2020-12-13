//
//  N으로 표현.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/03.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    map<int, set<int>> m;

    int temp = N;
    for (int i = 1; i <= 8; ++i) {
        m[i].insert(temp);
        temp = temp * 10 + N;
    }
        
    for (int i = 2; i <= 8; ++i) {
        for (int j = 1; j < i; ++j) {
            int k = i - j;
            for (auto a : m[j]) {
                for (auto b : m[k]) {
                    m[i].insert(a + b);
                    m[i].insert(a * b);
                    if (a - b > 0) m[i].insert(a - b);
                    if (b - a > 0) m[i].insert(b - a);
                    if (a > 0) m[i].insert(b / a);
                    if (b > 0) m[i].insert(a / b);
                }
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= 8 && !flag; ++i)
        for (auto a : m[i])
            if (a == number) {
                answer = i;
                flag = true;
                break;
            }
    return answer;
}

int main() {
    cout << solution(5, 12) << endl;
    return 0;
}
