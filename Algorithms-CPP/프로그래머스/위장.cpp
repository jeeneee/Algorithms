//
//  위장.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/27.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> mp;
    for (auto& c : clothes) mp[c[1]]++;
    for (auto& a : mp)
        answer *= a.second + 1;
    return answer - 1;
}

int main() {
	vector<vector<string>> clothes = {
		{"yellow_hat", "headgear"},
		{"blue_sunglasses", "eyewear"},
		{"green_turban", "headgear"}
	};
	cout << solution(clothes) << endl;
	return 0;
}
