//
//  징검다리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/10.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
    int answer = 0;
    int lo = 1, hi = distance;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int prev = 0, cnt = 0;
        for (int rock: rocks) {
            if (rock - prev < mid) ++cnt;
            else prev = rock;
        }
        if (distance - prev < mid) ++cnt;
        if (cnt <= n) {
            lo = mid + 1;
            answer = max(answer, mid);
        }
        else hi = mid - 1;
    }
    
    return answer;
}

int main() {
	cout << solution(25, {2, 14, 11, 21, 17}, 2) << endl;
	return 0;
}
