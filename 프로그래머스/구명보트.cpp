//
//  구명보트.cpp
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

int solution(vector<int> people, int limit) {
    int answer = 0;
	sort(people.begin(), people.end());
	int l = 0, r = people.size() - 1;
	while (l <= r) {
		if (people[r] + people[l] <= limit) l++;
		r--; answer++;
	}
    return answer;
}

int main() {
	vector<int> people = {70, 50, 80, 50};
	cout << solution(people, 100) << endl; // 3
	return 0;
}
