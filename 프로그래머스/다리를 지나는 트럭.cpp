//
//  다리를 지나는 트럭.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/08/31.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, total_weight = 0, idx = 0;
	queue<int> w, d;
	while (true) {
		int trucks = w.size();
		for (int i = 0; i < trucks; ++i) {
			int distance = d.front();
			d.pop();
			if (distance <= 1) {
				total_weight -= w.front();
				w.pop();
				continue;
			}
			d.push(distance - 1);
		}
		if (idx < truck_weights.size() &&
			total_weight + truck_weights[idx] <= weight) {
			total_weight += truck_weights[idx];
			w.push(truck_weights[idx++]);
			d.push(bridge_length);
		}
		answer++;
		if (w.empty() && idx == truck_weights.size())
			break;
	}
    return answer;
}


int main() {
	vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};
	cout << solution(100, 100, truck_weights) << endl;
	return 0;
}
