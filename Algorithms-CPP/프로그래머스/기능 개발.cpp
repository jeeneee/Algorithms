//
//  기능 개발.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/09.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int max_day = 0;
	for (int i = 0; i < progresses.size(); ++i) {
		int day = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
		if (day > max_day) answer.push_back(1);
		else ++answer.back();
		max_day = max(max_day, day);
	}
	return answer;
}

int main() {
	vector<int> progresses = {93, 30, 55};
	vector<int> speeds = {1, 30, 5};
	for (auto a : solution(progresses, speeds))
		cout << a << endl;
	return 0;
}
