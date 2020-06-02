//
//  가장 큰 수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/31.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	string sa = to_string(a);
	string sb = to_string(b);
	return sa + sb > sb + sa ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (auto a : numbers)
		answer += to_string(a);
	if (answer[0] == '0') return "0";
    return answer;
}

int main() {
	vector<int> numbers = {0};
	cout << solution(numbers) << endl;
	return 0;
}
