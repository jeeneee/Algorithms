//
//  입국심사.cpp
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

long long solution(int n, vector<int> times) {
    long long lo = 1, hi = 0;
    for (auto time: times)
        hi = max(hi, (long long)time);
    hi *= n;
    long long answer = hi;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long num = 0;
        for (auto time: times)
            num += mid / time;
        if (num >= n) {
            hi = mid - 1;
		    answer = min(answer, mid);
        }
        else lo = mid + 1;
    }
    return answer;
}

int main() {
	cout << solution(6, {7, 10}) << endl;
	return 0;
}
