//
//  [2018 KAKAO BLIND RECRUITMENT] 파일명 정렬.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/15.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& _a, const string& _b) {
	string a = _a, b = _b;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	
	int i = 0, j = 0;
	string head_a = "", head_b = "";
	while (!isdigit(a[i])) head_a += a[i++];
	while (!isdigit(b[j])) head_b += b[j++];
	
	if (head_a != head_b) return head_a < head_b;
	
	string number_a = "", number_b = "";
	while (i < a.size() && isdigit(a[i])) number_a += a[i++];
	while (j < b.size() && isdigit(b[j])) number_b += b[j++];
	int num_a = stoi(number_a), num_b = stoi(number_b);
	if (num_a == num_b) return false;
	else return num_a < num_b;
}

vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(), compare);
    return files;
}

int main() {
	vector<string> files = {
		"F-5 Freedom Fighter", "B-50 Superfortress",
		"A-10 Thunderbolt II", "F-14 Tomcat"
	};
	for (auto a : solution(files))
		cout << a << ' ';
	cout << endl;
	return 0;
}
