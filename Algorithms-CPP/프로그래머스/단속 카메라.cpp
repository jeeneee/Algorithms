//
//  단속 카메라.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/08/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	sort(routes.begin(), routes.end());
	int tmp = routes[0][1];
	for (int i = 1; i < routes.size(); ++i) {
		if (routes[i][1] < tmp) tmp = routes[i][1];
		if (routes[i][0] > tmp) {
			answer++;
			tmp = routes[i][1];
		}
	}
    return answer;
}

int main() {
	vector<vector<int>> routes = {{-20,-15}, {-18,-13}, {-14,-5}, {-5,-3}};
	cout << solution(routes) << endl; // 2
	return 0;
}
