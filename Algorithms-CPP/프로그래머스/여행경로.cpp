//
//  여행경로.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string from, int cnt, vector<vector<string>>& tickets,
		 vector<bool>& visited, vector<string>& temp, vector<string>& answer) {
	temp.push_back(from);
	if (cnt == tickets.size()) {
		answer = temp;
		return true;
	}
	for (int i = 0; i < tickets.size(); ++i) {
		if (tickets[i][0] == from && !visited[i]) {
			visited[i] = true;
			bool flag = dfs(tickets[i][1], cnt+1, tickets, visited, temp, answer);
			if (flag) return true;
			visited[i] = false;
		}
	}
	temp.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> temp, answer;
	vector<bool> visited(tickets.size(), false);
	sort(tickets.begin(), tickets.end());
	dfs("ICN", 0, tickets, visited, temp, answer);
    return answer;
}

int main() {
	vector<vector<string>> tickets = {
		{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}
	};
	for (auto a : solution(tickets))
		cout << a << endl;
	return 0;
}
