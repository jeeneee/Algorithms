//
//  [2020 카카오 인턴십] 키패드 누르기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/21.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dial[10][2] = {
	{3, 1}, {0, 0}, {0, 1}, {0, 2},
	{1, 0}, {1, 1}, {1, 2},
	{2, 0}, {2, 1}, {2, 2}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
	int lx = 3, ly = 0;
	int rx = 3, ry = 2;
	for (auto number: numbers) {
		int x = dial[number][0];
		int y = dial[number][1];
		if (number == 1 || number == 4 || number == 7) {
			answer += 'L';
			lx = x; ly = y;
		} else if (number == 3 || number == 6 || number == 9) {
			answer += 'R';
			rx = x; ry = y;
		} else {
			int ld = abs(lx - x) + abs(ly - y);
			int rd = abs(rx - x) + abs(ry - y);
			if (ld < rd || (ld == rd && hand == "left")) {
				answer += 'L';
				lx = x; ly = y;
			} else if (ld > rd || (ld == rd && hand == "right")) {
				answer += 'R';
				rx = x; ry = y;
			}
		}
	}
    return answer;
}

int main() {
	vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
	string hand = "right";
	cout << solution(numbers, hand) << endl;
	return 0;
}
