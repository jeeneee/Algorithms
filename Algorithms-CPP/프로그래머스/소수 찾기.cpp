//
//  소수 찾기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/26.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int answer;
set<int> s;

bool isPrime(int x) {
	if (x == 2) return true;
	if (x < 2 || x % 2 == 0) return false;
	
	for (int i = 3; i*i <= x; i += 2) {
		if (x % i == 0) return false;
	}
	return true;
}

void dfs(string num, vector<bool>& chk, string numbers) {
	if (num.size()) {
		int x = stoi(num);
		if (!s.count(x) && isPrime(x)) {
			s.insert(x);
			answer++;
		}
	}
	for (int i = 0; i < chk.size(); ++i) {
		if (!chk[i]) {
			chk[i] = true;
			dfs(num+numbers[i], chk, numbers);
			chk[i] = false;
		}
	}
}

int solution(string numbers) {
	s.clear();
	answer = 0;
	vector<bool> chk(numbers.size(), false);
	dfs("", chk, numbers);
	return answer;
}

int main() {
	string numbers = "17";
	cout << solution(numbers) << endl;
	return 0;
}

/* next_permutation */

#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isPrime(int x) {
    if (x == 2) return true;
    if (x < 2 || x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end());
    set<int> s;
    do {
        string str_num;
        for (int i = 0; i < numbers.size(); ++i) {
            str_num = numbers.substr(0, i+1);
            int num = stoi(str_num);
            if (!s.count(num) && isPrime(num))
                s.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    return s.size();
}
