//
//  탑.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/05.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size(), 0);
	for (int i = heights.size()-1; i >= 0; --i) {
		if (answer[i]) continue;
		for (int j = i-1; j >= 0; --j)
			if (heights[j] > heights[i]) {
				answer[i] = j+1;
				break;
			}
	}
    return answer;
}

int main() {
	vector<int> heights = {1,5,3,6,7,6,5};
	for (auto a : solution(heights))
		cout << a << endl;
	return 0;
}
