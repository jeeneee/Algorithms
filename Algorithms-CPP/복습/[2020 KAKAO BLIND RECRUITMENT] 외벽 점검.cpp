//
//  [2020 KAKAO BLIND RECRUITMENT] 외벽 점검.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/08/30.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    deque<int> dq;
    for (int i = 0; i < weak.size(); ++i) dq.push_back(weak[i]);
    
    sort(dist.begin(), dist.end());
    
    for (int i = 0; i < dq.size(); ++i) {
        do {
            int w = 0, d = 0;
            for (d = 0; d < dist.size() && w < dq.size(); ++d) {
                int end = dq[w] + dist[d];
                while (w < dq.size() && dq[w] <= end) w++;
            }
            if (w == dq.size()) answer = min(answer, d);
        } while(next_permutation(dist.begin(), dist.end()));
        dq.push_back(dq.front() + n);
        dq.pop_front();
    }

    if (answer == 10) return -1;
    return answer;
}

int main() {
	int n = 12;
	vector<int> weak = {1, 3, 4, 9, 10};
	vector<int> dist = {3, 5, 7};
	cout << solution(n, weak, dist) << endl;
	return 0;
}
