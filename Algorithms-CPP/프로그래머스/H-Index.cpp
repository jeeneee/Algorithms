//
//  H-Index.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/03.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), [](int a, int b) {
        return a > b;
    });
    for (int h = citations[0]; h >= 0; --h) {
        int i;
        for (i = 0; i < citations.size(); ++i)
            if (citations[i] < h) break;
        if (i >= h) {
            answer = h;
            break;
        }
    }
    return answer;
}
