//
//  종이접기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/07.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 규칙성을 찾는 문제
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer = {0};
    for (int i = 1; i < n; ++i) {
		vector<int> temp = answer;
		temp[temp.size()/2] = 1;
		answer.push_back(0);
		answer.insert(answer.end(), temp.begin(), temp.end());
    }
    return answer;
}

int main() {
	int n;
	cin >> n;
	vector<int> answer = solution(n);
	for (auto &a : answer)
		cout << a << ' ';
	cout << endl;
	return 0;
}
